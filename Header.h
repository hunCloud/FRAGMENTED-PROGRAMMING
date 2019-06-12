
#include <iostream>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <string>
#include <vector>
#define LOOP(i, n) for (int i = 0; i < n; i++)
#define NOT_FOUND -1
#define SIZE_TEST 100
using namespace std;

//_______________________________________________________
//********************************
// DATA STRUCTURE AND ALGORITHMS
//_____________________________________________________________
struct FRACTION {
	int num;
	int den;
};
// 1. Review
ostream& operator<<(ostream& os, FRACTION t) {
	os << "{" << t.num << " ," << t.den << "}\t";
	return os;
}
template <class T>
bool Max_2(T a, T b) {
	return a > b;
}
template <class T>
bool Min_2(T a, T b) {
	return a < b;
}
void Swap(void* a, void* b, int size) {
	void* temp = malloc(size);
	memcpy(temp, b, size);
	memcpy(b, a, size);
	memcpy(a, temp, size);
	free(temp);
}
void Copy(void* a, void* b, int size) {
	memcpy(a, b, size);
}
template <class T>
bool operator>(T a, T b) {
	return Min_2(a, b);
}

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
void Test0() {
	FRACTION a, b;
	a = { 1, 2 };
	b = { 3, 4 };
	Swap(&a, &b, sizeof(FRACTION));
	cout << "a = {3, 4} == " << a << endl;
}
template <class T>
void OutputArray(T a[], int n) {
	LOOP(i, n)
		cout << a[i] << '\t';
	cout << endl;
}
void Test() {
	int a[] = { 1, 2, 4, 11, 2, 0 };
	int n = sizeof(a) / sizeof(a[0]);
	cout << "Demo IncreaseSort()\n";
	IncreaseSortArray<int>(a, n);
	OutputArray<int>(a, n);
	cout << "a[0] = 2 == " << a[0] << endl;
	cout << Max_2<int>(4, 4);
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
void TestString() {
	string a[3] = { "hello", "xin chao", "mina" };
	IncreaseSortArray<string>(a, 3);
	cout << a[0].c_str() << endl;
	cout << a[1].c_str() << endl;
	cout << a[2].c_str() << endl;
}


struct NODE {
	void* data;
	NODE* pNext;
};
typedef NODE* refNode;
struct LIST
{
	NODE* head;
	NODE* tail;
};

NODE* getNode(void* x, int dSize) {
	NODE* p = (NODE*)malloc(sizeof(NODE));
	if (!p) {
		cout << "Not enough memory!\n";
		exit(0);
	}
	p->data = (void*)malloc(dSize);
	if (!p->data) {
		cout << "Leak memory!\n";
		exit(0);
	}
	memcpy(p->data, x, dSize);
	p->pNext = NULL;
	return p;
}

void initList(LIST& L) {
	L.head = L.tail = NULL;
}
void addHead(LIST& L, void* x, int dSize) {
	refNode p = getNode(x, dSize);
	if (L.head == NULL) {
		L.head = L.tail = p;
	}
	else {
		p->pNext = L.head;
		L.head = p;
	}
}
void printList(LIST l) {
	refNode p = l.head;
	for (; p; p = p->pNext)
		cout << *((int*)(p->data)) << '\t';
	cout << endl;
}
void TestLinkedList() {
	LIST l;
	initList(l);
	LOOP(i, 4) {
		int x = i + 1;
		addHead(l, &x, sizeof(x));
	}
	printList(l);
}
void TestReadFile() {
	FILE* f;
	const char* INT_DATA = "ints data.txt";
	errno_t stt = fopen_s(&f, INT_DATA, "wt");
	cout << "errno_t = " << stt \
		<< "\nMeaning successfully read!"
		<< endl;
	LOOP(i, 10)
		fprintf_s(f, "n = %d\n", i);
	fclose(f);
	FILE* fi;
	fopen_s(&fi, INT_DATA, "rt");
	int x;
	while (!feof(fi)) {
		if (fscanf_s(fi, "n = %d\n", &x) > 0)
			cout << x << '\t';
		else
			break;
	}
	const char* FLOAT_DATA = "float data.txt";
	FILE* ff, * fout;
	float y;
	int ran;
	fopen_s(&ff, FLOAT_DATA, "a+");
	srand(time(NULL));
	LOOP(i, 9) {
		ran = 1 + rand() % (i + 1);
		y = rand() % 22 + i / (float)ran;
		fprintf_s(ff, "%.4f\t", y);
	}
	fclose(ff);
	fopen_s(&fout, FLOAT_DATA, "rt");
	while (!feof(fout)) {
		if (fscanf_s(fout, "%f\t", &y) > 0)// not use the format %.4f
			cout << y << '\t';
		else
			break;
	}
	_fcloseall();
}
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
void DemoCalTime() {
	clock_t t1 = clock();
	Sleep(2222);
	float dur = clock() - t1;
	cout << dur << endl;
}
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
#define SIZE_ARRAY 13
void TestStudent() {
	STUDENT a[SIZE_ARRAY];
	createStudArr(a, SIZE_ARRAY);
	printStudArr(a, SIZE_ARRAY);
	sortStudArrID(a, SIZE_ARRAY);
	printStudArr(a, SIZE_ARRAY);
	sortStudArrName(a, SIZE_ARRAY);
	printStudArr(a, SIZE_ARRAY);
}
// extra exercises
static int countSSComparisons = 0;
static int countISComparisons = 0;
static int countHSComparisons = 0;
static int countQSComparisons = 0;
static int countMSComparisons = 0;

static int countSSAssignments = 0;
static int countISAssignments = 0;
static int countHSAssignments = 0;
static int countQSAssignments = 0;
static int countMSAssignments = 0;
template <typename T>
void SELECTION_SORT(T a[], int n) {
	countSSAssignments++;
	for (int i = 0; (++countSSComparisons) && i < n - 1; i++ && countSSAssignments++) {
		int min = i;
		countSSAssignments += 2;
		for (int j = i + 1; (++countSSComparisons) && j < n; countSSAssignments++ && j++) {
			if ((++countSSComparisons) && a[min] > a[j]) {
				min = j;
				countSSAssignments++;
			}
		}
		if ((++countSSComparisons) && min != i) {
			swap(a[i], a[min]);
			countSSAssignments += 3;
		}
	}
}
template <typename T>
void INSERTION_SORT(T a[], int n) {
	++countISAssignments;
	for (int i = 1; ++countISComparisons && i < n; ++countISAssignments && i++) {
		int j = i - 1;
		T x = a[i];
		countISAssignments += 2;
		while ((countISComparisons += 2) && j >= 0 && x < a[j]) {
			a[j + 1] = a[j];
			j--;
			countISAssignments += 2;
		}
		a[j + 1] = x;
		++countISAssignments;
	}
}
template <typename T>
void HEAPIFY(T a[], int n, int i) {
	countHSAssignments += 3;
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if ((countHSComparisons += 2) && l<n && a[l]>a[largest]) {
		largest = l;
		countHSAssignments++;
	}
	if ((countHSComparisons += 2) && r<n && a[r]>a[largest]) {
		countHSAssignments++;
		largest = r;
	}
	if (i != largest) {
		swap(a[i], a[largest]);
		countHSAssignments += 3;
		HEAPIFY(a, n, largest);
	}
}
template <typename T>
void HEAP_SORT(T a[], int n) {
	countHSAssignments++;
	for (int i = n / 2 - 1; i >= 0; countHSAssignments++ && i--)
		HEAPIFY(a, n, i);
	countHSAssignments++;
	for (int i = n - 1; i >= 0; countHSAssignments++ && i--) {
		swap(a[0], a[i]);
		countHSAssignments += 3;
		HEAPIFY(a, i, 0);
	}
}
#define RANDOM_VALUE 4444
void createInt(int a[], int n) {
	int x, y;
	srand(time(NULL));
	LOOP(i, n) {
		x = -i + rand() % (RANDOM_VALUE + i);
		y = rand() % (RANDOM_VALUE);
		a[i] = x - y;
	}
}
template <typename T>
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
	array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int PARTITION(T arr[], int low, int high)
{
	countQSAssignments += 3;
	T pivot = arr[high];    // pivot 
	int i = (low - 1);  // Index of smaller element 

	for (int j = low; (countQSComparisons++) && (j <= high - 1); (countQSAssignments++) && (j++))
	{
		// If current element is smaller than or 
		// equal to pivot 
		if ((++countQSComparisons) && (arr[j] <= pivot))
		{
			i++;    // increment index of smaller element 
			swap(arr[i], arr[j]);
			countQSAssignments += 4;
		}
	}
	swap(arr[i + 1], arr[high]);
	countQSAssignments += 3;
	return (i + 1);
}

/* The main function that implements QUICK_SORT
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
template <typename T>
void QUICK_SORT(T arr[], int low, int high)
{
	if ((++countQSComparisons) && (low < high))
	{
		/* pi is partitioning index, arr[p] is now
		   at right place */
		int pi = PARTITION(arr, low, high);
		countQSAssignments++;
		// Separately sort elements before 
		// PARTITION and after PARTITION 
		QUICK_SORT(arr, low, pi - 1);
		QUICK_SORT(arr, pi + 1, high);
	}
}

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 

