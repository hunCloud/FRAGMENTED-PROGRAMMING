

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
// 2. Search
#define SIZE_WORD 64
#define SIZE_MEANING 512
struct DICT {
	char word[SIZE_WORD];
	char meaning[SIZE_MEANING];
};

void createDictionary(DICT a[], int n) {
	LOOP(i, n) {
		cin.sync();
		cout << "Input word = ";
		cin.getline(a[i].word, SIZE_WORD);
		cin.sync();
		cout << "Input meaning = ";
		cin.getline(a[i].meaning, SIZE_MEANING);
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
void swapDict(DICT& a, DICT& b) {
	DICT c;
	strcpy_s(c.word, a.word);
	strcpy_s(a.word, b.word);
	strcpy_s(b.word, c.word);
	strcpy_s(c.meaning, a.meaning);
	strcpy_s(a.meaning, b.meaning);
	strcpy_s(b.meaning, c.meaning);
}
void SortArrayDict(DICT a[], int n) {
	LOOP(i, n - 1) {
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (!Comparisonstring(a[min].word, a[j].word))
				min = j;
		swapDict(a[i], a[min]);
	}
}
ostream& operator<<(ostream& os, DICT a) {
	os << a.word << ": " << a.meaning << '\t';
	return os;
}
void OutputDict(DICT a[], int n) {
	LOOP(i, n) {
		cout << a[i] << endl;
	}
}
#define NO_EXIST "No word suitable"
const char* searchWord(DICT a[], int n, const char* key) {
	string s;
	LOOP(i, n) {
		if (strcmp(a[i].word, key) == 0)
			return a[i].meaning;
	}
	return NO_EXIST;
}
#define SIZE_DICT 4
void TestDictionary() {
	DICT a[SIZE_DICT];
	createDictionary(a, SIZE_DICT);
	SortArrayDict(a, SIZE_DICT);
	OutputDict(a, SIZE_DICT);
	cout << searchWord(a, SIZE_DICT, "2");
}

int main(int argc, char* const argv[]) {
	TestDictionary();
	system("pause");
	return 0;
}