#include <iostream>
#include <stdlib.h>

#define FAIL -1
#define EXISTENCE 0
#define SUCCESS 1

#define TRUE 1
#define FALSE 0
using namespace std;

#define TRASH 0
template <typename ty>
struct NODE {
	ty key;
	NODE<ty>* pLeft;
	NODE<ty>* pRight;
};
template <typename ty>
NODE<ty>* newNode(ty item) {
	NODE<ty>* temp = (NODE<ty>*)malloc(sizeof(NODE<ty>));
	temp->key = item;
	temp->pLeft = temp->pRight = NULL;
	if (!temp)
		cout << "Leak memory\n";
	return temp;
}
template <typename ty>
void inorder(NODE<ty>* root) {
	if (root) {
		inorder(root->pLeft);
		cout << root->key << '\t';
		inorder(root->pRight);
	}
}
template <typename ty>
int insert(NODE<ty>*& root, ty _Val) {
	NODE<ty>* tem = newNode(_Val);
	if (!tem)
		return FAIL;

	if (root == NULL) {
		root = tem;
		return SUCCESS;
	}
	if (root->key == _Val)
		return EXISTENCE;

	else if (_Val < root->key)
		insert(root->pLeft, _Val);

	else if (_Val > root->key)
		insert(root->pRight, _Val);

}
void TestBTS() {
	NODE<int>* T = NULL;
	insert(T, 22);
	insert(T, 2);
	insert(T, -12);
	insert(T, 0);
	insert(T, 9);
	inorder(T);
}
int main(int argc, char* const argv[]) {
	TestBTS();
	system("pause");
	return 0;
}