%{
#include <stdio.h>
%}

%%
// Rule to match any string containing the substring "abc"
.*abc.* {
    int i;

    // Loop through each character in the matched string
    for (i = 0; i < strlen(yytext); i++) {
        // Check if the current and next two characters form the sequence "abc"
        if (yytext[i] == 'a' && yytext[i + 1] == 'b' && yytext[i + 2] == 'c') {
            // Print "ABC" and skip the next two characters
            printf("ABC");
            i += 2;
        } else {
            // Print the current character
            printf("%c", yytext[i]);
        }
    }
}

%%

// Main function
int main() {
    // Prompt the user to enter an input string
    printf("Enter input string:\n");

    // Call the lexer function
    yylex();

    return 0;
}

// Lexer wrap-up function (returns 1 to indicate the end of input)
int yywrap() {
    return 1;
}

