#include <iostream>
#include <queue>
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
  else if(data > n->data) n->right = insertNode(n->right, data);
  return n;
}

tNode* findMinNode(tNode* n) {
  tNode* current = n;
  while(current->left != NULL)
    current = current->left;
  return current;
}

tNode* deleteNode(tNode* n, int data) {
  if(n == NULL) return n;
  if(data < n->data) n->left = deleteNode(n->left, data);
  else if(data > n->data) n->right = deleteNode(n->right, data);
  else {
    if(n->left == NULL) {
      tNode* temp = n->right;
      delete n;
      return temp;
    }
    else if(n->right == NULL) {
      tNode* temp = n->left;
      delete n;
      return temp;
    }
    else {
      tNode* temp = findMinNode(n->right);
      n->data = temp->data;
      n->right = deleteNode(n->right, temp->data);
    }
  }
  return n;
}

void inorder(tNode* n) {
  if(n == NULL) return;
  inorder(n->left);
  cout << n->data << " ";
  inorder(n->right);
}

int main() {
  tNode* root = createNode(10);
  root = insertNode(root, 3);
  root = insertNode(root, 8);
  root = insertNode(root, 4);
  root = insertNode(root, 9);
  root = insertNode(root, 1);
  root = insertNode(root, 7);
  inorder(root);
  cout << endl;
  root = deleteNode(root, 8);
  root = deleteNode(root, 7);
  root = deleteNode(root, 10);
  root = deleteNode(root, 3);
  root = deleteNode(root, 4);
  root = deleteNode(root, 9);
  inorder(root);
  cout << endl;

  return 0;
}
