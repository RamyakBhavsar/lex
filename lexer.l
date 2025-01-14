%{
#include <stdio.h>
%}

%% 
"<"[^>]+">" {printf("Tag: %s\n", yytext); }
. ; 
%%	 

int main(int argc, char* argv[]) 
{ 
    if (argc > 1) {
        yyin = fopen(argv[1], "r"); 
        if (!yyin) {
            perror("Error opening file");
            return 1;
        }
    } else {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    yylex(); 

    fclose(yyin); 
    return 0; 
}
int yywrap() {
    return 1;
}