/*[Basic] Introduction to C ++
A brief history of C ++ development
C ++ (C plus plus) is developed by Bjarne Stroustrup at Bell Lab as an advanced version of the C language. This is a free-form multi-pattern language that has static type and supports procedural and data programming. abstract, object-oriented programming, and polymorphic programming. The C ++ standard was adopted in 1998 by ISO / IEC and again in 2003 (C ++ 03). The two most recently updated versions of C ++ are C ++ 11 (2011) and C ++ 14 (2014).

Steps to develop C ++ program
Before embarking on programming, we will learn about the process of developing a C ++ program.

Step 1 . Define the problem to be solved. (What?)
What is the problem that the program needs to solve? This is the first step and also the simplest step, which may also be the hardest. All you need is a clear requirement for the problem to be solved.

Step 2. Provide a solution to the problem (How?)
This is the step to give the solution to the problem in step 1. This is also a good step to ignore when developing software. The key is that there are many solutions to the problem, but every solution is beneficial and harmful. Usually programmers have ideas and immediately write code for a solution, maybe it is not the best solution.

Studies show that about 20% of the time is spent writing the original code, 80% of the time is spent fixing bugs or adding features. So take some time to give the best solution for the time-saving development problem later.

Step 3. Write code for the program.
To write the program we need:

Knowledge of a programming language.
Editor
C ++ files are usually saved with extensions:

Source file is .cpp
The file header is .h
Step 4. Compile the program
To compile the program we need a program called a compiler (Complier). The work of the compiler is.

Checking the program is definitely correct syntax of C ++.
Convert source file (.cpp) to machine language called object file (.o or .obj).
Step 5. Link the object files in step 5 (Linking)
When compiling the program each source file (.cpp) in the project will be converted to object file (.o or .obj). Then the file files will be combined into a single executable file that can run.

Step 6. Check and fix bugs.
When running the program, must check if the program has run the results as expected? If a bug occurs, check and fix the bug to make the program run perfectly.

Note: Steps 3 -> 6 are all done by the software, each program can be used for each step, but there is a software package that integrates all of these features called Integrated Development Environment (IDE). .

Integrated Development Environment (IDE).
An IDE contains everything we need to develop programs develop, compile, link, and debug so we should install one or more IDEs to experience.

Throughout the Coder Psychology tutorial I will use Visual Studio.

Introducing some IDE:

Visual Studio: Developed by Microsoft, it costs a fee to buy a license, but you can use the Express version for free. Download Visual Studio at: DOWNLOAD
Code :: Blocks: is free IDE, open source and multi-platform. Download Code :: Block at DOWNLOAD
Dev-C ++: is an Integrated Development Environment (IDE) that fully supports the C / C ++ programming language. It uses the MinGW program of the GCC (GNU compiler) as a compiler. Dev-C ++ can also be used in conjunction with Cygwin or any other GCC platform compiler. Download Dev-C ++ at DOWNLOAD
Build configurations
How to build configurations for IDE to determine how to build the program?

On each IDE we can choose from two build configurations: Debug and Release.

Since the build on each mode will be different, choose the build configuration that matches the purpose:

When developing the program, fix the bug we will build in Debug mode.
When the build builds we will build in Release mode.
You can read more about Debug and Release at Debug and Release distinction

We can switch between debug and release easily:

Convert build configuration in Visual Studio:
Convert build configuration in Code :: Blocks
*/