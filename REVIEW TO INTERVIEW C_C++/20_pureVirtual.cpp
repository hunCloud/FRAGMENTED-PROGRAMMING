/*20. What is a pure virtual function?

The pure virtual function is the function declared in the base class without the function definition, it is required to define the derived class.*/
#include <iostream>

using namespace std;

class Base
{
public:
	virtual void print() = 0;
	Base() {}
	~Base() {}

private:

};

class Devired
{
public:
	void print() {
		cout << "print function pure virtual of Base class is written.\n";
	}

private:

};

int main(int argc, char* const argv[]) {
	Devired test;
	test.print();
	system("pause");
	return 0;
}
