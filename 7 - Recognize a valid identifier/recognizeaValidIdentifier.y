%{
// Include necessary header file
#include<stdio.h>

// Variable to track the validity of the identifier
int valid = 1;
%}

// Token definitions
%token digit letter

// Rules section
%%
start : letter s
s     : letter s
       | digit s
       |
       ;
%%

// Error handling function for Bison
int yyerror()
{
    // Print an error message when the input is not an identifier
    printf("\nIt's not an identifier!\n");
    
    // Set the validity flag to 0
    valid = 0;
    
    // Return 0 indicating an error
    return 0;
}

int main()
{
    // Print a prompt to enter a name for testing
    printf("\nEnter a name to be tested for identifier:\t");
    
    // Invoke the parser generated by Bison
    yyparse();
    
    // Check the validity flag and print the result
    if (valid)
    {
        printf("\nIt is an identifier!\n");
    }

    // Return 0 indicating successful execution
    return 0;
}

