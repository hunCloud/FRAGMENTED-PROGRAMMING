
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
template <typename T>
bool Min_2(T a, T b) {
	return a < b;
}
template <class T>
bool Max_2(T a, T b) {
	return a > b;
}
int FindMinMax(int a[], int n, bool(*Con)(int, int)) {
	int index = 0;
	for (int i = 1; i < n; i++)
		if (Con(a[i], a[index]))
			index = i;
	return index;
}
void Test2() {
	int a[] = { 2, 1, 4, 9, 0, 2 };
	int size = sizeof(a) / sizeof(a[0]);
	cout << "Maximum Index = " << FindMinMax(a, size, &Max_2) << endl;
	cout << "Minimum Index = " << FindMinMax(a, size, &Min_2) << endl;
}
int main(int argc, char* const argv[]) {
	Test2();
	system("pause");
	return 0;
}