void MERGE(int a[], int l, int m, int r)
{
	int i, j, k;
	// m = l + (r - 1) / 2;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[SIZE_TEST], R[SIZE_TEST];
	LOOP(t, n1)
		L[t] = a[l + t];
	LOOP(t, n2)
		R[t] = a[m + 1 + t];

	i = 0, j = 0, k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		a[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		a[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */

void MERGE_SORT(int a[], int l, int r)
{
	if (l < r)
	{

		int m = l + (r - 1) / 2;
		MERGE_SORT(a, l, m);
		MERGE_SORT(a, m + 1, r);
		MERGE(a, l, m, r);
	}
}
template <class T>
void arrcpy(T a[], int arr[], int n) {
	LOOP(i, n)
		arr[i] = a[i];
}
void TestSort() {
	int a[SIZE_TEST];
	int a1[SIZE_TEST];
	int a2[SIZE_TEST];
	int a3[SIZE_TEST];
	int a4[SIZE_TEST];
	int n = SIZE_TEST;
	clock_t t1 = clock();
	createInt(a, SIZE_TEST);
	clock_t t2 = clock();
	arrcpy<int>(a, a1, n);
	arrcpy<int>(a, a2, n);
	arrcpy<int>(a, a3, n);
	arrcpy<int>(a, a4, n);
	//arrcpy<int>(a, a4);
	cout << "TIME THAT CREATE " << SIZE_TEST << " ELEMENTS" << \
		t2 - t1 << "ms" << endl;
	clock_t t3 = clock();
	SELECTION_SORT<int>(a, SIZE_TEST);
	clock_t t4 = clock();
	cout << "TIME SELECTION SORT:\t" << t4 - t3 << "ms" << endl;
	clock_t t5 = clock();
	INSERTION_SORT<int>(a1, SIZE_TEST);
	clock_t t6 = clock();
	cout << "TIME INSERTION SORT:\t" << t6 - t5 << "ms" << endl;
	clock_t t7 = clock();
	QUICK_SORT<int>(a2, 0, SIZE_TEST - 1);
	clock_t t8 = clock();
	cout << "TIME QUICK SORT:\t" << t8 - t7 << "ms" << endl;
	clock_t t9 = clock();
	HEAP_SORT<int>(a3, SIZE_TEST);
	clock_t t10 = clock();
	cout << "TIME HEAP SORT:\t" << t10 - t9 << "ms" << endl;
	cout << "\n\n\n";
	cout << "\t\t: Selection\tInsertion\tHeap\tQuick\n";
	cout << "Assignments\t" << countSSAssignments << '\t' << \
		countISAssignments << '\t' << countHSAssignments << '\t' << \
		countQSAssignments << endl;
	cout << "Comparisons\t" << countSSComparisons << '\t' << \
		countISComparisons << '\t' << countHSComparisons << '\t' << \
		countQSComparisons << endl;
	/*clock_t t11 = clock();

	MERGE_SORT(a4, 0, SIZE_TEST - 1);

	clock_t t12 = clock();
	cout << "TIME MERGE SORT:\t" << t12 - t11 << "ms" << endl;
*/
//printIntArr(a, SIZE_TEST);
}
//---------------------------------------------------------
//				STACK AND QUEUE
template <typename T>
struct nodeS {
	T data;
	nodeS* pNext;
};
template <class T>
nodeS<T>* getNodeS(T key) {
	nodeS<T>* p = new nodeS<T>;
	if (p == NULL)
	{
		cout << "Leak memory\n";
		exit(0);
	}
	p->pNext = NULL;
	p->data = key;
	return p;
}
template <class T>
struct STACK {
	nodeS<T>* First;
	nodeS<T>* Last;
};
template <typename T>
void initStack(STACK<T>& S) {
	S.First = S.Last = NULL;
}
template <typename T>
bool addFirst(STACK<T>& S, T key) {
	nodeS<T>* p = getNodeS(key);
	if (!p) {
		cout << "Leak memory!\n";
		return false;
	}
	if (S.First == NULL) {
		S.First = S.Last = p;
		return true;
	}
	else {
		p->pNext = S.First;
		S.First = p;
	}
}
template <class T>
nodeS<T>* popFirst(STACK<T>& S) {
	nodeS<T>* p = S.First;
	S.First = S.First->pNext;
	delete S.First;
	S.First = NULL;
	return p;
}
template <typename T>
bool addLast(STACK<T>& S, T key) {
	nodeS* p = getNodeS(key);
	if (!p) {
		cout << "Leak memory!\n";
		return false;
	}
	if (S.First == NULL) {
		S.First = S.Last = p;
		return true;
	}
	else {
		S.Last->pNext = p;
		S.Last = p;
		return true;
	}
}
template <class T>
nodeS<T>* popLast(STACK<T>& S) {
	nodeS* p = S.First;
	for (; p->pNext->pNext; p = p->pNext);
	nodeS* q = S.Last;
	S.Last = p;
	S.Last->pNext = NULL;
	return q;
}
template <typename T>
void printStack(STACK<T> S) {
	nodeS<T>* p = S.First;
	for (; p; p = p->pNext)
		cout << p->data << '\t';
	cout << endl;
}

void TestStack() {
	STACK<int> S;
	initStack<int>(S);
	addFirst<int>(S, 4);
	addFirst<int>(S, 3);
	addFirst<int>(S, 2);
	addFirst<int>(S, 1);
	printStack(S);
}
#define ARRAY_SIZE 100
template <typename T>
struct stack
{
	int top;
	int size;
	//int cap;
	T* data;
};
template <class T>
void setS(stack<T>& s, int n)
{
	s.size = n;
	s.data = (T*)malloc(n * sizeof(T));
	s.top = 0;
}
template <typename T>
void delAllS(stack<T>& s)
{
	delete[]s.data;
	s.data = NULL;
	s.top = 0;
	s.size = 0;
}
template <class T>
bool isEmptyS(stack<T> s)
{
	return s.top == 0;
}
template <typename T>
bool isFullS(stack<T> s)
{
	return s.top == s.size;
}
template <class T>
void pushS(stack<T>& s, T k) {
	if (s.top == s.size)
	{
		s.size = 2 * s.size;
		//printf_s("%s\n", "stack is now full!");
		s.data = (T*)realloc(s.data, sizeof(T) * s.size);
		//delete s.data;?????? don't have to delete.
		//s.data = NULL;
		if (!s.data) {
			cout << "Failure to allocate memory\n";
			return;
		}
		s.data[s.top] = k;
		s.top++;
	}
}
template <class T>
T popS(stack<T>& s) {
	if (isEmptyS(s)) {
		printf_s("%s\n", "Stack is now empty!");
		exit(0);
	}
	return s.data[--s.top];
}
void makeS(stack<int>& s)
{
	srand(time(NULL));
	LOOP(i, s.size)
		pushS<int>(s, rand() % 20 - rand() % 20);
}
template <typename T>
void printS(stack<T> s)
{
	if (isEmptyS(s))
	{
		printf_s("%s\n", "stack is empty!");
		return;
	}
	LOOP(i, s.top)
		cout << s.data[i] << '\t';
	printf_s("\n");
}
template <typename T>
struct queue
{
	int size;
	int in;
	int out;
	T* data;
};
template <class T>
void initQ(queue<T>& q, int n)
{
	q.size = n;
	q.data = new T[n];
	q.in = q.out = 0;
}
template <typename T>
bool isEmptyQ(queue<T> q)
{
	return q.in == q.out;
}
template <typename T>
bool isFullQ(queue<T> q)
{
	return q.in == q.size;
}
template <class T>
void pushQ(queue<T>& q, T k)
{
	if (isFullQ<T>(q))
	{
		printf_s("%s\n", "Queue is full!");
		q.size *= 2;
		q.data = (T*)realloc(q.data, q.size * sizeof(T));
	}
	q.data[q.in++] = k;
}
template <typename T>
int popQ(queue<T>& q)
{
	if (isEmptyQ<T>(q))
	{
		printf_s("%s\n", "Queue is empty!");
		exit(0);
	}
	return q.data[q.out++];

}
template <class T>
void printQ(queue<T> q)
{
	if (isEmptyQ<T>(q))
	{
		printf_s("%s\n", "Queue is empty!");
		return;
	}
	for (int i = q.out; i < q.in; i++)
		printf_s("%d\t", q.data[i]);
	printf_s("\n");
}
template <typename T>
void makeQ(queue<T>& q)
{
	srand(time(0));
	LOOP(i, q.size)
	{
		pushQ<T>(q, rand() % 20 - rand() % 20);
	}
}
void TestMain()
{
	queue<int> q;
	initQ(q, 6);
	makeQ(q);
	printQ(q);
	//stack s;
	//setS(s, 9);
	//makeS(s);
	////delAllS(s);
	//
	//pushS(s, 1111);
	//printS(s);
	//cout << popS(s) << endl;
	//and queue
	//here..
}
//26 / 10 / 2016
template <class T>
struct nodeQ {
	T data;
	nodeQ* pNext;
};
template <class T>
struct QUEUE {
	nodeQ<T>* front;
	nodeQ<T>* rear;
};
template <typename T>
nodeQ<T>* getNodeQ(T key) {
	nodeQ<T>* p = new nodeQ<T>;
	if (!p) {
		cout << "Leak memory!\n";
		exit(0);
	}
	p->data = key;
	p->pNext = NULL;
	return p;
}
template <class T>
void initQueue(QUEUE<T>& Q) {
	Q.front = Q.rear = NULL;
}
template <typename T>
bool enQueue(QUEUE<T>& Q, T key) {
	nodeQ<T>* p = getNodeQ<T>(key);
	if (Q.front == NULL) {
		Q.front = Q.rear = p;
		return true;
	}
	else {
		Q.rear->pNext = p;
		Q.rear = p;
		return true;
	}
}
template <typename T>
bool isEmptyQ(QUEUE<T> Q) {
	return Q.front == NULL;
}
template <class T>
nodeQ<T>* deQueue(QUEUE<T>& Q) {
	if (isEmptyQ<T>(Q)) {
		cout << "Empty queue\n Please stop!\n";
		return NULL;
	}
	nodeQ<T> * p = Q.front;
	Q.front = p->pNext;
	return p;
}
template <typename T>
void printQueue(QUEUE<T> Q) {
	if (isEmptyQ(Q)) {
		cout<<"Empty queue\n";
			return;
	}
	nodeQ<T>* p = Q.front;
	for (; p; p = p->pNext)
		cout << p->data << '\t';
	cout << endl;
}

// CPP program for array implementation of queue
// A structure to represent a queue  
class Queue
{
public:
	int front, rear, size;
	unsigned capacity;
	int* array;
};

// function to create a queue of given capacity.  
// It initializes size of queue as 0  
Queue* createQueue(unsigned capacity)
{
	Queue* queue = new Queue();
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity - 1; // This is important, see the enqueue  
	queue->array = new int[(queue->capacity * sizeof(int))];
	return queue;
}

// Queue is full when size  
// becomes equal to the capacity  
int isFull(Queue* queue)
{
	return (queue->size == queue->capacity);
}

// Queue is empty when size is 0  
int isEmpty(Queue* queue)
{
	return (queue->size == 0);
}

// Function to add an item to the queue.  
// It changes rear and size  
void enqueue(Queue* queue, int item)
{
	if (isFull(queue))
		return;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
	cout << item << " enqueued to queue\n";
}

// Function to remove an item from queue.  
// It changes front and size  
int dequeue(Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = queue->size - 1;
	return item;
}

// Function to get front of queue  
int front(Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->front];
}

// Function to get rear of queue  
int rear(Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->rear];
}
template <class T>
void deleteQueue(QUEUE<T>& Q) {
	/*nodeQ<T>* p = Q.front;
	while (Q.front) {
		p = p->pNext;
		delete[] Q.front;
		Q.front=NULL;
		Q.front = p;
	}*/
	nodeQ<T>* p = Q.front;
	for (; p; ) {
		p = p->pNext;
		delete[] Q.front;
		Q.front = NULL;
		Q.front = p;
	}
	/*nodeQ<T>* p;
	while (Q.front) {
		p = Q.front;
		Q.front = Q.front->pNext;
		delete[] p;
		p = NULL;
	}*/
}
// Driver code 
void TestQueue2()
{
	Queue* queue = createQueue(1000);
	enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);
	enqueue(queue, 40);
	cout << dequeue(queue) << " dequeued from queue\n";
	cout << "Front item is " << front(queue) << endl;
	cout << "Rear item is " << rear(queue) << endl;
}
void TestQueue() {
	QUEUE<int> Q;
	initQueue(Q);
	enQueue(Q, 2);
	printQueue<int>(Q);
	deleteQueue(Q);
	printQueue<int>(Q);
}
// Extra exercise
void createMatrix(vector<int> a) {

}