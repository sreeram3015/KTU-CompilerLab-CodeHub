%{
// Variable to track whether currently processing a comment
int COMMENT = 0;
%}

// Regular expressions and rules section
identifier [a-zA-Z][a-zA-Z0-9]*
%%

#.* {printf("\n%s is a preprocessor directive", yytext);}  // Preprocessor directive
int | float | char | double | while | for | struct | typedef | do | if | break | continue | void | switch | return | else | goto {
    printf("\n\t%s is a keyword", yytext);
}  // Keywords

"/*" {COMMENT=1;} {printf("\n\t %s is a COMMENT", yytext);}  // Start of a block comment
{identifier}\( {if (!COMMENT) printf("\nFUNCTION \n\t%s", yytext);}  // Function declaration
\{ {if (!COMMENT) printf("\n BLOCK BEGINS");}  // Beginning of a block
\} {if (!COMMENT) printf("BLOCK ENDS ");}  // End of a block
{identifier}(\[[0-9]*\])? {if (!COMMENT) printf("\n %s IDENTIFIER", yytext);}  // Identifiers with optional array notation
\".*\" {if (!COMMENT) printf("\n\t %s is a STRING", yytext);}  // String literals
[0-9]+ {if (!COMMENT) printf("\n %s is a NUMBER ", yytext);}  // Numbers
\)(\:)? {if (!COMMENT) printf("\n\t"); ECHO; printf("\n");}  // Right parenthesis and optional colon
\( ECHO;  // Left parenthesis
= {if (!COMMENT) printf("\n\t %s is an ASSIGNMENT OPERATOR", yytext);}  // Assignment operator
\<= | \>= | \< | == | \> {if (!COMMENT) printf("\n\t%s is a RELATIONAL OPERATOR", yytext);}  // Relational operators
%%

 // Main function
int main(int argc, char **argv)
{
    FILE *file;
    file = fopen("var.c", "r");
    if (!file)
    {
        printf("Could not open the file\n");
        exit(0);
    }

    yyin = file;
    yylex();  // Invoke the lexer
    printf("\n");
    return 0;
}

 // Function to wrap up the lexer (mandatory for flex)
int yywrap()
{
    return 1;  // Indicate the end of input
}

