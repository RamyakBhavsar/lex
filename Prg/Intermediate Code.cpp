#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	char *operation;
	char *operand1;
	char *operand2;
	char *result;
} ThreeAddressCode;
void generate_code(const char *operation, const char *operand1, const char *operand2, const
                   char *result) {
	printf("%s = %s %s %s\n", result, operand1, operation, operand2);
}
int main() {
// Example source code: x = a + b; y = x - c;
	char *a = "a";
	char *b = "b";
	char *c = "c";
	char *x = "x";
	char *y = "y";
	generate_code("+", a, b, x);
	generate_code("-", x, c, y);
	return 0;
}