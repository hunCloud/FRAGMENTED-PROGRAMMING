//	how many ways to initialize
//a primitive data type in C++ and what are those?
#include <iostream>
using namespace std;

int main(int argc, char* const argv[]) {
	int a = 3;// copy initialization. khởi tạo bản sao
	int b(4);// direct initialization. khởi tạo trực tiếp
	int c{ 5 };// uniform initialization (suport c++ 11) khởi tạo thống nhất

	system("pause");
	return 0;
}