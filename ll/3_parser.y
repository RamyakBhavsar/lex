%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex(void);  // Declare the lexer function
%}

%token NUMBER IDENTIFIER
%token WHILE IF ELSE
%token RELOP ASSIGNOP ADDOP MULOP
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON

%%
program:
    statements
    ;

statements:
    statement
    | statements statement
    ;

statement:
    WHILE LPAREN condition RPAREN LBRACE statements RBRACE
    | IF LPAREN condition RPAREN LBRACE statements RBRACE
    | IF LPAREN condition RPAREN LBRACE statements RBRACE ELSE LBRACE statements RBRACE
    | IDENTIFIER ASSIGNOP expression SEMICOLON
    ;

condition:
    expression RELOP expression
    ;

expression:
    term
    | expression ADDOP term
    ;

term:
    factor
    | term MULOP factor
    ;

factor:
    NUMBER
    | IDENTIFIER
    | LPAREN expression RPAREN
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Enter expressions (Ctrl+D to exit):\n");

    // Process input until EOF (Ctrl+D)
    while (1) {
        int parse_result = yyparse();
        if (parse_result != 0) {
            // Break if the parsing is unsuccessful or we reach EOF
            break;
        }
    }
    return 0;
}
