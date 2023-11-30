#include <stdio.h>
#include <stdlib.h>

// Structure representing a node in the transition table
struct Node {
    int state;
    struct Node* link;
};

void findEpsilonClosure(int, int);
void insertTransitionTable(int, char, int);
int findAlphabetIndex(char);
void findFinalStates(void);
void unionClosure(int);
void printEpsilonClosure(int);

// Global variables
static int set[20], numStates, numAlphabets, currentState, numTransitions, numFinalStates, startState, finalStates[20], index, buffer[20];
char alphabets[20], transitionCharacter;
static int epsilonClosure[20][20] = {0};
struct Node* transitionTable[20][20] = {NULL};

// Main function
void main() {
    int i, j, k, m, t, n;

    struct Node* temp;

    printf("Enter the number of alphabets?\n");
    scanf("%d", &numAlphabets);
    getchar();

    printf("NOTE:- [ use letter e as epsilon]\n");
    printf("NOTE:- [e must be the last character, if present]\n");

    printf("Enter alphabets?\n");
    for (i = 0; i < numAlphabets; i++) {
        alphabets[i] = getchar();
        getchar();
    }

    printf("Enter the number of states?\n");
    scanf("%d", &numStates);

    printf("Enter the start state?\n");
    scanf("%d", &startState);

    printf("Enter the number of final states?\n");
    scanf("%d", &numFinalStates);

    printf("Enter the final states?\n");
    for (i = 0; i < numFinalStates; i++)
        scanf("%d", &finalStates[i]);

    printf("Enter the number of transitions?\n");
    scanf("%d", &numTransitions);

    printf("NOTE:- [Transition is in the form--> qno   alphabet   qno]\n");
    printf("NOTE:- [States number must be greater than zero]\n");

    printf("Enter transitions?\n");
    for (i = 0; i < numTransitions; i++) {
        scanf("%d %c %d", &currentState, &transitionCharacter, &index);
        insertTransitionTable(currentState, transitionCharacter, index);
    }

    printf("\n");

    // Find epsilon closure for each state
    for (i = 1; i <= numStates; i++) {
        transitionCharacter = 0;
        for (j = 0; j < 20; j++) {
            buffer[j] = 0;
            epsilonClosure[i][j] = 0;
        }
        findEpsilonClosure(i, i);
    }

    printf("Equivalent NFA without epsilon\n");
    printf("-----------------------------------\n");

    printf("Start state:");
    printEpsilonClosure(startState);
    printf("\nAlphabets:");
    for (i = 0; i < numAlphabets; i++)
        printf("%c ", alphabets[i]);

    printf("\nStates:");
    for (i = 1; i <= numStates; i++)
        printEpsilonClosure(i);

    printf("\nTransitions are...:\n");

    for (i = 1; i <= numStates; i++) {
        for (j = 0; j < numAlphabets - 1; j++) {
            for (m = 1; m <= numStates; m++)
                set[m] = 0;
            for (k = 0; epsilonClosure[i][k] != 0; k++) {
                t = epsilonClosure[i][k];
                temp = transitionTable[t][j];
                while (temp != NULL) {
                    unionClosure(temp->state);
                    temp = temp->link;
                }
            }
            printf("\n");
            printEpsilonClosure(i);
            printf("%c\t", alphabets[j]);
            printf("{");
            for (n = 1; n <= numStates; n++) {
                if (set[n] != 0)
                    printf("q%d,", n);
            }
            printf("}");
        }
    }

    printf("\nFinal states:");
    findFinalStates();
    printf("\n");
}

// Function to find epsilon closure for a given state
void findEpsilonClosure(int stateX, int sta) {
    struct Node* temp;
    int i;
    if (buffer[stateX])
        return;
    epsilonClosure[sta][transitionCharacter++] = stateX;
    buffer[stateX] = 1;
    if (alphabets[numAlphabets - 1] == 'e' && transitionTable[stateX][numAlphabets - 1] != NULL) {
        temp = transitionTable[stateX][numAlphabets - 1];
        while (temp != NULL) {
            findEpsilonClosure(temp->state, sta);
            temp = temp->link;
        }
    }
}

// Function to insert a transition into the transition table
void insertTransitionTable(int stateR, char character, int stateS) {
    int j;
    struct Node* temp;
    j = findAlphabetIndex(character);
    if (j == 999) {
        printf("Error\n");
        exit(0);
    }
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->state = stateS;
    temp->link = transitionTable[stateR][j];
    transitionTable[stateR][j] = temp;
}

// Function to find the index of an alphabet character
int findAlphabetIndex(char character) {
    int i;
    for (i = 0; i < numAlphabets; i++)
        if (alphabets[i] == character)
            return i;

    return (999);
}

// Function to perform union of closures
void unionClosure(int i) {
    int j = 0, k;
    while (epsilonClosure[i][j] != 0) {
        k = epsilonClosure[i][j];
        set[k] = 1;
        j++;
    }
}

// Function to find and print final states
void findFinalStates() {
    int i, j, k, t;
    for (i = 0; i < numFinalStates; i++) {
        for (j = 1; j <= numStates; j++) {
            for (k = 0; epsilonClosure[j][k] != 0; k++) {
                if (epsilonClosure[j][k] == finalStates[i]) {
                    printEpsilonClosure(j);
                }
            }
        }
    }
}

// Function to print epsilon closure of a state
void printEpsilonClosure(int state) {
    int j;
    printf("{");
    for (j = 0; epsilonClosure[state][j] != 0; j++)
        printf("q%d,", epsilonClosure[state][j]);
    printf("}\t");
}
