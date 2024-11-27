%{
#include "4_parser.tab.h"
#include <stdio.h>
%}

%option noyywrap

%%

int         { return INT; }
float       { return FLOAT; }
[a-zA-Z_][a-zA-Z0-9_]*  { return ID; }
"="         { return ASSIGN; }
";"         { return SEMICOLON; }
"{"         { return LBRACE; }
"}"         { return RBRACE; }
"("         { return LPAREN; }
")"         { return RPAREN; }
[ \t\n]     { /* Ignore whitespace */ }

%%

