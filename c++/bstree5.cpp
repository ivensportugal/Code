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
  if(n == NULL) return n;
  if(data < n->data) n->left = insert(n->left, data);
  if(data > n->data) n->right = insert(n->right, data);
  return n;
}


tNode* findMinNode(tNode* n) {
  tNode* current = n;
  while(current->left != NULL)
    current = current->left;
  return current;
}


tNode* removeNode(tNode* n, int data) {
  if(n == NULL) return n;
  if(data < n->data) n->left = removeNode(n->left, data);
  else if(data > n->data) n->right = removeNode(n->right, data);
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

    tNode* temp = findMinNode(n->right);
    n->data = temp->data;
    return removeNode(n->right, temp->data);
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
  tNode* root = createNode(50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  removeNode(root, 20);
  removeNode(root, 30);
  removeNode(root, 50);

  inorder(root);
  cout << endl;
}
