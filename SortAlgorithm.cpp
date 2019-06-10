
#include <iostream>
#include <time.h>
#include <Windows.h>
#define LOOP(i, n) for (int i = 0; i < n; i++)
#define SIZE_TEST 211
using namespace std;

// _____________________________________________________
//|														|
//|			DATA STRUCTURE AND ALGORITHMS				|
//|_____________________________________________________|
// 3. Sort
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
int main(int argc, char* const argv[]) {
	TestSort();
	system("pause");
	return 0;
}