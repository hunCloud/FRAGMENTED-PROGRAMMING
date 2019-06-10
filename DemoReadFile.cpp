
#include <iostream>
#include <time.h>
#define LOOP(i, n) for (int i = 0; i < n; i++)
using namespace std;

// _____________________________________________________
//|														|
//|			DATA STRUCTURE AND ALGORITHMS				|
//|_____________________________________________________|
// 1. Review
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
int main(int argc, char* const argv[]) {
	TestReadFile();
	system("pause");
	return 0;
}