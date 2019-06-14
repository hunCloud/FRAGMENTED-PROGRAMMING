// why should you declare a destructor
// as virtual (virtual)?
/*You need to declare the destruct function as virtual when the class
 is designed as Base class so that another class
  inherits Base class.*/
#include <iostream>
using namespace std;
// just only call to Base
// destructor
class Base
{
public:
	~Base() {
		cout << "In virtual base class\n";
	}
};
class Derived : public Base
{
public:
	~Derived() {
		cout << "Derived destructor\n";
	}
};

int main(int argc, char* const argv[]) {
	Base* p = new Derived;
	delete p;
	system("pause");
	return 0;
}