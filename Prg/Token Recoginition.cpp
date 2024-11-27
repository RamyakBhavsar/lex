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
Token tokenize(char *code) { 
Token token; 
int i = 0; 
// Skip white spaces 
while (code[i] == ' ') i++; 
// Check if it's a number 
if (isdigit(code[i])) { 
token.type = TOKEN_NUMBER; 
int j = 0; 
while (isdigit(code[i])) { 
token.value[j++] = code[i++]; 
}
  token.value[j] = '\0'; 
    } 
    else if (strchr("+-*/", code[i])) { 
        token.type = TOKEN_OPERATOR; 
        token.value[0] = code[i++]; 
        token.value[1] = '\0';   
    } 
    else if (isalpha(code[i])) { 
        token.type = TOKEN_IDENTIFIER; 
        int j = 0; 
        while (isalnum(code[i]) || code[i] == '_') { 
            token.value[j++] = code[i++]; 
        } 
        token.value[j] = '\0';   
    } 
    else { 
        token.type = TOKEN_UNKNOWN; 
        token.value[0] = code[i++]; 
        token.value[1] = '\0';   
    } 
    return token; 
} 
int main () { 
    char code [] = "x = 12 + 34 * 56"; 
    int pos = 0; 
    printf ("Tokenized output:\n"); 
    while (code[pos] != '\0') { 
        Token token = tokenize(&code[pos]); 
        if (token.type == TOKEN_UNKNOWN) { 
            printf("Error: Unknown token '%s'\n", token.value); 
            break; 
        } 
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
pos += strlen(token.value); 
} 
return 0; 
}