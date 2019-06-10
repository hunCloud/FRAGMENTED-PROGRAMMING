
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
int main(int argc, char* const argv[]) {
	TestStack();
	system("pause");
	return 0;
}