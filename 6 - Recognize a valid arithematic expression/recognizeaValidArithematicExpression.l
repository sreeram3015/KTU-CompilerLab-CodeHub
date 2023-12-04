%{
#include "y.tab.h"
%}

// Flex rules section
%%
[a-zA-Z_][a-zA-Z_0-9]* return id;        // Rule for identifying identifiers
[0-9]+(\.[0-9]*)? return num;            // Rule for identifying numbers (including floating-point)
[+/*] return op;                          // Rule for identifying operators: +, /, *
. return yytext[0];                       // Rule for matching any other character and returning it
\n return 0;                              // Rule for matching newline and indicating end of input
%%

// Function to wrap up the lexer (mandatory for Flex)
int yywrap()
{
    return 1;  // Indicate the end of input
}

