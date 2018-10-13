#include<iostream>
#include<queue>
using namespace std;


struct tNode {
  int data;
  tNode* left;
  tNode* right;
};

tNode* createNode(int data) {
  tNode* newNode = new tNode;
  newNode->data  = data;
  newNode->left  = NULL;
  newNode->right = NULL;
  return newNode;
}

tNode* insertNode(tNode* n, int data) {
  if(n == NULL) return createNode(data);
  if(data < n->data) n->left = insertNode(n->left, data);
  else if (data > n->data) n->right = insertNode(n->right, data);
  else if (data == n->data) { cout << "notify user" << endl;}
  else { cout << "something very bad happened!" << endl;}
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
  insertNode(root, 10);
  insertNode(root, 20);
  insertNode(root, 30);
  insertNode(root, 40);
  insertNode(root, 60);
  insertNode(root, 70);
  insertNode(root, 80);
  insertNode(root, 90);

  inorder(root);
  cout << endl;

  return 0;
}
