
#include <iostream>
#include <time.h>

#define LOOP(i, n) for (int i = 0; i < n; i++)
using namespace std;

// _____________________________________________________
//|														|
//|			DATA STRUCTURE AND ALGORITHMS				|
//|_____________________________________________________|
//				STACK AND QUEUE
template <typename T>
struct QUEUE
{
	int size;
	int front;
	int rear;
	T* data;
};
template <class T>
void initQ(QUEUE<T>& q, int n)
{
	q.size = n;
	q.data = new T[n];
	q.front = q.rear = 0;
}
template <typename T>
bool isEmptyQ(QUEUE<T> q)
{
	return q.front == q.rear;
}
template <typename T>
bool isFullQ(QUEUE<T> q)
{
	return q.front == q.size;
}
template <class T>
void pushQ(QUEUE<T>& q, T k)
{
	if (isFullQ<T>(q))
	{
		printf_s("%s\n", "QUEUE is full!");
		q.size *= 2;
		q.data = (T*)realloc(q.data, q.size * sizeof(T));
	}
	q.data[q.front++] = k;
}
template <typename T>
int popQ(QUEUE<T>& q)
{
	if (isEmptyQ<T>(q))
	{
		printf_s("%s\n", "QUEUE is empty!");
		exit(0);
	}
	return q.data[q.rear++];

}
template <class T>
void printQ(QUEUE<T> q)
{
	if (isEmptyQ<T>(q))
	{
		printf_s("%s\n", "QUEUE is empty!");
		return;
	}
	for (int i = q.rear; i < q.front; i++)
		printf_s("%d\t", q.data[i]);
	printf_s("\n");
}
template <typename T>
void makeQ(QUEUE<T>& q)
{
	srand(time(0));
	LOOP(i, q.size)
	{
		pushQ<T>(q, rand() % 20 - rand() % 20);
	}
}
void TestQueue()
{
	QUEUE<int> q;
	initQ(q, 6);
	makeQ(q);
	printQ(q);
	cout << popQ(q) << endl;
	cout << popQ(q) << endl;
	printQ(q);
}
//26 / 10 / 2016
int main(int argc, char* const argv[]) {
	TestQueue();
	system("pause");
	return 0;
}