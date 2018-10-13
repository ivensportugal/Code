// Returns the sum of data from every path from root to leaf.

#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

int sum = 0;

void preorder(Node* t, int currentSum) {
  
  // leaf
  if(t->left  == NULL && t->right == NULL) {sum += (currentSum*10 + t->data); cout << "add" << currentSum*10 + t-> data << endl;}
  if(t->left  != NULL) preorder(t->left , currentSum*10 + t->data);
  if(t->right != NULL) preorder(t->right, currentSum*10 + t->data);

}

int main () {

  // Creating Nodes
  Node* root = new Node();
  Node* n1 = new Node();
  Node* n2 = new Node();
  Node* n3 = new Node();
  Node* n4 = new Node();
  Node* n5 = new Node();
  Node* n6 = new Node();
  Node* n7 = new Node();

  n7->data  = 4;
  n7->left  = NULL;
  n7->right = NULL;

  n6->data  = 5;
  n6->left  = NULL;
  n6->right = n7;
 
  n5->data  = 4;
  n5->left  = NULL;
  n5->right = NULL;
 
  n4->data  = 7;
  n4->left  = NULL;
  n4->right = NULL;

  n3->data  = 5;
  n3->left  = n4;
  n3->right = n5;
  
  n2->data  = 2;
  n2->left  = NULL;
  n2->right = NULL;

  n1->data  = 3;
  n1->left  = n2;
  n1->right = n3;

  root->data  = 6;
  root->left  = n1;
  root->right = n6;


  // Traverse the tree
  preorder(root, 0);

  // Output the result
  cout << sum << endl;


}
