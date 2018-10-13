/* a binary search tree */

#include<iostream>
using namespace std;


/* the node structure */
struct tNode {
  int data;
  tNode* left;
  tNode* right;
};

// A helper function to create nodes
tNode* createNode(int data) {
  tNode* newNode = new tNode;
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// Traverse the tree in order
void inorder(tNode* n) {
  if(n == NULL) return;
  inorder(n->left);
  cout << n->data << " ";
  inorder(n->right);
}

// Insert a new node in the tree
tNode* insert(tNode* n, int data) {
  if(n == NULL) return createNode(data);

  if(data < n->data) n->left  = insert(n->left , data);
  if(data > n->data) n->right = insert(n->right, data);

  return n;
}

// Driver program
int main() {

  tNode* root = createNode(20);
  insert(root, 10);
  insert(root,  5);
  insert(root, 15);
  insert(root, 30);
  insert(root, 11);

  inorder(root);
  cout << endl;

  return 0;
}
