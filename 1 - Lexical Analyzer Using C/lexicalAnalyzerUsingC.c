#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main() {
    // Declare file pointers for input and output
    FILE *inputFile, *outputFile;

    // Initialize line number, token number, and flags
    int lineNumber = 1;
    int tokenNumber = 0;
    int keywordIndex = 0;
    int charIndex, isKeyword;

    // Declare character and string variables
    char currentChar, lexeme[20];

    // Open input file in read mode and output file in write mode
    inputFile = fopen("input.txt", "r");
    outputFile = fopen("output.txt", "w");

    // Declare an array of keywords
    char keywords[30][30] = {"int", "main", "if", "else", "do", "while"};

    // Print header in the output file
    fprintf(outputFile, "Line no. \t Token no. \t Token \tLexeme\n\n");

    // Loop until the end of the input file is reached
    while (!feof(inputFile)) {
        charIndex = 0;  // Initialize index for the lexeme
        isKeyword = 0;  // Reset the flag
        currentChar = fgetc(inputFile);  // Read a character from the input file

        // Check if the character is an operator (+, -, *, /)
        if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
            fprintf(outputFile, "%7d\t\t %7d\t\t Operator\t %7c\n", lineNumber, tokenNumber, currentChar);
            tokenNumber++;
        }
        // Check if the character is a special symbol (;, {, }, (, ), ?, @, !, %)
        else if (currentChar == ';' || currentChar == '{' || currentChar == '}' || currentChar == '(' || currentChar == ')' || currentChar == '?' || currentChar == '@' || currentChar == '!' || currentChar == '%') {
            fprintf(outputFile, "%7d\t\t %7d\t\t Special symbol\t%7c\n", lineNumber, tokenNumber, currentChar);
            tokenNumber++;
        }
        // Check if the character is a digit
        else if (isdigit(currentChar)) {
            fprintf(outputFile, "%7d\t\t %7d\t\t Digit\t\t %7c\n", lineNumber, tokenNumber, currentChar);
            tokenNumber++;
        }
        // Check if the character is an alphabet
        else if (isalpha(currentChar)) {
            lexeme[charIndex] = currentChar;
            charIndex++;

            // Read subsequent characters forming an identifier or keyword
            currentChar = fgetc(inputFile);
            while (isalnum(currentChar) && currentChar != ' ') {
                lexeme[charIndex] = currentChar;
                charIndex++;
                currentChar = fgetc(inputFile);
            }

            // Terminate the string
            lexeme[charIndex] = '\0';

            // Check if the string is a keyword
            for (keywordIndex = 0; keywordIndex < 6; keywordIndex++) {
                if (strcmp(lexeme, keywords[keywordIndex]) == 0) {
                    isKeyword = 1;
                    break;
                }
            }

            // Print either keyword or identifier based on the flag
            if (isKeyword) {
                fprintf(outputFile, "%7d\t\t %7d\t\t Keyword\t%7s\n", lineNumber, tokenNumber, lexeme);
                tokenNumber++;
            } else {
                fprintf(outputFile, "%7d\t\t %7d\t\t Identifier\t%7s\n", lineNumber, tokenNumber, lexeme);
                tokenNumber++;
            }
        }
        // Check if the character is a newline character
        else if (currentChar == '\n') {
            lineNumber++;  // Increment the line number
        }
    }

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    // Return 0 to indicate successful execution
    return 0;
}
