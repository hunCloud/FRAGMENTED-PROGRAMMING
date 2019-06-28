#include <iostream>
#define LH -1
#define EH 0
#define RH 1
using namespace std;

template <typename _Val>
struct AVLNode {
	_Val key;
	int balFactor;
	AVLNode* pLeft;
	AVLNode* pRight;
};
// rotate Left-Left
template <typename _Val>
void rotateLL(AVLNode<_Val>*& T) {
	AVLNode<_Val>* T1 = T->pLeft;
	T->pLeft = T1->pRight;
	T1->pRight = T;
	switch (T1->balFactor)
	{
	case LH: T->balFactor = EH;
		T1->balFactor = EH;
		break;
	case EH: T->balFactor = LH;
		T1->balFactor = RH;
		break;
	default:
		break;
	}
	T = T1;
}
template <typename _Val>
void rotateRR(AVLNode<_Val>*& T) {
	AVLNode<_Val>* T1 = T->pRight;
	T->pRight = T1->pLeft;
	T1->pLeft = T;
	switch (T1->balFactor)
	{
	case RH: T1->balFactor = EH;
		T->balFactor = EH;
	case EH: T1->balFactor = LH;
		T->balFactor = RH;
	default:
		break;
	}
}
template <typename _Val>
void rotateLR(AVLNode<_Val>*& T) {
	AVLNode<_Val>* T1 = T->pLeft;
	AVLNode<_Val>* T2 = T1->pRight;
	T->pLeft = T2->pRight;
	T1->pRight = T2->pLeft;
	T2->pLeft = T1;
	T2->pRight = T;
	switch (T2->balFactor)
	{
	case LH: T->balFactor = RH;
		T1->balFactor = EH;
		break;
	case EH: T->balFactor = EH;
		T1->balFactor = EH;
		break;
	case RH: T->balFactor = EH;
		T1->balFactor = LH;
		break;
	default:
		break;
	}
	T2->balFactor = EH;
	T = T2;
}
template <typename _Val>
void rotateRL(AVLNode<_Val>*& T) {
	AVLNode<_Val>* T1 = T->pRight;
	AVLNode<_Val>* T2 = T1->pLeft;
	T->pRight = T2->pLeft;
	T1->pLeft = T2->pRight;
	T2->pLeft = T;
	T2->pRight = T1;
	switch (T2->balFactor)
	{
	case LH: T->balFactor = EH;
		T1->balFactor = RH;
		break;
	case EH: T->balFactor = T1->balFactor = EH;
		break;
	case RH: T->balFactor = LH;
		T1->balFactor = EH;
	default:
		break;
	}
	T2->balFactor = EH;
	T = T2;
}
template <typename _Val>
int balanceLeft(AVLNode<_Val>*& T) {
	switch (T->pLeft->balFactor)
	{
	case LH: rotateLL(T); return 2;
	case EH: rotateLL(T); return 1;
	case RH: rotateLR(T); return 2;
	default:
		break;
	}
	return 0;
}
template <typename _Val>
int balanceRight(AVLNode<_Val>*& T) {
	switch (T->pRight->balFactor) {
	case LH: rotateRL(T); return 2;
	case EH: rotateRR(T); return 1;
	case RH: rotateRR(T); return 2;
	}
	return 0;
}
template <typename _Val>
int insertNode(AVLNode<_Val>*& T, _Val data) {
	int res;
	if (T != nullptr) {
		if (T->key == data)
			return 0;
		else if (T->key > data) {
			res = insertNode(T->pLeft, data);
			if (res < 2)
				return res;
			switch (T->balFactor)
			{
			case RH: T->balFactor = EH;
				return 1;
			case EH: T->balFactor = LH;
				return 2;
			case LH: balanceLeft(T);
				return 1;
			default:
				break;
			}
		}
		else {
			res = insertNode(T->pRight, data);
			if (res < 2)
				return res;
			switch (T->balFactor)
			{
			case LH: T->balFactor = EH;
				return 1;
			case EH: T->balFactor = RH;
				return 2;
			case RH: balanceRight(T);
				return 1;
			default:
				break;
			}
		}
	}
	T = new AVLNode<_Val>;
	if (T == nullptr)
		return -1;
	T->key = data;
	T->balFactor = EH;
	T->pLeft = T->pRight = nullptr;
	return 2;
}
template <typename _Val>
void printAVL(AVLNode<_Val>* T) {
	if (T != nullptr) {
		cout << T->key << '\t';
		printAVL(T->pLeft);
		printAVL(T->pRight);
	}
}
template <typename _Val>
int searchStandFor(AVLNode<_Val>*& p, AVLNode<_Val>*& q) {
	int res;
	if (q->pLeft != nullptr) {
		res = searchStandFor(p, q->pLeft);
		if (res < 2)
			return res;
		switch (q->balFactor)
		{
		case LH: q->balFactor = EH;
			return 2;
		case EH: q->balFactor = RH;
			return 1;
		case RH: return balanceRight(p);
		default:
			break;
		}
	}
	else {
		p->key = q->key;
		p = q;
		q = q->pRight;
		return 2;
	}
}
template <typename _Val>
int deleteNode(AVLNode<_Val>*& T, _Val data) {
	int res;
	if (T == NULL)
		return 0;// fail
	if (T->key > data) {
		res = deleteNode(T->pLeft, data);
		if (res < 2)
			return res;
		switch (T->balFactor) {
		case LH: T->balFactor = EH;
			return 2;// high of tree is changed
		case EH: T->balFactor = RH;
			return 1;
		case RH: return balanceRight(T);
		}
	}
	else if (T->key < data) {
		res = deleteNode(T->pRight, data);
		if (res < 2)
			return res;
		switch (T->balFactor)
		{
		case RH: T->balFactor = EH;
			return 2;
		case EH: T->balFactor = LH;
			return 1;
		case LH: return balanceLeft(T);
		default:
			break;
		}
	}
	else {
		AVLNode<_Val>* p = T;
		if (T->pLeft == nullptr) {
			T = T->pRight;
			res = 2;
		}
		else if (T->pRight == nullptr) {
			T = T->pLeft;
			res = 2;
		}
		else {
			res = searchStandFor(p, T->pRight);
			if (res < 2)
				return res;
			switch (T->balFactor)
			{
			case RH: T->balFactor = EH;
				return 2;
			case EH: T->balFactor = LH;
				return 1;
			case LH: return balanceLeft(T);
			default:
				break;
			}
		}
		delete p;
		return res;
	}
}
int main(int argc, char* const argv[]) {
	AVLNode<int>* T;
	T = nullptr;
	int i = 1;

	insertNode(T, 22);
	insertNode(T, i + 2);
	insertNode(T, 14);
	while (i < 14) {
		insertNode(T, i);
		i++;
	}
	printAVL(T);
	deleteNode(T, 14);
	cout << '\n';
	printAVL(T);
	//insertNode(T, i);
	system("pause");
	return 0;
}