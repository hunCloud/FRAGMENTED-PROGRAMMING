
#include <iostream>
#include <time.h>
#include <Windows.h>
#define LOOP(i, n) for (int i = 0; i < n; i++)
#define NOT_FOUND -1
using namespace std;

// _____________________________________________________
//|														|
//|			DATA STRUCTURE AND ALGORITHMS				|
//|_____________________________________________________|
// 3. Sort
void sortInt(int a[], int n) {
	LOOP(i, n - 1) {
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (a[min] > a[j])
				min = j;
		swap(a[min], a[i]);
	}
}
int countMaxElement(int a[], int n) {
	int k = 1;
	for (int i = n - 2; i >= 0; i--)
		if (a[n - 1] == a[i])
			k++;
	return k;
}
#include <math.h>
void sortAbsInt(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int x = a[i];
		int j = i - 1;
		while (j >= 0 & abs(x) < abs(a[j])) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void printIntArr(int a[], int n) {
	LOOP(i, n)
		cout << a[i] << '\t';
	cout << endl;
}
int thirdMaxNumber(int a[], int n) {
	int* b = new int[n];
	LOOP(i, n)
		b[i] = a[i];
	LOOP(i, n - 1) {
		if (b[i] == b[i + 1]) {
			for (int j = i; j < n; j++)
				b[j] = b[j + 1];
			n--;
			i--;
		}
	}
	int x = b[n - 3];
	delete[] b;
	b = NULL;
	return x;
}
void sortDown(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int x = a[i];
		int j = i - 1;
		while (j >= 0 && x > a[j]) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void sortPosNeg(int a[], int n) {
	int* pos = new int[n];
	int* neg = new int[n];
	int n1 = 0, n2 = 0;
	LOOP(i, n) {
		if (a[i] > 0)
			pos[n1++] = a[i];
		else
			neg[n2++] = a[i];
	}
	sortInt(neg, n2);
	sortDown(pos, n1);
	LOOP(i, n1)
		a[i] = pos[i];
	for (int i = n1, j = 0; i < n && j < n2; i++, j++)
		a[i] = neg[j];
	delete[] pos, neg;
	pos = neg = NULL;
}
void sortEvenOdd(int a[], int n) {
	int* even = new int[n];
	int* odd = new int[n];
	int n1 = 0, n2 = 0;
	LOOP(i, n) {
		if (abs(a[i]) % 2 == 0)
			even[n1++] = a[i];
		else
			odd[n2++] = a[i];
	}
	sortDown(odd, n2);
	sortInt(even, n1);
	LOOP(i, n1)
		a[i] = even[i];
	for (int i = n1, j = 0; i < n && j < n2; i++, j++)
		a[i] = odd[j];
	delete[] even, odd;
	even = odd = NULL;
}
void Test1() {
	int a[] = { 12, 2, 15, -3, 8, 5, 1, -8, 6, 0, 4, 15 };
	int n = sizeof(a) / sizeof(int);
	sortInt(a, n);
	printIntArr(a, n);
	cout << "The third maximum number is " << a[n - 3] << endl;
	cout << "The number of maximum element is: " << thirdMaxNumber(a, n) << endl;
	sortAbsInt(a, n);
	printIntArr(a, n);
	sortPosNeg(a, n);
	printIntArr(a, n);
	sortEvenOdd(a, n);
	printIntArr(a, n);
}
int main(int argc, char* const argv[]) {
	Test1();
	system("pause");
	return 0;
}