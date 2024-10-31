Programming Assignment 2

Summary:
The goal of this assignment is to take two hexadecimal numbers and perform bitwise operations on numbers taken from a txt file. The output should be a 32-bit hexadecimal, and if its not, it will display an error.

Working process:
The program takes in an example file given to us with an operand telling us what we should do and two hexidecimal values. Each line is taken in and analyzes if the operand is valid, and takes in the two hexidecimal values. The only time one value is taken is when a not operand is specified within the text file. The numbers are converted into uint32_t in order to do the operation, except for ASR as those numbers are signed. The output is displayed after listing out the operand, and the two numbers being operated on. 

TO EXECUTE: Call ./operands in the terminal.
