// The implementation of a tree

#include <iostream>
using namespace std;

// The nodes of a tree
struct tNode {
  int data;
  tNode* left;
  tNode* right;
};


// Crates nodes for the tree
tNode* createNode(int data) {
  tNode* n = new tNode;
  n->data = data;
  n->left  = NULL;
  n->right = NULL;

  return n;
}


// Traverses the tree and print nodes in order
void inorder(tNode* n) {
  if(n != NULL) {
    inorder(n->left);
    cout << n->data << " ";
    inorder(n->right);
  }
}


int main() {

  tNode* root = createNode(10);
  root->left  = createNode(5);
  root->right = createNode(15);

  inorder(root);

  return 0;

}
