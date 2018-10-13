#include <iostream>
using namespace std;

struct tNode {
  int data;
  tNode* left;
  tNode* right;
};

tNode* createNode(int data) {
  tNode* newNode = new tNode;
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

tNode* insert(tNode* n, int data) {
  if(n == NULL) return createNode(data);
  if(data < n->data) n->left = insert(n->left, data);
  if(data > n->data) n->right = insert(n->right, data);
  return n;
}

tNode* search(tNode* n, int data) {
  if(n == NULL || n->data == data) return n;
  if(data < n->data) return search(n->left, data);
  if(data > n->data) return search(n->right, data);
  return n;
}

void inorder(tNode* n) {
  if(n == NULL) return;
  inorder(n->left);
  cout << n->data << " ";
  inorder(n->right);
}

int main() {
  tNode* root = createNode(30);
  insert(root, 20);
  insert(root, 10);
  insert(root, 0);
  insert(root, -10);
  insert(root, 90);
  insert(root, 80);
  insert(root, 70);
  insert(root, 91);
  insert(root, 60);
  insert(root, 50);
  insert(root, 40);
  insert(root, 45);

  inorder(root);
  cout << endl;

  return 0;
}
