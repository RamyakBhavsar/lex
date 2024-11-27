%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAR_NAME 100

typedef struct Symbol {
    char name[MAX_VAR_NAME];
    struct Symbol* next;
} Symbol;

Symbol* symbolTable = NULL;

void insert_symbol(char* name);
int lookup_symbol(char* name);
void check_redeclaration(char* name);

void yyerror(const char *s);  // Declare yyerror function

%}

%union {
    int ival;
    char* sval;
}

%token <sval> ID
%token INT FLOAT ASSIGN SEMICOLON LBRACE RBRACE LPAREN RPAREN

%type <sval> type

%%

program:
    declarations
    ;

declarations:
    declarations declaration
    | /* Empty */
    ;

declaration:
    type ID SEMICOLON {
        check_redeclaration($2);  // Pass the name as a string
        insert_symbol($2);        // Pass the name as a string
        printf("Declared variable: %s\n", $2);
    }
    ;

type:
    INT { $$ = "int"; }
    | FLOAT { $$ = "float"; }
    ;

%%

void insert_symbol(char* name) {
    Symbol* new_symbol = (Symbol*)malloc(sizeof(Symbol));
    strcpy(new_symbol->name, name);
    new_symbol->next = symbolTable;
    symbolTable = new_symbol;
}

int lookup_symbol(char* name) {
    Symbol* current = symbolTable;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return 1;  // Found symbol
        }
        current = current->next;
    }
    return 0;  // Symbol not found
}

void check_redeclaration(char* name) {
    if (lookup_symbol(name)) {
        printf("Error: Variable '%s' already declared in this scope.\n", name);
        exit(1);  // Exit if redeclared
    }
}

int main() {
    printf("Enter the program:\n");
    yyparse();  // Start the parsing process
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
