/*12. What does a copy constructor mean and when is it used, especially when compared to the = operator?

The copy creation function is a special type of constructor, creating a new object from an existing object.*/
#include <iostream>
#include <string>
using namespace std;

class A
{
public:
	A() {}
	~A() {}

private:

};


int main(int argc, char* const argv[]) {
	A a;
	A b = a;// Hàm tạo sao chép được gọi
	A c(a);// ..
	A d;
	d = a;// Toán tử gán được gọi
	system("pause");
	return 0;
}