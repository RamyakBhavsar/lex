#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100


char grammar[MAX][MAX], terminals[MAX], nonTerminals[MAX];
char first[MAX][MAX], follow[MAX][MAX];
int productionCount;

void findFirst(char, int, int);
void findFollow(char);
void computeFirstSets();
void computeFollowSets();
int isLL1();

int main() {
    int i;
    char ch;

    printf("Enter the number of productions: ");
    scanf("%d", &productionCount);

    printf("Enter the productions \n");
    for (i = 0; i < productionCount; i++) {
        scanf("%s", grammar[i]);
    }

    for (i = 0; i < MAX; i++) {
        first[i][0] = '\0';
        follow[i][0] = '\0';
    }

    computeFirstSets();
    computeFollowSets();

    
    printf("\nFIRST :\n");
    for (i = 0; i < productionCount; i++) {
        printf("FIRST(%c) =  %s \n", grammar[i][0], first[i]);
    }

   
    printf("\nFOLLOW :\n");
    for (i = 0; i < productionCount; i++) {
        printf("FOLLOW(%c) =  %s \n", grammar[i][0], follow[i]);
    }

   

    return 0;
}

void computeFirstSets() {
    int i, j, k;

    for (i = 0; i < productionCount; i++) {
        char nonTerminal = grammar[i][0];
        for (j = 2; grammar[i][j] != '\0'; j++) {
            if (isupper(grammar[i][j])) { 
                findFirst(grammar[i][j], i, j);
                break;
            } else { 
                int len = strlen(first[i]);
                first[i][len] = grammar[i][j];
                first[i][len + 1] = '\0';
                break;
            }
        }
    }
}


void findFirst(char c, int q1, int q2) {
    int i, k;

    for (i = 0; i < productionCount; i++) {
        if (grammar[i][0] == c) {
            if (grammar[i][2] == '$') { 
                int len = strlen(first[q1]);
                first[q1][len] = '$';
                first[q1][len + 1] = '\0';
            } else if (islower(grammar[i][2])) {
                int len = strlen(first[q1]);
                first[q1][len] = grammar[i][2];
                first[q1][len + 1] = '\0';
            } else { 
                findFirst(grammar[i][2], q1, q2);
            }
        }
    }
}


void computeFollowSets() {
    int i, j, k;

    follow[0][0] = '$'; 

    for (i = 0; i < productionCount; i++) {
        for (j = 2; grammar[i][j] != '\0'; j++) {
            if (isupper(grammar[i][j])) {
                if (grammar[i][j + 1] != '\0' && !isupper(grammar[i][j + 1])) {
                    int len = strlen(follow[i]);
                    follow[i][len] = grammar[i][j + 1];
                    follow[i][len + 1] = '\0';
                } else if (grammar[i][j + 1] == '\0') {
                    for (k = 0; follow[i][k] != '\0'; k++) {
                        int len = strlen(follow[j]);
                        follow[j][len] = follow[i][k];
                        follow[j][len + 1] = '\0';
                    }
                }
            }
        }
    }
}

void isLL1(){
	
}

