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

tNode* insert(tNode* n, int data) {
  if(n == NULL) return createNode(data);
  if(data < n->data) n->left = insert(n->left, data);
  else if(data > n->data) n->right = insert(n->right, data);
  return n;
}

//tNode* search(tNode* n, int data) {}


void inorder(tNode* n) {
  if(n == NULL) return;
  inorder(n->left);
  cout << n->data << " ";
  inorder(n->right);
}

tNode* minNode(tNode* n) {
  tNode* current = n;
  while(n->left != NULL)
    current = current->left;
  return current;
}

tNode* deleteNode(tNode* n, int data) {
  if(n == NULL) return NULL;
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
      tNode* temp = minNode(n->right);
      n->data = temp->data;
      return deleteNode(n->right, temp->data);
    }
  }
  return n;
}

int main() {
  tNode* root = createNode(50);
  root = insert(root, 50);
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 70);
  root = insert(root, 80);

  inorder(root);
  
  return 0;
}

