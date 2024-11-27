// AIM: Generating Intermediate Code for a New Language:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing three-address code information
typedef struct {
    char *operation;  // Operator (+, -, *, /, etc.)
    char *operand1;   // Left operand
    char *operand2;   // Right operand
    char *result;     // Result variable
} ThreeAddressCode;

// Function to generate and print intermediate code
void generate_code(const char *operation, const char *operand1, const char *operand2, const char *result) {
    printf("%s = %s %s %s\n", result, operand1, operation, operand2);
}

int main() {
    // Example variables for the source code: x = a + b; y = x - c;
    char *a = "a";
    char *b = "b";
    char *c = "c";
    char *x = "x";
    char *y = "y";

    // Generate intermediate code for x = a + b
    generate_code("+", a, b, x);

    // Generate intermediate code for y = x - c
    generate_code("-", x, c, y);

    return 0;
}
