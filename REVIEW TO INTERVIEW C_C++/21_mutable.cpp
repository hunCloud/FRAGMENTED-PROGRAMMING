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
/*mutable
When programming with C ++, surely, we hear about mutable keywords three times.

So what is the mutable keyword used for?

Sometimes we need to change the value of the data member through the constant function (const function) of the class. However, as we know, the constant function does not allow to change the value of the data member.

=> What should we do?

In C ++ also give us the mutable keyword to easily do that. With the declared data member is mutable allows us to change their value in the constant function.

For example:*/
int main(int argc, char* const argv[]) {
	const Base test;// biến đối tượng const
	test.val = 22;
	test.print();// dùng đc hàm const của đối tượng const.
	system("pause");
	return 0;
}
/*The mubtable keyword allows us to change the constituent data member (const object).*/
/*Attention:

mubtable only applies to non-static (non-static) data members and non-const (not constants) data of the class.*/