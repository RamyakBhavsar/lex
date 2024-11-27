%{ 
%} 

%% 
"<"[^>]> {printf("%s\n", yytext); }
. ; 
%%	 


	
int main(int argc, char*argv[]) 
{ 
	
	extern FILE *yyin = fopen("tags.txt","r"); 

	yylex(); 

	return 0; 
}

int yywrap(){
    return 1;
} 