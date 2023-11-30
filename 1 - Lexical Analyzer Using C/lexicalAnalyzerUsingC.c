#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main() {
    // Declare file pointers for input and output
    FILE *input, *output;

    // Initialize line number, token number, and flags
    int l = 1;
    int t = 0;
    int j = 0;
    int i, flag;

    // Declare character and string variables
    char ch, str[20];

    // Open input file in read mode and output file in write mode
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");

    // Declare an array of keywords
    char keyword[30][30] = {"int", "main", "if", "else", "do", "while"};

    // Print header in the output file
    fprintf(output, "Line no. \t Token no. \t Token \tLexeme\n\n");

    // Loop until the end of the input file is reached
    while (!feof(input)) {
        i = 0;  // Initialize index for the string
        flag = 0;  // Reset the flag
        ch = fgetc(input);  // Read a character from the input file

        // Check if the character is an operator (+, -, *, /)
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            fprintf(output, "%7d\t\t %7d\t\t Operator\t %7c\n", l, t, ch);
            t++;
        }
        // Check if the character is a special symbol (;, {, }, (, ), ?, @, !, %)
        else if (ch == ';' || ch == '{' || ch == '}' || ch == '(' || ch == ')' || ch == '?' || ch == '@' || ch == '!' || ch == '%') {
            fprintf(output, "%7d\t\t %7d\t\t Special symbol\t%7c\n", l, t, ch);
            t++;
        }
        // Check if the character is a digit
        else if (isdigit(ch)) {
            fprintf(output, "%7d\t\t %7d\t\t Digit\t\t %7c\n", l, t, ch);
            t++;
        }
        // Check if the character is an alphabet
        else if (isalpha(ch)) {
            str[i] = ch;
            i++;

            // Read subsequent characters forming an identifier or keyword
            ch = fgetc(input);
            while (isalnum(ch) && ch != ' ') {
                str[i] = ch;
                i++;
                ch = fgetc(input);
            }

            // Terminate the string
            str[i] = '\0';

            // Check if the string is a keyword
            for (j = 0; j < 6; j++) {
                if (strcmp(str, keyword[j]) == 0) {
                    flag = 1;
                    break;
                }
            }

            // Print either keyword or identifier based on the flag
            if (flag == 1) {
                fprintf(output, "%7d\t\t %7d\t\t Keyword\t%7s\n", l, t, str);
                t++;
            } else {
                fprintf(output, "%7d\t\t %7d\t\t Identifier\t%7s\n", l, t, str);
                t++;
            }
        }
        // Check if the character is a newline character
        else if (ch == '\n') {
            l++;  // Increment the line number
        }
    }

    // Close the input and output files
    fclose(input);
    fclose(output);

    // Return 0 to indicate successful execution
    return 0;
}
