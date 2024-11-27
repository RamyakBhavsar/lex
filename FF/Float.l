digit [0-9]
num {digit}+
snum [-+]?{num}
%{
%}
%%
({snum}[.]{num})|([.]{num})|({snum}[.])|([+-][.]{num}) {printf ("\n==>%s is a floating-point number \n", yytext);}
({snum}) {printf ("\n==>%s is not a floating-point number \n",yytext);}
%%
int main ()
{
 printf ("Enter any number \n" );
 yylex();
 return 0;
}

int yywrap()
{
    return 1;
}