#include <stdio.h>
#include <string.h>

// Global arrays to store results and states
char epsilonClosureResults[20][20], currentStateCopy[3], inputStates[20][20];

// Function to add a state to the result array
void addToEpsilonClosure(char currentState[3], int index) {
    strcpy(epsilonClosureResults[index], currentState);
}

// Function to display the epsilon closure of a state
void displayEpsilonClosure(int count) {
    int currentIndex = 0;
    printf("\n Epsilon closure of state %s = { ", currentStateCopy);
    
    // Loop through the epsilon closure results
    while (currentIndex < count) {
        printf("%s", epsilonClosureResults[currentIndex]);
        currentIndex++;
    }
    
    printf("}\n");
}

int main() {
    FILE *inputFile;
    inputFile = fopen("input.dat", "r");
    
    // Variables for reading input file
    char currentState[3];
    int fileEnd, epsilonClosureCount = 0, numOfStates, stateIndex = 0;
    char transitionState1[3], transitionInput[3], transitionState2[3];

    // Get the number of states from the user
    printf("\n Enter the number of states: \n");
    scanf("%d", &numOfStates);

    // Get the states from the user
    printf("\n Enter the states \n");
    
    // Populate inputStates array with user input
    for (stateIndex = 0; stateIndex < numOfStates; stateIndex++) {
        scanf("%s", inputStates[stateIndex]);
    }

    // Process each state
    for (stateIndex = 0; stateIndex < numOfStates; stateIndex++) {
        epsilonClosureCount = 0;
        // Copy the current state to 'currentStateCopy' for display purposes
        strcpy(currentState, inputStates[stateIndex]);
        strcpy(currentStateCopy, currentState);
        
        // Add the initial state to the epsilon closure result array
        addToEpsilonClosure(currentState, epsilonClosureCount++);

        // Loop through the input file
        while (1) {
            // Read three strings from the file: transitionState1, transitionInput, and transitionState2
            fileEnd = fscanf(inputFile, "%s%s%s", transitionState1, transitionInput, transitionState2);
            if (fileEnd == EOF) {
                break; // End of file reached
            }
            
            // Check if the current state matches transitionState1
            if (strcmp(currentState, transitionState1) == 0) {
                // Check if the input is epsilon ("e")
                if (strcmp(transitionInput, "e") == 0) {
                    // Add the next state to the epsilon closure result array and update the current state
                    addToEpsilonClosure(transitionState2, epsilonClosureCount++);
                    strcpy(currentState, transitionState2);
                }
            }
        }

        // Display the epsilon closure of the current state
        displayEpsilonClosure(epsilonClosureCount);

        // Rewind the input file for the next state
        rewind(inputFile);
    }

    // Close the input file
    fclose(inputFile);

    return 0;
}

