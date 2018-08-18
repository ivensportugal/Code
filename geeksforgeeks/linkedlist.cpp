#include <iostream>
using namespace std;

struct lNode {
	int data;
	lNode* next;
};

void append(lNode** root, int data) {
	
	lNode* newnode = new lNode;
	newnode->data = data;
	newnode->next = NULL;

	if(*root == NULL) {
		*root = newnode;
		return;
	}

	lNode* last = *root;

	while(last->next != NULL)
		last = last->next;

	last->next = newnode;

	return;
}

void print(lNode* root) {
	while(root != NULL) {
		cout << root->data << " - ";
		root = root->next;
	}
	cout << endl;
}

int main () {

	lNode* list = NULL;
	append(&list, 00);
	append(&list, 10);
	append(&list, 20);

	print(list);

	return 0;
}