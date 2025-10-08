#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

int main(int argc, char* argv[]) {
    printf("═══ Variables With Type Abstractions ═══\n");
    int myInt = 42;
    float myFloat = 2.7f;
    char myChar = 'A';
    char myString[] = "ABC";
    _Bool myBool = 1;

    printf("int: %d\n", myInt); // int: 42
    printf("float: %.2f\n", myFloat); // float: 2.70
    printf("char: %c\n", myChar); // char: A
    printf("string: %s\n", myString); // string: ABC
    printf("_Bool: %d\n", myBool); // _Bool: 1

    printf("\n═══ Variables With Generic Type Abstractions ═══\n");
    uint32_t generic_myInt = 0b00000000000000000000000000101010; // 42 in binary
    uint32_t generic_myFloat = 0b01000000001011001100110011001101; // 2.7f in binary
    uint32_t generic_myChar = 0b00000000000000000000000001000001; // 'A' in binary
    uint32_t generic_myString = 0b00000000010000110100001001000001; // "ABC" in binary
    uint32_t generic_myBool = 0b00000000000000000000000000000001; // true in binary

    printf("generic int: %d\n", generic_myInt); // generic int: 42
    printf("generic float: %.2f\n", *(float*)&generic_myFloat); // generic float: 2.70
    printf("generic char: %c\n", generic_myChar); // generic char: A
    printf("generic string (m1): %c%c%c\n",
        (generic_myString >> 0b00000000000000000000000000000000) & 0b00000000000000000000000011111111,
        (generic_myString >> 0b00000000000000000000000000001000) & 0b00000000000000000000000011111111,
        (generic_myString >> 0b00000000000000000000000000010000) & 0b00000000000000000000000011111111); // generic string (m1): ABC
    printf("generic string (m2): %s\n", (char*)&generic_myString); // generic string (m2): ABC
    printf("generic _Bool: %d\n", generic_myBool); // generic _Bool: 1

    return 0;
}
