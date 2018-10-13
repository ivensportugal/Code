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

tNode* insertNode(tNode* n, int data) {
  if(n == NULL) return createNode(data);
  if(data < n->data) n->left = insertNode(n->left, data);
  else if(data > n->data) n->right = insertNode(n->right, data);
  return n;
}

int main() {
  tNode* root = createNode(50);
  insertNode(root, 4);
  insertNode(root, 2);
  insertNode(root, 15);
  insertNode(root, 85);
  insertNode(root, 65);
  insertNode(root, 8);
  insertNode(root, 33);

  inorder(root);
  cout << endl;
}
