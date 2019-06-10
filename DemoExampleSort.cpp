
#include <iostream>
#define LOOP(i, n) for (int i = 0; i < n; i++)
using namespace std;

// _____________________________________________________
//|														|
//|			DATA STRUCTURE AND ALGORITHMS				|
//|_____________________________________________________|
// 1. Review
template <class T>
void IncreaseSortArray(T a[], int size) {
	for (int i = 1; i < size; i++) {
		T x = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > x)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}

template <class T>
void OutputArray(T a[], int n) {
	LOOP(i, n)
	cout << a[i] << '\t';
	cout << endl;
}
template <class T>
bool Max_2(T a, T b) {
	return a > b;
}
void Test() {
	int a[] = { 1, 2, 4, 11, 2, 0 };
	int n = sizeof(a) / sizeof(a[0]);
	cout << "Demo IncreaseSort()\n";
	IncreaseSortArray<int>(a, n);
	OutputArray<int>(a, n);
	cout << "a[0] = 1 == " << a[0] << endl;
	cout << Max_2<int>(4, 4);
}
int main(int argc, char* const argv[]) {
	Test();
	system("pause");
	return 0;
}