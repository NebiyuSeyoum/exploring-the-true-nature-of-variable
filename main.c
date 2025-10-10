#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>


// Bit shift amounts
#define SHIFT_0_BIN 0b00000000000000000000000000000000  // 0 bits (binary notation)
#define SHIFT_0_OCT 00000000000                         // 0 bits (octal notation)
#define SHIFT_0_DEC 0                                   // 0 bits (decimal notation)
#define SHIFT_0_HEX 0x00000000                          // 0 bits (hexadecimal notation)

#define SHIFT_8_BIN 0b00000000000000000000000000001000  // 8 bits (binary notation)
#define SHIFT_8_OCT 00000000010                         // 8 bits (octal notation)
#define SHIFT_8_DEC 8                                   // 8 bits (decimal notation)
#define SHIFT_8_HEX 0x00000008                          // 8 bits (hexadecimal notation)

#define SHIFT_16_BIN 0b00000000000000000000000000010000 // 16 bits (binary notation)
#define SHIFT_16_OCT 00000000020                        // 16 bits (octal notation)
#define SHIFT_16_DEC 16                                 // 16 bits (decimal notation)
#define SHIFT_16_HEX 0x00000010                         // 16 bits (hexadecimal notation)

// Byte masks
#define MASK_255_BIN 0b00000000000000000000000011111111 // 8-bit mask (binary notation)
#define MASK_255_OCT 00000000377                        // 8-bit mask (octal notation)
#define MASK_255_DEC 255                                // 8-bit mask (decimal notation)
#define MASK_255_HEX 0x000000FF                         // 8-bit mask (hexadecimal notation)

/**
 * Display usage information and available command-line options
 * @param program_name: Name of the executable program
 */
void print_usage(const char* program_name) {
    printf("═══════════════════════════════════════════════════════════════\n");
    printf("    EXPLORING THE TRUE NATURE OF VARIABLES\n");
    printf("    An Educational Experiment on Type Independence\n");
    printf("═══════════════════════════════════════════════════════════════\n\n");
    printf("Usage: %s [notation]\n\n", program_name);
    printf("Available notations (all represent identical data):\n");
    printf("  bin (default) - Binary notation     (0b...)\n");
    printf("  oct           - Octal notation      (0...)\n");
    printf("  dec           - Decimal notation    (...)\n");
    printf("  hex           - Hexadecimal notation (0x...)\n\n");
    printf("Examples:\n");
    printf("  %s bin    # Same data, binary notation\n", program_name);
    printf("  %s oct    # Same data, octal notation\n", program_name);
    printf("  %s dec    # Same data, decimal notation\n", program_name);
    printf("  %s hex    # Same data, hexadecimal notation\n", program_name);
    printf("  %s help   # Show this help message\n\n", program_name);
    printf("EDUCATIONAL DISCOVERY:\n");
    printf("This experiment reveals that data types (int, float, char, etc.)\n");
    printf("are human abstractions. All data is fundamentally identical -\n");
    printf("just bit patterns that can be interpreted in multiple ways.\n");
    printf("Variables are type-independent; types exist only to reduce\n");
    printf("cognitive load for programmers, not computational necessity.\n");
    printf("═══════════════════════════════════════════════════════════════\n");
}

/**
 * Main function - Demonstrates the fundamental unity of all data types
 * @param argc: Number of command-line arguments
 * @param argv: Array of command-line argument strings
 * @return: 0 on success, 1 on error
 */
