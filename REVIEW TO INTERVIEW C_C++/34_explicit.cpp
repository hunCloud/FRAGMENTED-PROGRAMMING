/*34. What does the explicit keyword mean?

For constructor, do not allow implicit compiler to solve function parameter.
[C/C++] explicit keyword
In C ++ it allows us to use the only parameter of the constructor, to implicitly convert the data type of that parameter to the data type of the class to pass to the function.

*/
#include <iostream>
using namespace std;
class Base
{
public:
	string get() const {
		return att;
	}
	explicit Base(string pass) {// dùng explicit để tránh nhầm lẫn ép string thành Base nhờ vao constructor
		att = pass;// lúc này tham số Base của hàm là tường minh không ép kiểu được
	}
private:
	string att;
};

void funcBase(Base obj) {
	cout << "atribute = " << obj.get() << endl;
}
int main(int argc, char* const argv[]) {
	string s("HHHHH\nNNNN");// tạo object Base từ constructor của Base
	// string đc dùng ngầm định parameter trogn constructor của Base
	funcBase((Base)s);// chuyển
	system("pause");
	return 0;
}