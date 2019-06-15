/*[Basic] The first concepts about C ++
The first C ++ program.
1. #include <iostream>

Statements that start with # are special commands called preprocessors, telling the compiler to perform a specific task:

#include <>: Add the contents of the header file to the included file.

#define: Define a macro

#if, #else: Compile according to conditions.
2. int main ()

The main function is a special function in C ++.

Each C ++ program has a single main function.

C ++ program will start executing from the beginning of main function.

The return type of main function is int

The end of the function on main will return 1 value to tell the operating system that the program is executing right or wrong:

Return 0: Successful execution of the program without errors
Return is different from 0: There is an error in the program, depending on the value that shows the error
Attention :

In standard C ++, the function main returns the int value only.
Some compilers can support void type, we should not use it.
Comment in C ++
Comments can be one line (or multiple lines) used to explain the code we write.

Use "comment content" to comment on 1 line
For example :
Should use the comment for the code I write to explain to others to read the code or a time after we read it again, we still understand the code we wrote.

The content of the comment should be used:

At the library, program, function, comment levels should answer the question what it does - What
In the libray, the program, function, comment should answer the question how to do it - How
With the variable and the comment statement, answer the question why it exists - Why
Variables, initialize (initialization) and assign (assign)
Simple variables are objects with names, stored in memory.
A variable includes data type and identifier (name)
To create a variable we use the variable called variable definition
For example :

l-values and r-values
l-values

l-values is a variable, the expression has an address in memory that can be changed.
l-values are used to the left of the assignment statement.
r-values

r-values is any value that can be assigned to l-values.
r-values always create unique values to assign to l-values
For example :
Initialization and assignment (assignment)
When defining a variable and giving it the initial value is called initialization.
For example :
Undefined behavior
The results of code execution are not clearly defined in the language.

Each compiler can give different results.

See UB details at: Undefine behavior

Attention :

Avoid writing code to lead to Undefined behavior.
Keywords and identifiers in C ++
Keywords in C ++

Naming rules in C ++
C ++ naming is required to follow the following rules:

The name cannot match the keyword
Name only includes characters, numbers and underscores (names cannot contain any other symbols including spaces)
The name must start with a letter or underscore, DO NOT start with a number.
Uppercase and ordinary names (NAME # Name)
For example:
Some naming conventions should be used
Should be named according to the convention so that the program we write is bright, easy to read and understand.

Variable and function names should begin with lowercase letters (camel Case).
For example :

Class, struct, and enum names should start with uppercase letters (Pascal Case)

Naming should mean expressing its function
Attention :

Avoid naming with meaningless characters
The variable name should be signed as a single sign when used in the loop
For example :


*/