
#include <iostream>
#include <time.h>

#define LOOP(i, n) for (int i = 0; i < n; i++)
using namespace std;

// _____________________________________________________
//|														|
//|			DATA STRUCTURE AND ALGORITHMS				|
//|_____________________________________________________|
//				STACK AND QUEUE
#define ARRAY_SIZE 100
template <typename T>
struct STACK
{
	int top;
	int size;
	T* data;
};
template <class T>
void setS(STACK<T>& s, int n)
{
	s.size = n;
	s.data = (T*)malloc(s.size * sizeof(T));
	s.top = 0;
}
template <typename T>
void delAllS(STACK<T>& s)
{
	delete[]s.data;
	s.data = NULL;
	s.top = 0;
	s.size = 0;
}
template <class T>
bool isEmptyS(STACK<T> s)
{
	return s.top == 0;
}
template <typename T>
bool isFullS(STACK<T> s)
{
	return s.top == s.size;
}
template <class T>
bool pushS(STACK<T>& s, T k) {
	if (s.top == s.size) {
		s.size = 2 * s.size;
		//printf_s("%s\n", "STACK is now full!");
		s.data = (T*)realloc(s.data, sizeof(T) * s.size);
		//delete s.data;?????? don't have to delete.
		//s.data = NULL;
	}
		if (!s.data) {
			cout << "Failure to allocate memory\n";
			return false;
		}
		s.data[s.top] = k;
		s.top++;
		return true;
}
template <class T>
T popS(STACK<T>& s) {
	if (isEmptyS(s)) {
		printf_s("%s\n", "STACK is now empty!");
		exit(0);
	}
	return s.data[--s.top];
}
void makeS(STACK<int>& s)
{
	srand(time(NULL));
	LOOP(i, s.size)
		pushS<int>(s, rand() % 20 - rand() % 20);
}
template <typename T>
void printS(STACK<T> s)
{
	if (isEmptyS(s))
	{
		printf_s("%s\n", "STACK is empty!");
		return;
	}
	LOOP(i, s.top)
		cout << (s.data[i]) << '\t';
	printf_s("\n");
}
int const SIZE_STACK = 5;
int main(int argc, char* const argv[]) {
	STACK<int> s;
	setS(s, SIZE_STACK);
	makeS(s);
	printS(s);
	cout << popS(s)<<endl;
	printS(s);
	system("pause");
	return 0;
}