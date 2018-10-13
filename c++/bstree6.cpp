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

tNode* insertNode(tNode* n, int data) {
  if(n == NULL) return createNode(data);

  if(data < n->data) n->left = insertNode(n->left, data);
  else if (data > n->data) n->right = insertNode(n->right, data);

  return n;
}

void inorder(tNode* n) {
  if(n == NULL) return;
  inorder(n->left);
  cout << n->data << " ";
  inorder(n->right);
}

int main() {
  tNode* root = createNode(40);
  insertNode(root, 14);
  insertNode(root, 10);
  insertNode(root, 16);
  insertNode(root, 50);
  insertNode(root, 100);
  insertNode(root, 45);
  insertNode(root, 44);

  inorder(root);
  cout << endl;

  return 0;
}
