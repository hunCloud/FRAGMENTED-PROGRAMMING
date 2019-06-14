#include <iostream>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

using namespace std;
#define LH -1
#define EH 0
#define RH 1
#define FAIL -1
#define EXISTENCE 0
#define SUCCESS 1

#define TRUE 1
#define FALSE 0
#define M 100
#define LOOP(i, n) for (int i = 0; i < n; i++)


template <class _Val>
struct NODE {
	_Val key;
	NODE<_Val>* pLeft;
	NODE<_Val>* pRight;
};

template <class _Val>
void initTree(NODE<_Val>*& T) {
	T = NULL;
}
template <class _Val>
NODE<_Val>* searchNode(NODE<_Val>* T, _Val data) {
	if (T) {
		if (T->key == data)
			return T;
		else if (T->key > data)
			return searchNode(T->pLeft, data);
		else
			return searchNode(T->pRight, data);
		// must return value
	}
	return NULL;
}

template <class _Val>
int insertNode(NODE<_Val>*& T, _Val data) {
	if (T != NULL) {
		if (T->key == data)
			return EXISTENCE;
		else if (T->key > data)
			return insertNode(T->pLeft, data);
		else
			return insertNode(T->pRight, data);
	}
	T = (NODE<_Val>*)malloc(sizeof(NODE<_Val>));
	if (T == NULL) {
		cout << "Leak memory\n";
		return FAIL;
	}
	T->key = data;
	T->pLeft = T->pRight = NULL;
	return SUCCESS;
}
template <class _Val>
void searchStandFor(NODE<_Val>*& p, NODE<_Val>*& q) {
	if (q->pLeft)
		searchStandFor(p, q->pLeft);
	else {
		p->key = q->key;
		p = q;
		q = q->pRight;
	}
}
template <class _Val>
int deleteNode(NODE<_Val>*& T, _Val data) {
	if (T == NULL) {
		cout << "Empty NODE<_Val>*\n";
		return 0;
	}
	else if (T->key > data)
		return deleteNode(T->pLeft, data);
	else if (T->key < data)
		return deleteNode(T->pRight, data);
	else {
		NODE<_Val>* p = T;
		if (T->pLeft == NULL)
			T = T->pRight;
		else if (T->pRight == NULL)
			T = T->pLeft;
		else {
			NODE<_Val>* q = T->pRight;
			searchStandFor(p, q);
		}
		delete p;
	}
}
template <class _Val>
void removeTree(NODE<_Val>*& T) {
	if (!T) {
		removeTree(T->pLeft);
		removeTree(T->pRight);
		delete T;
	}
}
template <class _Val>
void printTree(NODE<_Val>* T) {
	if (T != NULL) {
		printTree(T->pLeft);
		cout << T->key << "\t";
		printTree(T->pRight);
	}
}
int const VALUE_RANDOM = 22;
int const SIZE_TREE = 6;
int random(int val) {
	srand(time(NULL));
	return rand() % val;
}
int main(int argc, char* const argv[]) {
	NODE<int>* T;
	initTree(T);
	LOOP(i, SIZE_TREE)
	{
		insertNode(T, random(VALUE_RANDOM) + i);
	}
	insertNode(T, 122);
	printTree(T);
	NODE<int>* p = searchNode(T, 122);
	if (p)
		cout << "SDD=  " << p->key << endl;

	system("pause");
	return 0;
}