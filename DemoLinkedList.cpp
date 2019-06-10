
#include <iostream>
#define LOOP(i, n) for (int i = 0; i < n; i++)
using namespace std;

// _____________________________________________________
//|														|
//|			DATA STRUCTURE AND ALGORITHMS				|
//|_____________________________________________________|
// 1. Review
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
int main(int argc, char* const argv[]) {
	TestLinkedList();
	system("pause");
	return 0;
}