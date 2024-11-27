// AIM: Token Recognition for a New Programming Language:

#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef enum {
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_IDENTIFIER,
    TOKEN_UNKNOWN
} TokenType;

typedef struct {
    TokenType type;
    char value[100];
} Token;

// Function to tokenize input string
Token tokenize(char *code, int *pos) {
    Token token;
    int i = *pos;  // Start from the current position
    token.value[0] = '\0';  // Clear the value initially

    // Skip white spaces
    while (code[i] == ' ' || code[i] == '\t' || code[i] == '\n') {
        i++;
    }

    // If we've reached the end of the string
    if (code[i] == '\0') {
        token.type = TOKEN_UNKNOWN;
        token.value[0] = '\0';
        *pos = i;
        return token;
    }

    // Check if it's a number
    if (isdigit(code[i])) {
        token.type = TOKEN_NUMBER;
        int j = 0;
        while (isdigit(code[i])) {
            token.value[j++] = code[i++];
        }
        token.value[j] = '\0';
    }
    // Check if it's an operator
    else if (strchr("+-*/=", code[i])) {
        token.type = TOKEN_OPERATOR;
        token.value[0] = code[i++];
        token.value[1] = '\0';
    }
    // Check if it's an identifier (variable name)
    else if (isalpha(code[i]) || code[i] == '_') {
        token.type = TOKEN_IDENTIFIER;
        int j = 0;
        while (isalnum(code[i]) || code[i] == '_') {
            token.value[j++] = code[i++];
        }
        token.value[j] = '\0';
    }
    // For unknown tokens (like invalid characters)
    else {
        token.type = TOKEN_UNKNOWN;
        token.value[0] = code[i++];
        token.value[1] = '\0';
    }

    // Update the position for the next iteration
    *pos = i;
    return token;
}

int main() {
    char code[] = "x = 12 + 34 * 56";
    int pos = 0;

    printf("Tokenized output:\n");

    while (code[pos] != '\0') {
        Token token = tokenize(code, &pos);

        // If the token type is unknown, print error and exit
        if (token.type == TOKEN_UNKNOWN) {
            printf("Error: Unknown token '%s'\n", token.value);
            break;
        }

        // Print the token type and value
        switch (token.type) {
            case TOKEN_NUMBER:
                printf("NUMBER: %s\n", token.value);
                break;
            case TOKEN_OPERATOR:
                printf("OPERATOR: %s\n", token.value);
                break;
            case TOKEN_IDENTIFIER:
                printf("IDENTIFIER: %s\n", token.value);
                break;
            default:
                printf("Unknown token type\n");
                break;
        }
    }

    return 0;
}
