/*[C / C ++] NULL and nullptr in C ++
As we already know the NULL value is usually assigned to the pointer to indicate that it is a null pointer (the pointer does not point to any address).

For example:
#define NULL 0
However, if we pay close attention to a little NULL in C ++, it is defined:

#define NULL 0
NULL is just a macro with a value of 0, not a value representing a null pointer.

Here we will ask two questions.

Do we use NULL for null pointers?
Is there any value that represents the null pointer?
With the first question, we can see that we can still use NULL, but in some cases we can give unwanted results (see example below).

With the second question, starting from C ++ 11 provides us nullptr, we can use nullptr to represent the null pointer.

For example.
*/
#include <iostream>

using namespace std;
void test(int* p) {
	cout << "Function pointer\n";
}
void test(int v) {
	cout << "Function int value\n";
}
int main(int argc, char* const argv[]) {
	test(NULL);// cout function int. But NULL=0(int)
	test(nullptr);// cout funciton of pointer
	system("pause");
	return 0;
}
/*In the above example, we call DoSomething (NULL); The compiler will understand that we call DoSomething with the parameter of type int. When we call DoSomething (nullptr); The compiler will call DoSomething with join
number of pointer types.

Conclusion: We should use nullptr for null pointers.*/