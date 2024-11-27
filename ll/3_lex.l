%{
#include "3_parser.tab.h"
%}

%%

"while"       { return WHILE; }
"if"          { return IF; }
"else"        { return ELSE; }
[0-9]+        { yylval = atoi(yytext); return NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]* { return IDENTIFIER; }
"<"|"<="|">"|">="|"=="|"!=" { return RELOP; }
"="           { return ASSIGNOP; }
"+"|"-"       { return ADDOP; }
"*"|"/"       { return MULOP; }
"("           { return LPAREN; }
")"           { return RPAREN; }
"{"           { return LBRACE; }
"}"           { return RBRACE; }
";"           { return SEMICOLON; }
[ \t\n]+      { /* Ignore whitespace */ }
.             { printf("Unknown token: %s\n", yytext); return 0; }

%%

int yywrap() {
    return 1;  // Return 1 to indicate end of input
}
