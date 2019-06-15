/*22. What does volatile keyword mean?

The volatile keyword used for objects, informing the compiler that the value of that object can be changed by the operating system, another thread ……

Compiler will optimize the variables that are declared volatile
volatile
Optimize code

Consider the example*/
int val = 10;
while (val == 10) {
	// to do
}
/*When compiling, the compiler may optimize the code.

If the compiler sees the variable val NOT being changed any time, the compiler may optimize the val.
Val variable will be stored in the register 1 time, and the compiler only takes the value of variable val from the register without taking the value directly from address variable val. Meanwhile the while loop becomes while (true);

Optimize code will help the program run faster, but in many cases give unwanted results. As the example above, if we change the value of val from outside the program or from another thread to end the loop. However, the compiler will not receive the change, so the loop continues to execute without ending.

To turn it off is not optimized because the compiler uses the volatile keyword.*/