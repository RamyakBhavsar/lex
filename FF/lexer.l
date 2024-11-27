%{
#include "parser.tab.h"
%}

%%
[0-9]+      { yylval = atoi(yytext); return NUMBER; }
[+\-*/()]   { return yytext[0]; }
[ \t\n]     { /* Skip whitespace */ }
.           { printf("Unknown character: %s\n", yytext); }
%%
int yywrap() {
    return 1;
}
