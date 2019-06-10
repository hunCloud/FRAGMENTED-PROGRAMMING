
#include <iostream>

using namespace std;

// _____________________________________________________
//|														|
//|			DATA STRUCTURE AND ALGORITHMS				|
//|_____________________________________________________|
// 1. Review
struct FRACTION {
	int num;
	int den;
};
// 1. Review

void Swap(void* a, void* b, int size) {
	void* temp = malloc(size);
	memcpy(temp, b, size);
	memcpy(b, a, size);
	memcpy(a, temp, size);
	free(temp);
}
template <typename T>
void SwapT(T& a, T& b) {
	T c = a;
	a = b;
	b = c;
}
ostream& operator<<(ostream& os, FRACTION t) {
	os << "{" << t.num << " ," << t.den << "}\t";
	return os;
}
template <class T>
void printT(ostream& os, T t) {
	os << t;
}
void Test0() {
	FRACTION a, b;
	a = { 1, 2 };
	b = { 3, 4 };
	//Swap(&a, &b, sizeof(FRACTION));
	SwapT<FRACTION>(a, b);
	cout << "a = {3, 4} == ";
	printT<FRACTION>(cout, a);
	cout << endl;
}
int main(int argc, char* const argv[]) {
	Test0();
	system("pause");
	return 0;
}