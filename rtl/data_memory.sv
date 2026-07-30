// Byte-addressable data memory with sub-word access support.
//
// Backing store is word-wide; byte enables select which lanes a store
// updates. Loads return the full containing word and the MEM stage extracts
// and extends the requested field.

`include "defines.svh"

module data_memory #(
    parameter int DEPTH_WORDS = DMEM_WORDS
)
(
    input  logic        clk,

    input  logic        mem_we,
    input  logic        mem_re,

    input  logic [31:0] addr,
    input  logic [31:0] write_data,
    input  logic [1:0]  mem_size,   // MEM_SZ_BYTE / HALF / WORD

    output logic [31:0] read_data,  // raw containing word

    // Access faults, reported to the MEM stage
    output logic        misaligned,
    output logic        out_of_range
);

localparam int ADDR_MSB = $clog2(DEPTH_WORDS) + 1; // top bit of the word index

logic [31:0] mem [0:DEPTH_WORDS-1];

// Word index and byte offset within the word
logic [ADDR_MSB-2:0] word_index;
logic [1:0]          byte_offset;

assign word_index  = addr[ADDR_MSB:2];
assign byte_offset = addr[1:0];

////////////////////////////////
// Access checking
//
// Alignment is required by the RISC-V spec for the access width. Range is
// checked so a stray address reports a fault instead of silently aliasing
// back into the array.

always_comb begin
    case (mem_size)
        MEM_SZ_HALF: misaligned = (byte_offset[0] != 1'b0);
        MEM_SZ_WORD: misaligned = (byte_offset    != 2'b00);
        default:     misaligned = 1'b0; // byte accesses are always aligned
    endcase
end

assign out_of_range = (mem_re || mem_we) &&
                      (addr >= (DEPTH_WORDS * 4));

// A faulting access must not change or observe memory state
logic access_ok;
assign access_ok = !misaligned && !out_of_range;

////////////////////////////////
// Byte enables

logic [3:0] byte_en;

always_comb begin
    byte_en = 4'b0000;

    if (mem_we && access_ok) begin
        case (mem_size)
            MEM_SZ_BYTE: byte_en = 4'b0001 << byte_offset;
            MEM_SZ_HALF: byte_en = 4'b0011 << byte_offset;
            MEM_SZ_WORD: byte_en = 4'b1111;
            default:     byte_en = 4'b0000;
        endcase
    end
end

////////////////////////////////
// Store data lane replication
//
// The byte or halfword is replicated across the word so that whichever lane
// the byte enables select already carries the correct value.

logic [31:0] store_word;

always_comb begin
    case (mem_size)
        MEM_SZ_BYTE: store_word = {4{write_data[7:0]}};
        MEM_SZ_HALF: store_word = {2{write_data[15:0]}};
        default:     store_word = write_data;
    endcase
end

////////////////////////////////
// Initialisation

initial begin
    for (int i = 0; i < DEPTH_WORDS; i++) begin
        mem[i] = 32'd0;
    end
end

////////////////////////////////
// Write port

always_ff @(posedge clk) begin
    if (byte_en[0]) mem[word_index][7:0]   <= store_word[7:0];
    if (byte_en[1]) mem[word_index][15:8]  <= store_word[15:8];
    if (byte_en[2]) mem[word_index][23:16] <= store_word[23:16];
    if (byte_en[3]) mem[word_index][31:24] <= store_word[31:24];
end

////////////////////////////////
// Read port

always_comb begin
    if (mem_re && access_ok)
        read_data = mem[word_index];
    else
        read_data = 32'd0;
end

endmodule
