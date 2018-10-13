#include<iostream>
using namespace std;

struct tNode {
  int data;
  tNode* left;
  tNode* right;
};

tNode* createNode(int data) {
  tNode* n = new tNode;
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;
}

void inorder(tNode* n) {
  if(n == NULL) return;
  inorder(n->left);
  cout << n->data << " ";
  inorder(n->right);
}

tNode* insert(tNode* n, int data) {
  if(n == NULL) return createNode(data);

  if(data < n->data) n->left = insert(n->left, data);
  if(data > n->data) n->right = insert(n->right, data);

  return n;
}

int main() {
  tNode* root = createNode(20);
  root = insert(root, 10);
  root = insert(root,  5);
  root = insert(root, 15);
  root = insert(root, 30);
  root = insert(root, 11);

  inorder(root);
  cout << endl;

  return 0;
}

