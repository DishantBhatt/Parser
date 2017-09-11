

Dishant Bhatt 
James Lawrence
CS 530, Spring 2017
Assignment #3, Parser for Assignments and Expressions
README.md

Files:

parser.cpp

Makefile

input: in.txt

output: out.txt

README.txt


Compile Instructions:
	In order to compile the program, simply type "make" into the command line and press enter.

Run Instructions:
	In order to run the program, type "./parser" into the command line after compiling. This is assuming a file named "in.txt" has been placed in the directory by the professor. The text from in.txt will then be written to "out.txt" (which is created by parser.cpp). The text will be labeled as valid or invalid. If invalid, and explanation as to why will also be explained. The error explanation will be the first error encountered in the statement.

The Assignment 3 goal was to take a text file of assignments and expressions and validate each text line. We programmed using C++ with g++ compiler. We included methods and flags to test each line. We validated the statements by incrementing through each of the characters. When an operand, parenthesis, semi-colon, or digit was encountered we ran tests to make sure they were utilized properly. These tests were conducted by a series of methods that returned a boolean value. 

VALIDATION RULES:
If an operand is not followed by a blank space or if the next character after an operand is another operand, the statement is invalid.
If the statement begins with an operand or number, it is invalid.
If a expression name begins with a number (i.e "4four") it is invalid.
If part of the expression is just a number (i.e "4" or 23") it is invalid.
If there are unbalanced parenthesis the statement is invalid. 
If there is a semi-colon in the middle of the statement or if there is no ending semi-colon then the statement is invalid.
If a statment ends with an operand, regardless of the presence of a ending semi-colon, the statment is invalid. 

As far as we know, there are no deficiencies or bugs within the program. While we were able to validate the expressions and assignments for single pairs of parenthesis, we were unable to validate for nested parenthesis as part of the extra credit assignment. 

