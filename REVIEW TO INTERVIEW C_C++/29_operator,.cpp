/*29. What does the ‘,’ operator mean?

Comma operator

The operator performs the expression on the first operand first, then executes the expression to the second operand and returns the result of the second operand expression.*/

#include <iostream>
using namespace std;
int print(int a, int b) {
	cout << a << "; " << b << endl;
	return 1;
}
int main(int argc, char* const argv[]) {
	int a = 3;
	int b = 4;
	int z = 2121;
	z = (print(a, z)\
	     , b);//thực hiện hàm print trước rồi gán z=b sau.
	cout << "z = " << z << endl;
	cout << "a = " << a << endl;
	system("pause");
	return 0;
}