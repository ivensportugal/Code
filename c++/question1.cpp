// To print the nodes of two trees in order (limited space)

#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

void inorder(Node* tree) {
  if(tree->left  != NULL) inorder(tree->left );
  cout << tree->data << " ";
  if(tree->right != NULL) inorder(tree->right);
}

void print(Node* tree1, Node* tree2) {

  if(tree1->left == NULL && tree1->right == NULL &&
     tree2->left == NULL && tree2->right == NULL) {
       if(tree1->data < tree2->data) cout << tree1->data << " ";
       else cout << tree2->data << " ";

  
}

int main () {

  Node n1 = {1, NULL, NULL};
  Node n5 = {5, NULL, NULL};
  Node n3 = {3, &n1, &n5};
  
  Node n2 = {2, NULL, NULL};
  Node n6 = {6, NULL, NULL};
  Node n4 = {4, &n2, &n6};

  inorder(&n3);
  inorder(&n4);

  return 0;
}
