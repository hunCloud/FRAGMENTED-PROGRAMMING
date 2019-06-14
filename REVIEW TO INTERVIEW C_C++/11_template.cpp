/*9. What does the concept of namespace mean and how to use it?

Using namespace to define context for defined names. It defines the scope in which the identifier of the object is unique. We can define objects of the same name in different namespaces.

To define a namespace we use namespace keywords

namespace
{
   // Code here
}
To use namespaces we use the following methods:

Using the using statement:
using namespace ten_namespace;
Use the operator ‘::‘:
ten_namespace :: doi_tuong*/
#include <iostream>
#include <string>
using namespace std;

template <typename T>
T sum(T var1, T var2) {
	return var1 + var2;
}
template <class T>
class Myself
{
	T special;
public:
	void setSpecial(T special) {
		this->special = special;
	}
	T getSpecial() {
		return special;
	}
	Myself() {}
	~Myself() {}
};

int main(int argc, char* const argv[]) {
	Myself<int> Hung;
	Hung.setSpecial(23);
	cout << Hung.getSpecial() << endl;
	Myself<string> Me;
	Me.setSpecial("No thing here!\n");
	cout << Me.getSpecial();
	system("pause");
	return 0;
}