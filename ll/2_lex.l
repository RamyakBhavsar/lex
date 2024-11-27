%{
#include <stdio.h>
%}

DIGIT       [0-9]+
IDENTIFIER  [a-zA-Z_][a-zA-Z0-9_]*
OPERATOR    [+\-*/]

%%
{DIGIT}             { printf("NUMBER: %s\n", yytext); }
{OPERATOR}          { printf("OPERATOR: %s\n", yytext); }
{IDENTIFIER}         { printf("IDENTIFIER: %s\n", yytext); }
"="                 { printf("ASSIGNMENT OPERATOR: %s\n", yytext); }
[ \t\n]+            ;  // Ignore whitespace
.                   { printf("UNKNOWN TOKEN: %s\n", yytext); }
%%

int main() {
    printf("Enter the source code (Ctrl+D to end input):\n");
    yylex(); // Start tokenizing
    return 0;
}

int yywrap() {
    return 1;  // Indicate end of input
}
