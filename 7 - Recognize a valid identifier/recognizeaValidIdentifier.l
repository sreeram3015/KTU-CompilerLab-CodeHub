%{
// Include the generated Bison header file
#include "y.tab.h"
%}

// Flex rules section
%%
[a-zA-Z_][a-zA-Z_0-9]* return letter; // Rule for identifying identifiers
[0-9]                return digit;  // Rule for identifying single digits
.                   return yytext[0]; // Rule for matching any other character
\n                  return 0;         // Rule for handling newline characters
%%

 // Function to wrap up the lexer (mandatory for flex)
int yywrap()
{
    return 1; // Indicate the end of input
}

