# Algorithm:

Open input and output files.

Initialize line number (l), token number (t), and other variables.

Print the output file header.

Read characters from the input file until the end is reached.

Check each character for operators, special symbols, digits, and alphabets.

If an operator or special symbol is found, print its details to the output file.

If a digit is found, print it as a token to the output file.

If an alphabet is found, read subsequent characters to form an identifier or keyword.

Check if the identifier is a keyword; if yes, print it as a keyword, else print it as an identifier.

If a newline character is encountered, increment the line number.

Close the input and output files.

End the program.