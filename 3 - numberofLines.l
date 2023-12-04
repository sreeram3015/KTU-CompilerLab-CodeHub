%{
#include<stdio.h>

// Declare and initialize counters for lines (lc), spaces (sc), words (wc), and characters (cc)
int lineCount = 0, spaceCount = 0, wordCount = 0, charCount = 0;
%}

%%

// Rule to match newline characters, increment line count, and update character count
[\n] { lineCount++; charCount += yyleng; }

// Rule to match space and tab characters, increment space count, and update character count
[ \t] { spaceCount++; charCount += yyleng; }

// Rule to match one or more non-space characters, increment word count, and update character count
[^\t\n ]+ { wordCount++; charCount += yyleng; }

%%

// Main function
int main(int argc, char* argv[]) {
    printf("Enter the input:\n");

    // Call the lexer function
    yylex();

    // Display the results
    printf("The number of lines = %d\n", lineCount);
    printf("The number of spaces = %d\n", spaceCount);
    printf("The number of words = %d\n", wordCount);
    printf("The number of characters = %d\n", charCount);

    return 0;
}

// Lexer wrap-up function (returns 1 to indicate the end of input)
int yywrap() {
    return 1;
}

