/*21. What does mutable keyword mean?

mutable allows us to change the member variable of the const object.*/
#include <iostream>

using namespace std;

class Base
{
public:
	mutable int val;
	void print() const {// phải const thì biến đối tượng const mới dùng được
		cout << "val = " << val << endl;
	}

};

int main(int argc, char* const argv[]) {
	const Base test;// biến đối tượng const
	test.val = 22;
	test.print();// dùng đc hàm const của đối tượng const.
	system("pause");
	return 0;
}