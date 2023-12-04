#include <stdio.h>
#include <string.h>

// Main function
void main() {
    // Array to store intermediate code
    char intermediateCode[10][30], currentInstruction[20], operation[10];
    
    // Variable for loop iteration
    int i = 0;

    // Input intermediate code until 'exit' is encountered
    printf("\nEnter the set of intermediate code (terminate with 'exit'):\n");
    do {
        // Read an intermediate code instruction and store it in the array
        scanf("%s", intermediateCode[i]);
    } while (strcmp(intermediateCode[i++], "exit") != 0);

    // Display header for target code generation
    printf("\nTarget code generation");
    printf("\n************************");

    // Reset the iteration variable
    i = 0;

    // Process each intermediate code instruction
    do {
        // Copy the current intermediate code instruction to a temporary variable
        strcpy(currentInstruction, intermediateCode[i]);

        // Determine the operation based on the third character of the instruction
        switch (currentInstruction[3]) {
            case '+':
                strcpy(operation, "ADD ");
                break;
            case '-':
                strcpy(operation, "SUB ");
                break;
            case '*':
                strcpy(operation, "MUL ");
                break;
            case '/':
                strcpy(operation, "DIV ");
                break;
        }

        // Display the target code instructions
        printf("\n\tMov %c,R%d", currentInstruction[2], i);
        printf("\n\t%s%c,R%d", operation, currentInstruction[4], i);
        printf("\n\tMov R%d,%c", i, currentInstruction[0]);

        // Move to the next intermediate code instruction
    } while (strcmp(intermediateCode[++i], "exit") != 0);

    // Display a newline at the end
    printf("\n");
}