int main(int argc, char* argv[]) {
    // Default to binary notation for demonstration
    int use_bin = 1, use_oct = 0, use_dec = 0, use_hex = 0;

    // Parse and validate command line arguments
    if (argc > 1) {
        if (strcmp(argv[1], "help") == 0 || strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
            print_usage(argv[0]);
            return 0;
        } else if (strcmp(argv[1], "bin") == 0) {
            use_bin = 1; use_oct = 0; use_dec = 0; use_hex = 0;
        } else if (strcmp(argv[1], "oct") == 0) {
            use_bin = 0; use_oct = 1; use_dec = 0; use_hex = 0;
        } else if (strcmp(argv[1], "dec") == 0) {
            use_bin = 0; use_oct = 0; use_dec = 1; use_hex = 0;
        } else if (strcmp(argv[1], "hex") == 0) {
            use_bin = 0; use_oct = 0; use_dec = 0; use_hex = 1;
        } else {
            printf("ERROR: Invalid notation '%s'\n\n", argv[1]);
            print_usage(argv[0]);
            return 1;
        }
    }

    // Traditional variable declarations - each appears to be "different"
    int myInt = 42;                    // "Integer" type
    float myFloat = 2.7f;              // "Floating-point" type
    char myChar = 'A';                 // "Character" type
    char myString[] = "ABC";           // "String" type
    _Bool myBool = 1;                  // "Boolean" type

    // Display what appears to be different types
    printf("Programming languages present these as 'different' types:\n");
    printf("  int:     %d      ← Appears to be a 'number'\n", myInt);
    printf("  float:   %.2f    ← Appears to be a 'decimal number'\n", myFloat);
    printf("  char:    %c      ← Appears to be a 'character'\n", myChar);
    printf("  string:  %s     ← Appears to be 'text'\n", myString);
    printf("  _Bool:   %d      ← Appears to be 'true/false'\n\n", myBool);

    printf("Using ANY generic type (here: uint32_t) as universal data container with %s notation:\n",
        use_bin ? "BINARY" : use_oct ? "OCTAL" : use_dec ? "DECIMAL" : "HEXADECIMAL");
    printf("Showing that ONE arbitrary type can represent ALL data forms!\n");
    printf("(Could be uint8_t, uint64_t, void*, or any other - choice is not essential!)\n\n");

    uint32_t genericContainer;  // ONE variable for ALL data concepts!

    // ┌─────────────────────────────────────────────────────────────────┐
    // │ REINTERPRETATION 1: INTEGER CONCEPT                             │
    // └─────────────────────────────────────────────────────────────────┘

    if (use_bin) {
        genericContainer = 0b00000000000000000000000000101010; // Bit pattern representing "42"
    } else if (use_oct) {
        genericContainer = 00000000052; // Same pattern, octal notation
    } else if (use_dec) {
        genericContainer = 42; // Same pattern, decimal notation
    } else if (use_hex) {
        genericContainer = 0x0000002A; // Same pattern, hex notation
    }
    printf("→ 'Integer' concept:  %d     ← Container interpreted as integer\n", genericContainer);

    // ┌─────────────────────────────────────────────────────────────────┐
    // │ REINTERPRETATION 2: FLOATING-POINT CONCEPT                      │
    // └─────────────────────────────────────────────────────────────────┘

    if (use_bin) {
        genericContainer = 0b01000000001011001100110011001101; // IEEE 754 pattern for 2.7
    } else if (use_oct) {
        genericContainer = 010013146315; // Same pattern, octal notation
    } else if (use_dec) {
        genericContainer = 1076677837; // Same pattern, decimal notation
    } else if (use_hex) {
        genericContainer = 0x402CCCCD; // Same pattern, hex notation
    }
    printf("→ 'Float' concept:    %.2f   ← Same container, interpreted as float\n", *(float*)&genericContainer);

    // ┌─────────────────────────────────────────────────────────────────┐
    // │ REINTERPRETATION 3: CHARACTER CONCEPT                           │
    // └─────────────────────────────────────────────────────────────────┘

    if (use_bin) {
        genericContainer = 0b00000000000000000000000001000001; // ASCII 'A' pattern
    } else if (use_oct) {
        genericContainer = 00000000101; // Same value, octal notation
    } else if (use_dec) {
        genericContainer = 65; // Same value, decimal notation
    } else if (use_hex) {
        genericContainer = 0x00000041; // Same value, hex notation
    }
    printf("→ 'Character' concept: %c     ← Same container, interpreted as character\n", genericContainer);

    // ┌─────────────────────────────────────────────────────────────────┐
    // │ REINTERPRETATION 4: STRING CONCEPT                              │
    // └─────────────────────────────────────────────────────────────────┘

    if (use_bin) {
        genericContainer = 0b00000000010000110100001001000001; // "ABC" packed into bits
    } else if (use_oct) {
        genericContainer = 000020641101; // Same data, octal notation
    } else if (use_dec) {
        genericContainer = 4407873; // Same data, decimal notation
    } else if (use_hex) {
        genericContainer = 0x00434241; // Same data, hex notation
    }
    // Extract characters from the same container using bit manipulation
    printf("→ 'String' concept:   %c%c%c   ← Same container, extracted as text\n",
        (genericContainer >> (use_bin ? SHIFT_0_BIN : use_oct ? SHIFT_0_OCT : use_dec ? SHIFT_0_DEC : SHIFT_0_HEX)) & (use_bin ? MASK_255_BIN : use_oct ? MASK_255_OCT : use_dec ? MASK_255_DEC : MASK_255_HEX),
        (genericContainer >> (use_bin ? SHIFT_8_BIN : use_oct ? SHIFT_8_OCT : use_dec ? SHIFT_8_DEC : SHIFT_8_HEX)) & (use_bin ? MASK_255_BIN : use_oct ? MASK_255_OCT : use_dec ? MASK_255_DEC : MASK_255_HEX),
        (genericContainer >> (use_bin ? SHIFT_16_BIN : use_oct ? SHIFT_16_OCT : use_dec ? SHIFT_16_DEC : SHIFT_16_HEX)) & (use_bin ? MASK_255_BIN : use_oct ? MASK_255_OCT : use_dec ? MASK_255_DEC : MASK_255_HEX));
    printf("                      %s     ← Same container, direct interpretation\n", (char*)&genericContainer);

    // ┌─────────────────────────────────────────────────────────────────┐
    // │ REINTERPRETATION 5: BOOLEAN CONCEPT                             │
    // └─────────────────────────────────────────────────────────────────┘

    if (use_bin) {
        genericContainer = 0b00000000000000000000000000000001; // "True" concept
    } else if (use_oct) {
        genericContainer = 00000000001; // Same concept, octal notation
    } else if (use_dec) {
        genericContainer = 1; // Same concept, decimal notation
    } else if (use_hex) {
        genericContainer = 0x00000001; // Same concept, hex notation
    }
    printf("→ 'Boolean' concept:  %d     ← Same container, interpreted as truth value\n", genericContainer);

    return 0;
}
