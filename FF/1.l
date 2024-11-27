%{
#include<stdio.h>
%}

%%
if|else               {printf("%s is a keyword\n", yytext);}
printf                {printf("%s is a keyword\n", yytext);}
[0-9]+                {printf("%s is a number\n", yytext);}
[a-zA-Z]+             {printf("%s is a word\n", yytext);}
.|\n                  {ECHO;}
%%

int main()
{
    printf("\nEnter the string: ");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}