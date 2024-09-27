Programming Assignment 1

Summary
The goal of this assignment is to take two hexadecimal numbers and add them using the add operand. The output should be a 32-bit hexadecimal, and if the text was to have unsupported operations, display an error.

Working process:
The program takes in an example file given to us with an operand telling us what we should do and two hexidecimal values. Each line is taken in and analyzes if the operand is add, and takes in the two hexidecimal values. The numbers are converted into uint32_t in order to do the operation. The output is displayed after listing out the operand, and the two numbers being added. Whether or not the addition resulted in an overflow is listed beneath each answer as well.