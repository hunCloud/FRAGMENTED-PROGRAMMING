/*15. What is the difference between referencing, propagation, and pointer transmission in C ++?
- Call by value
	+ Create a copy of the passed variable, the expressions in the function perform on the copy.
	+ The value of the passed variable does not change after executing the function.
- Call by reference
	+ Direct operation on the address of the variable passed
	+ The value of the variable changes after executing the function, if the function changes the variable value.
- Call by pointer
	+ Operate on the address of the pointer to
	+ The value at the address the pointer points to after changing the function if the function changes the value
*/