/*8. How do you access a variable that is "obscured" by another variable with the same name?

We can use the namespace: namespace :: variable name.

With the global variable we use: :: variable name.

For example:*/
#include <iostream>
using namespace std;
int val = 10;
int main(int argc, char* const argv[]) {
	// local variable
	int val = 20;
	// Change the value of global variable.
	::val = 30;
	// To display the value of local variable
	cout << "val = " << val << endl;
	// TO display the value of global variable
	cout << "::val = " << ::val << endl;
	system("pause");
	return 0;
}