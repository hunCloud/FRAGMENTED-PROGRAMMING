/*31. What does const member function mean and how is it used?

Cannot change data member of class in member member function.*/
#include <iostream>
using namespace std;
class Object
{
public:
	int val;
public:
	int get() const {
		val = 22;// báo lỗi, không được phép thay đổi data member
		return val;
	}
	void set(int a) {// không có const nên đc phép thay đổi.
		val = a;
	}
};

int main(int argc, char* const argv[]) {
	Object obj1;
	obj1.set(10);
	cout << obj1.get();
	system("pause");
	return 0;
}