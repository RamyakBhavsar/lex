#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VARIABLES 100
#define MAX_SCOPES 100
typedef struct {
	char name[50];
	int is_declared;
} Variable;
typedef struct {
	Variable variables[MAX_VARIABLES];
	int count;
} SymbolTable;
typedef struct {
	SymbolTable table;
} Scope;
Scope *scope_stack[MAX_SCOPES];
int current_scope = -1;
void enter_scope() {
	current_scope++;
	scope_stack[current_scope] = (Scope *)malloc(sizeof(Scope));
	scope_stack[current_scope]->table.count = 0;
}
void exit_scope() {
	free(scope_stack[current_scope]);
	current_scope--;
}
void declare_variable(const char *name) {
	Scope *scope = scope_stack[current_scope];
	for (int i = 0; i < scope->table.count; i++) {
		if (strcmp(scope->table.variables[i].name, name) == 0) {
			printf("Error: Variable '%s' already declared in this scope.\n", name);
			return;
		}
	}
	strcpy(scope->table.variables[scope->table.count++].name, name);
	printf("Declared variable: %s\n", name);
}
int is_variable_declared(const char *name) {
	for (int i = current_scope; i >= 0; i--) {
		Scope *scope = scope_stack[i];
		for (int j = 0; j < scope->table.count; j++) {
			if (strcmp(scope->table.variables[j].name, name) == 0) {
				return 1;
			}
		}
	}
	return 0;
}
int main() {
	enter_scope();
	declare_variable("x");
	enter_scope();
	declare_variable("y");
	declare_variable("x");
	if (is_variable_declared("x")) {
		printf("Variable 'x' is accessible in this scope.\n");
	}
	if (!is_variable_declared("z")) {
		printf("Variable 'z' is not declared.\n");
	}
	exit_scope();
	exit_scope();
	return 0;
}