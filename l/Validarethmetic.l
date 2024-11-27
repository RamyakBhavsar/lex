%{
#include <stdio.h>
#include <string.h>

int flag = 0, i = 0, j, k = 0;
char operand[20][20], oparator[20][20];
%}

%%

[a-zA-Z0-9]+ { 
    flag++; 
    strcpy(operand[i], yytext); 
    i++; 
}

[-+*/] { 
    flag--; 
    strcpy(oparator[k], yytext); 
    k++; 
}

\n { 
    // To handle end of input (newline) 
    return 0; 
}

%%

int main(int argc, char *argv[]) {
    printf("Enter an arithmetic expression:\n");
    fflush(stdout); // Ensures the prompt is displayed immediately

    yylex(); // Run lexical analysis
    
    // Check the validity of the expression
    if (flag != 1) {
        printf("Invalid expression\n");
    } else {
        printf("Valid expression\n");

        printf("The operands are:\t");
        for (j = 0; j < i; j++) {
            printf("%s\t", operand[j]);
        }

        printf("\nThe operators are:\t");
        for (j = 0; j < k; j++) {
            printf("%s\t", oparator[j]);
        }

        printf("\n");
    }

    return 0;
}

int yywrap() {
    return 1; // Required to end lexical analysis
}
