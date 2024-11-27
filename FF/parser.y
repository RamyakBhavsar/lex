%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(const char *s);  // Error handling function
int yylex();                 // Declaration of lexical analyzer
%}

%token NUMBER  // Token definition for numbers
%left '+' '-'  // Define precedence and left associativity for '+' and '-'
%left '*' '/'  // Define precedence and left associativity for '*' and '/'

%%
expression:
    expression '+' expression { printf("Add: %d + %d\n", $1, $3); $$ = $1 + $3; }
    | expression '-' expression { printf("Subtract: %d - %d\n", $1, $3); $$ = $1 - $3; }
    | expression '*' expression { printf("Multiply: %d * %d\n", $1, $3); $$ = $1 * $3; }
    | expression '/' expression { printf("Divide: %d / %d\n", $1, $3); $$ = $1 / $3; }
    | '(' expression ')' { $$ = $2; }  // Handle parentheses
    | NUMBER              { $$ = $1; }
    ;

%%
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Enter expressions (Ctrl+D to exit):\n");
    yyparse();
    return 0;
}
