%{
#include <stdio.h>
#include <stdlib.h>
%}

%token I B T A

%%

S  : I B T A { printf("Valid string\n"); }
   | A      { printf("Valid: S ? a\n"); }
   ;

%%

int main() {
    printf("Enter a string to parse: ");
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    exit(1);
}

int yylex() {
    int c = getchar();
    switch (c) {
        case 'i': return I;
        case 'b': return B;
        case 't': return T;
        case 'a': return A;
        default: return 0; // EOF or invalid character
    }
}
