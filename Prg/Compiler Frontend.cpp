#include <stdio.h>
#include <ctype.h>
#include <string.h>
typedef enum {
	TOKEN_NUMBER, TOKEN_IDENTIFIER, TOKEN_OPERATOR, TOKEN_IF,
	TOKEN_ELSE, TOKEN_WHILE, TOKEN_LPAREN, TOKEN_RPAREN,
	TOKEN_LBRACE, TOKEN_RBRACE, TOKEN_SEMICOLON, TOKEN_END,
	TOKEN_UNKNOWN
} TokenType;
typedef struct {
	TokenType type;
	char value[100];
} Token;
const char *source_code;
int current_pos = 0;
Token next_token() {
	Token token;
	int i = 0;
	while (source_code[current_pos] == ' ') current_pos++;
	if (source_code[current_pos] == '\0') {
		token.type = TOKEN_END;
		return token;
	}
	if (isdigit(source_code[current_pos])) {
		token.type = TOKEN_NUMBER;
		while (isdigit(source_code[current_pos])) {
			token.value[i++] = source_code[current_pos++];
		}
		token.value[i] = '\0';
		return token;
	}
	if (isalpha(source_code[current_pos])) {
		token.type = TOKEN_IDENTIFIER;
		while (isalnum(source_code[current_pos])) {
			token.value[i++] = source_code[current_pos++];
		}
		token.value[i] = '\0';
		if (strcmp(token.value, "if") == 0) token.type = TOKEN_IF;
		else if (strcmp(token.value, "else") == 0) token.type = TOKEN_ELSE;
		else if (strcmp(token.value, "while") == 0) token.type = TOKEN_WHILE;
		return token;
	}
	char ch = source_code[current_pos++];
	token.value[0] = ch;
	token.value[1] = '\0';
	switch (ch) {
		case '+':
		case '-':
		case '*':
		case '/':
			token.type = TOKEN_OPERATOR;
			break;
		case '(':
			token.type = TOKEN_LPAREN;
			break;
		case ')':
			token.type = TOKEN_RPAREN;
			break;
		case '{':
			token.type = TOKEN_LBRACE;
			break;
		case '}':
			token.type = TOKEN_RBRACE;
			break;
		case ';':
			token.type = TOKEN_SEMICOLON;
			break;
		default:
			token.type = TOKEN_UNKNOWN;
			break;
	}
	return token;
}
void parse() {
	Token token = next_token();
	if (token.type == TOKEN_IF) {
		printf("Parsed IF Statement\n");
		token = next_token();
		if (token.type == TOKEN_LPAREN) {
			printf("Condition Start\n");
			token = next_token();
			printf("Condition: %s\n", token.value);
			token = next_token();
			if (token.type == TOKEN_RPAREN) {
				printf("Condition End\n");
				token = next_token();
				if (token.type == TOKEN_LBRACE) {
					printf("Body Start\n");
					token = next_token();
					printf("Body Expression: %s\n", token.value);
					token = next_token();
					if (token.type == TOKEN_RBRACE) {
						printf("Body End\n");
					}
				}
			}
		}
	}
}
int main() {
	source_code = "if (x + 5) { y = 10; }";
	printf("Parsing source code: %s\n", source_code);
	parse();
	return 0;
}