/*28. What does the short circuit estimate mean? How is it used? Why can its use be dangerous?

Short circuits are logical operators: &&, ||

It is used when checking multiple conditions.

It can be dangerous:

With and: dk1 && dk2 operator (if dk 1 false does not check dk2, dk2 can be side effect)
With operator or: dk1 || dk2 (if dk 1 true does not check dk2, dk2 can be side effect)*/
#include <iostream>
using namespace std;

int main(int argc, char* const argv[]) {
	bool a = true;
	bool b = false;
	// xem thử trong if nó có kiểm tra hết a và b, rồi dùng a&&b không, tương tự cho tất cả.
	if (b && a)
		cout << "1\n";
	if (a && b)// xem thử
		cout << "2\n";
	if (b || a)
		cout << "3\n";
	if (a || b)
		cout << "4\n";
	system("pause");
	return 0;
}