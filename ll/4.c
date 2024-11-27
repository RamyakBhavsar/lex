// AIM: Managing Variable Scopes and Declarations:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

// Define types of symbols (variables)
typedef enum { VAR } SymbolType;

// Define a structure for a symbol (variable)
typedef struct Symbol {
    char name[MAX_NAME_LENGTH];
    SymbolType type;
    char data_type[MAX_NAME_LENGTH];  // Type of variable (int, float, etc.)
    struct Symbol *next; // For linked list of symbols in a single scope
} Symbol;

// Symbol table (linked list for simplicity, stack-based approach for nested scopes)
typedef struct SymbolTable {
    Symbol *head;  // Linked list to store symbols in the current scope
    struct SymbolTable *next;  // Pointer to the next scope (previous scope)
} SymbolTable;

// Stack of symbol tables for managing nested scopes
SymbolTable *scope_stack = NULL;

// Create a new symbol (variable)
Symbol* create_symbol(char* name, char* data_type) {
    Symbol* symbol = (Symbol*)malloc(sizeof(Symbol));
    strncpy(symbol->name, name, MAX_NAME_LENGTH);
    symbol->type = VAR;
    strncpy(symbol->data_type, data_type, MAX_NAME_LENGTH);
    symbol->next = NULL;
    return symbol;
}

// Push a new symbol table to the scope stack
void push_scope() {
    SymbolTable *new_scope = (SymbolTable*)malloc(sizeof(SymbolTable));
    new_scope->head = NULL;
    new_scope->next = scope_stack;
    scope_stack = new_scope;
}

// Pop the top symbol table from the scope stack
void pop_scope() {
    if (scope_stack != NULL) {
        SymbolTable *old_scope = scope_stack;
        scope_stack = scope_stack->next;
        free(old_scope);
    }
}

// Add a symbol (variable) to the current scope
void add_symbol(char* name, char* data_type) {
    if (scope_stack == NULL) {
        printf("Error: No scope to add symbol\n");
        return;
    }

    // Check if symbol already exists in the current scope
    SymbolTable *current_scope = scope_stack;
    Symbol *current_symbol = current_scope->head;
    while (current_symbol != NULL) {
        if (strcmp(current_symbol->name, name) == 0) {
            printf("Error: Variable '%s' already declared in this scope.\n", name);
            return;
        }
        current_symbol = current_symbol->next;
    }

    // Add symbol to the symbol table (current scope)
    Symbol* new_symbol = create_symbol(name, data_type);
    new_symbol->next = current_scope->head;
    current_scope->head = new_symbol;

    printf("Declared variable: %s\n", name);
}

// Lookup a symbol (variable) in the current scope and all enclosing scopes
Symbol* lookup_symbol(char* name) {
    SymbolTable *current_scope = scope_stack;
    while (current_scope != NULL) {
        Symbol *current_symbol = current_scope->head;
        while (current_symbol != NULL) {
            if (strcmp(current_symbol->name, name) == 0) {
                return current_symbol;
            }
            current_symbol = current_symbol->next;
        }
        current_scope = current_scope->next;
    }
    return NULL;  // Symbol not found
}

// Example of parsing and managing scopes
void parse_program() {
    push_scope();  // Global scope

    // Declare variables
    add_symbol("x", "int");
    add_symbol("y", "float");

    // Try to redeclare a variable in the same scope
    add_symbol("x", "int");

    push_scope();  // New scope (function, or nested block)
    add_symbol("a", "int");
    add_symbol("b", "float");

    // Look up variables
    Symbol *symbol = lookup_symbol("x");
    if (symbol != NULL) {
        printf("Variable '%s' is accessible in this scope.\n", symbol->name);
    } else {
        printf("Variable 'x' is not declared.\n");
    }

    symbol = lookup_symbol("z");
    if (symbol != NULL) {
        printf("Variable '%s' is accessible in this scope.\n", symbol->name);
    } else {
        printf("Variable 'z' is not declared.\n");
    }

    pop_scope();  // Exit nested scope
    pop_scope();  // Exit global scope
}

int main() {
    parse_program();
    return 0;
}
