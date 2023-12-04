#include<stdio.h>
#include<stdlib.h>

#include<string.h>

// Global variables
int i = 1, j = 0, no = 0, tmpChar = 90;

char expression[100], leftOperand[15], rightOperand[15];

// Structure to store position and operator information
struct expression
{
    int position;
    char operator;
} operators[15];

// Function declarations
void findOperators();
void explore();
void getLeftOperand(int);
void getRightOperand(int);

void main()
{
    printf("\t\tINTERMEDIATE CODE GENERATION\n\n");

    // Input the expression
    printf("Enter the Expression: ");
    scanf("%s", expression);

    // Print the intermediate code header
    printf("The intermediate code:\n");

    // Find operators in the expression
    findOperators();

    // Generate intermediate code
    explore();
}

// Function to find operators in the expression
void findOperators()
{
    // Loop through the expression to find operators and their positions
    for (i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == ':')
        {
            operators[j].position = i;
            operators[j++].operator = ':';
        }
        else if (expression[i] == '/')
        {
            operators[j].position = i;
            operators[j++].operator = '/';
        }
        else if (expression[i] == '*')
        {
            operators[j].position = i;
            operators[j++].operator = '*';
        }
        else if (expression[i] == '+')
        {
            operators[j].position = i;
            operators[j++].operator = '+';
        }
        else if (expression[i] == '-')
        {
            operators[j].position = i;
            operators[j++].operator = '-';
        }
    }
}

// Function to explore and generate intermediate code
void explore()
{
    i = 1;

    while (operators[i].operator != '\0')
    {
        getLeftOperand(operators[i].position);
        getRightOperand(operators[i].position);

        // Replace the operator with a temporary character
        expression[operators[i].position] = tmpChar--;

        // Print the intermediate code
        printf("\t%c := %s%c%s\t\t", expression[operators[i].position], leftOperand, operators[i].operator, rightOperand);
        printf("\n");

        i++;
    }

    getRightOperand(-1);

    // If no more operators, generate the final assignment
    if (no == 0)
    {
        getLeftOperand(strlen(expression));
        printf("\t%s := %s\n", rightOperand, leftOperand);
        exit(0);
    }

    // Generate the final assignment
    printf("\t%s := %c\n", rightOperand, expression[operators[--i].position]);
}

// Function to get the left operand of an operator
void getLeftOperand(int position)
{
    int w = 0, flag = 0;
    position--;

    while (position != -1 && expression[position] != '+' && expression[position] != '*' &&
           expression[position] != '=' && expression[position] != '\0' && expression[position] != '-' &&
           expression[position] != '/')
    {
        if (expression[position] != '$' && flag == 0)
        {
            leftOperand[w++] = expression[position];
            leftOperand[w] = '\0';
            expression[position] = '$';
            flag = 1;
        }

        position--;
    }
}

// Function to get the right operand of an operator
void getRightOperand(int position)
{
    int w = 0, flag = 0;
    position++;

    while (position != -1 && expression[position] != '+' && expression[position] != '*' &&
           expression[position] != '\0' && expression[position] != '=' && expression[position] != '-' &&
           expression[position] != '/')
    {
        if (expression[position] != '$' && flag == 0)
        {
            rightOperand[w++] = expression[position];
            rightOperand[w] = '\0';
            expression[position] = '$';
            flag = 1;
        }

        position++;
    }
}

