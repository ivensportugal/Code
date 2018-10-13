#include <iostream>
using namespace std;

struct tNode {
	int data;
	tNode* left;
	tNode* right;
};

void in_order(tNode* node) {
	if(node == NULL) return;
	in_order(node->left);
	cout << node->data << " ";
	in_order(node->right);
}

int main() {
	
	tNode* root = new tNode;
	root->data = 3;
	root->left = new tNode;
	root->left->data = 1;
	root->right = new tNode;
	root->right->data = 4;
	root->left->left = new tNode;
	root->left->left->data = 0;
	root->left->left->left = NULL;
	root->left->left->right = NULL;
	root->left->right = new tNode;
	root->left->right->data = 2;
	root->left->right->left = NULL;
	root->left->right->right = NULL;
	root->right->left = new tNode;
	root->right->left->data = 5;
	root->right->left->left = NULL;
	root->right->left->right = NULL;
	root->right->right = new tNode;
	root->right->right->data = 6;
	root->right->right->left = NULL;
	root->right->right->right = NULL;

	in_order(root);

	return 0;

}
