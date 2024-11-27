%{
#include <stdio.h>
%}

%% 
"<"[^>]+">" {printf("Tag: %s\n", yytext); }
. ; 
%%	 

int yywrap() {
    return 1;
}

int main(int argc, char* argv[]) 
{ 
    FILE *yyin; 
    yyin = fopen("tags.txt", "r"); 

    if (!yyin) {
        perror("Error opening file");
        return 1;
    }

    extern FILE *yyin; 

    yylex(); 

    fclose(yyin); 
    return 0; 
}
