// Checks the number of nodes on a BST that fall on a range

#include <iostream>
using namespace std;

int numberOfNodesInRange = 0;
int beginRange = 5;
int endRange   = 45;

struct Node {
  int data;
  Node* left;
  Node* right;

};

void preorder(Node* t) {

  if(t == NULL) return;

  if(t->data >= beginRange && t->data <= endRange){
    numberOfNodesInRange++;
    preorder(t->left);
    preorder(t->right);
  } else if(t->data < beginRange) { 
    preorder(t->right);
  } else if(t->data > endRange) {
    preorder(t->left);
  }

}

int main () {

  Node* root = new Node();
  Node* n1 = new Node();
  Node* n2 = new Node();
  Node* n3 = new Node();
  Node* n4 = new Node();
  Node* n5 = new Node();

  n5->data = 100;
  n5->left = n5->right = NULL;

  n4->data = 40;
  n4->left = n4->right = NULL;
  
  n3->data = 1;
  n3->left = n3->right = NULL;

  n2->data = 50;
  n2->left = n4;
  n2->right = n5;

  n1->data = 5;
  n1->left = n3;
  n1->right = NULL;

  root->data = 10;
  root->left = n1;
  root->right = n2;

  preorder(root);
  
  cout << numberOfNodesInRange << endl;

  return 0;

}
