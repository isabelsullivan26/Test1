Programming Assignment 2

Summary:
The goal of this assignment is to read in various ARM assembly instructions to perform arithmetic shifts, logical shifts, and bitwise operations. They are then saved to 8 different registers and their flag values are updated. These are all read from a file PA3.txt.

Working process:
The program takes in an example file given to us with different ARM assembly instructions. Each line is taken in and saves the correct registers, and the correct immediate value if the operation uses them. The numbers are converted into uint32_t in order to do the operation, and then their flag values are updated and the values of the registers are updated and displayed. The output is displayed after listing out the operand, and the two numbers being operated on. Each instruction is displayed, along with the register values after the instruction happens, and their flag values. 

Operation explanation:
MOV: loads immediate values into a register
ADDS: Adds two registers and stores the result in register 3
SUBS: Subtracts two registers and stores the result in register 3
ANDS: Bitwise and on two registers and then flags are updated
ORRS: Bitwise or on two registers and then flags are updated
XOR: Bitwise xor on two registers then updates flags
LSR: Logical right shift of bits
LSL: Logical left shift of bits 

TO EXECUTE: Call make, then ./instructions in the terminal.
