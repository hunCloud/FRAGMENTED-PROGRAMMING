
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
void DemoCalTime() {
	clock_t t1 = clock();
	Sleep(2222);
	float dur = clock() - t1;
	cout << dur << endl;
}
int main(int argc, char* const argv[]) {
	cout << "Sleep 2222 ms\n";
	DemoCalTime();
	system("pause");
	return 0;
}