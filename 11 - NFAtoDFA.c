#include <stdio.h>
#include <string.h>
#include <math.h>

// Constants
#define MAX_STATES 100
#define MAX_INPUTS 2

// Global variables
int nInputs;
int dfa[MAX_STATES][MAX_INPUTS][MAX_STATES] = {0};
int state[MAX_STATES * MAX_STATES] = {0};
char ch[10], str[1000];
int go[MAX_STATES * MAX_STATES][MAX_INPUTS] = {0};
int arr[MAX_STATES * MAX_STATES] = {0};

int main()
{
    int numStates, numFinalStates;
    int finalStates[10];
    int i, j = 3, currentState = 0, finalState = 0, flag = 0, current1, current2, k, l;
    int input;
     
    printf("\nFollow the one-based indexing\n");
     
    printf("\nEnter the number of states: ");
    scanf("%d", &numStates);
     
    printf("\nGive state numbers from 0 to %d", numStates - 1);
     
    for (i = 0; i < numStates; i++)
        state[(int)(pow(2, i))] = 1;

    printf("\nEnter the number of final states: ");
    scanf("%d", &numFinalStates);

    printf("\nEnter final states: ");
    for (i = 0; i < numFinalStates; i++)
    {
        scanf("%d", &finalStates[i]);
    }

    int p, q, r, rel;
     
    printf("\nEnter the number of rules according to NFA: ");
    scanf("%d", &rel);
     
    printf("\nDefine transition rule as \"initial state input symbol final state\"\n");

    for (i = 0; i < rel; i++)
    {
        scanf("%d%d%d", &p, &q, &r);
        if (q == 0)
            dfa[p][0][r] = 1;
        else
            dfa[p][1][r] = 1;          
    }

    printf("\nEnter initial state: ");
    scanf("%d", &input);

    input = pow(2, input);

    i = 0;
     
    printf("\nSolving according to DFA");
     
    int x = 0;
    for (i = 0; i < numStates; i++)
    {
        for (j = 0; j < MAX_INPUTS; j++)
        {
            int stateFlag = 0;
            for (k = 0; k < numStates; k++)
            {
                if (dfa[i][j][k] == 1)
                    stateFlag = stateFlag + pow(2, k);
            }
     
            go[(int)(pow(2, i))][j] = stateFlag;
            printf("%d-%d-->%d\n", (int)(pow(2, i)), j, stateFlag);
            if (state[stateFlag] == 0)
                arr[x++] = stateFlag;
            state[stateFlag] = 1;
        }
    }
     
    for (i = 0; i < x; i++)
    {
        printf("for %d ---- ", arr[x]);
        for (j = 0; j < MAX_INPUTS; j++)
        {
            int newState = 0;
            for (k = 0; k < numStates; k++)
            {
                if (arr[i] & (1 << k))
                {
                    int h = pow(2, k);
     
                    if (newState == 0)
                        newState = go[h][j];
                    newState = newState | (go[h][j]);
                }
            }
     
            if (state[newState] == 0)
            {
                arr[x++] = newState;
                state[newState] = 1;
            }
        }
    }
     
    printf("\nThe total number of distinct states are:\n");
     
    printf("STATE     0   1\n");
     
    for (i = 0; i < MAX_STATES * MAX_STATES; i++)
    {
        if (state[i] == 1)
        {
            int y = 0;
            if (i == 0)
                printf("q0 ");
     
            else
                for (j = 0; j < numStates; j++)
                {
                    int x = 1 << j;
                    if (x & i)
                    {
                        printf("q%d ", j);
                        y = y + pow(2, j);
                    }
                }
            printf("       %d   %d", go[y][0], go[y][1]);
            printf("\n");
        }
    }
    
    return 0;
}

