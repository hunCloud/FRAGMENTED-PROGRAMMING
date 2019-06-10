
#include <iostream>
#include <time.h>
#define LOOP(i, n) for (int i = 0; i < n; i++)
#define NOT_FOUND -1
using namespace std;

// _____________________________________________________
//|														|
//|			DATA STRUCTURE AND ALGORITHMS				|
//|_____________________________________________________|
// 2. Search
template <typename T>
int LinearExhaustive(T a[], int n, T x) {
	LOOP(i, n) {
		if (a[i] == x)
			return i;
	}
	return NOT_FOUND;
}
template <typename T>
int BinarySearch(T a[], int n, T x) {
	int l = 0, r = n - 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (a[m] == x)
			return m;
		else if (a[m] < x) {
			l = m + 1;
		}
		else
			r = m - 1;
	}
	return NOT_FOUND;
}

template <typename T>
void Sort(T a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (a[min] > a[j])
				min = j;
		swap(a[min], a[i]);
	}
}
template <typename T>
int LinearSentinel(T a[], int n, T x) {
	a[n] = x;
	for (int i = 0;; i++) {
		if (a[i] == x)
			return i;
	}
}
void TestSearch() {
	int a[] = { 3, 22, 11, 5, 76,5,12, 55 };
	int n = sizeof(a) / sizeof(a[0]);
	int need = 11;
	Sort(a, n);
	cout << "Found index = " << BinarySearch<int>(a, n, need);
}
int main(int argc, char* const argv[]) {
	TestSearch();
	system("pause");
	return 0;
}