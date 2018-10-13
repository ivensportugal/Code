// Insertion on a binary tree

#include <iostream>
#include <queue>
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

void insert(tNode* root, int data) {
  queue<tNode*> q;
  q.push(root);

  // Traversal
  while(!q.empty()) {

    root = q.front();
    q.pop();

    if(!root->left) {
      root->left = createNode(data);
      break;      
    } else
      q.push(root->left);

    if(!root->right) {
      root->right = createNode(data);
    } else
      q.push(root->right);
  }
}


void inorder(tNode* n) {
  if(n == NULL) return;
  inorder(n->left);
  cout << n->data << " ";
  inorder(n->right);
}

int main() {

  tNode* root = createNode(10);
  root->left = createNode(11);
  root->left->left = createNode(7);
  root->right = createNode(9);
  root->right->left = createNode(15);
  root->right->right = createNode(8);

  cout << "Inorder traversal before insertion:";
  inorder(root);

  int data = 12;
  insert(root, data);

  cout << endl;
  cout << "Inorder traversal after insertion:";
  inorder(root);
  cout << endl;
}
