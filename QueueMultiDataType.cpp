
#include <iostream>
#include <time.h>

#define LOOP(i, n) for (int i = 0; i < n; i++)
using namespace std;

// _____________________________________________________
//|														|
//|			DATA STRUCTURE AND ALGORITHMS				|
//|_____________________________________________________|
//				STACK AND QUEUE
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
	nodeQ<T>* p = Q.front;
	Q.front = p->pNext;
	return p;
}
template <typename T>
void printQueue(QUEUE<T> Q) {
	if (isEmptyQ(Q)) {
		cout << "Empty queue\n";
		return;
	}
	nodeQ<T>* p = Q.front;
	for (; p; p = p->pNext)
		cout << p->data << '\t';
	cout << endl;
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
void TestQueue() {
	QUEUE<int> Q;
	initQueue(Q);
	enQueue(Q, 2);
	enQueue(Q, 9);
	enQueue(Q, 21);
	cout << "deQueue once: " << deQueue(Q)->data << endl;
	printQueue<int>(Q);
	deleteQueue(Q);
	printQueue<int>(Q);
}
int main(int argc, char* const argv[]) {
	TestQueue();
	system("pause");
	return 0;
}