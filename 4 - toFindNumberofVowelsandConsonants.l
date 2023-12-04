%{
#include<stdio.h>

// Initialize counters for vowels and consonants
int vowelCount = 0;
int consonantCount = 0;
%}

%%

// Rule to match vowels (both lowercase and uppercase), increment vowel count
[aeiouAEIOU] { vowelCount++; }

// Rule to match any alphabetical character (both lowercase and uppercase), increment consonant count
[a-zA-Z] { consonantCount++; }

%%

// Main function
int main() {
    // Prompt the user to enter a string
    printf("Enter a string: ");

    // Call the lexer function
    yylex();

    // Display the results
    printf("\nNumber of vowels: %d", vowelCount);
    printf("\nNumber of consonants: %d\n", consonantCount);

    return 0;
}

// Lexer wrap-up function (returns 1 to indicate the end of input)
int yywrap() {
    return 1;
}

