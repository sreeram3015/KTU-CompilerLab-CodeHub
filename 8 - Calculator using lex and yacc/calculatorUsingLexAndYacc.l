%{
#include<stdio.h>
#include "y.tab.h"  // Include the Bison-generated header file
extern int yylval;  // Declare yylval, which is used to communicate values to the parser
%}

// Flex rules section
%%
[0-9]+ {
    // Rule for recognizing numbers
    yylval = atoi(yytext);  // Convert the matched text to an integer and assign it to yylval
    return NUMBER;          // Return the token type NUMBER to the parser
}

[\t] ;  // Rule for matching tabs, which is ignored

[\n] return 0;  // Rule for matching newlines, indicating the end of input

. return yytext[0];  // Rule for matching any other character and returning it as a token
%%

 // Function to wrap up the lexer (mandatory for flex)
int yywrap()
{
    return 1;  // Indicate the end of input
}

