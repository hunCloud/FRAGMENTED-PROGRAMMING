#include <iostream>

using namespace std;
class Exp
{
public:
	int val;
	void print() {
		cout << "sss\n";
	}
};
int main(int argc, char* const argv[]) {
	Exp* exp = nullptr;
	exp->val = 11;// chương trình sẽ bị crash vì exp là null trỏ tới data member
	exp->print();// không bị crash vì trỏ tới method k thay đổi data member
	system("pause");
	return 0;
}