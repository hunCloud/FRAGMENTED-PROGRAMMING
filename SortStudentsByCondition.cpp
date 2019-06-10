
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
#define SIZE_NAME 40
struct STUDENT {
	int stud_code;
	char name[SIZE_NAME];
	int birth_year;
};
ostream& operator<<(ostream& os, const STUDENT t) {
	os << "CODE: " << t.stud_code << endl;
	os << "NAME: " << t.name << endl;
	os << "BIRTH YEAR: " << t.birth_year << endl;
	return os;
}
void assignStud(STUDENT& c, STUDENT const a) {
	c.birth_year = a.birth_year;
	strcpy_s(c.name, a.name);
	c.stud_code = a.stud_code;
}
void swapStud(STUDENT& a, STUDENT& b) {
	STUDENT c;
	assignStud(c, a);
	assignStud(a, b);
	assignStud(b, c);
}
void sortStudArrID(STUDENT a[], int n) {
	LOOP(i, n - 1) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j].stud_code < a[min].stud_code)
				min = j;
		}
		if (a[i].stud_code != a[min].stud_code)
			swapStud(a[i], a[min]);
	}
}
void convertToString(string& s, char* a) {
	int len = strlen(a);
	LOOP(i, len)
		s.push_back(a[i]);
	s[len] = '\0';
}
int Comparisonstring(char* a, char* b) {
	string sa, sb;
	convertToString(sa, a);
	convertToString(sb, b);
	if (sa == sb)
		return 0;
	if (sa < sb)
		return -1;
	return 1;
}
void sortStudArrName(STUDENT a[], int n) {
	int t;
	LOOP(i, n - 1) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			t = Comparisonstring(a[min].name, a[j].name);
			if (t >= 0)
			{
				if (t > 0)
					min = j;
				else {
					if (a[min].birth_year > a[j].birth_year)
						min = j;
				}
			}
			if (min != i)
				swapStud(a[min], a[i]);
		}
	}
}
istream& operator>>(istream& is, STUDENT& t) {
	cout << "Enter ID code: "; is >> t.stud_code;
	cout << "Enter student name: ";
	//is.ignore(10, '\n');
	is >> ws;
	is.getline(t.name, SIZE_NAME);
	//is.sync();
	cout << "Enter birth year: ";
	is >> t.birth_year;
	return is;
}
void createStudArr(STUDENT a[], int n) {
	LOOP(i, n) {
		cout << "Input info of student " << i << endl;
		cin >> a[i];
	}
}
void printStudArr(STUDENT a[], int n) {
	LOOP(i, n) {
		cout << a[i];
	}
	cout << endl;
}
#define SIZE_ARRAY 3
void TestStudent() {
	STUDENT a[SIZE_ARRAY];
	createStudArr(a, SIZE_ARRAY);
	printStudArr(a, SIZE_ARRAY);
	sortStudArrID(a, SIZE_ARRAY);
	printStudArr(a, SIZE_ARRAY);
	sortStudArrName(a, SIZE_ARRAY);
	printStudArr(a, SIZE_ARRAY);
}

int main(int argc, char* const argv[]) {
	TestStudent();
	system("pause");
	return 0;
}