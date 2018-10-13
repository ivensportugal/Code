/* A BSTree for search */

#include <iostream>
using namespace std;

// A node strucutre for the three
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

// Insert nodes
tNode* insert(tNode* n, int data) {
  if(n == NULL) return createNode(data);
  if(data < n->data) n->left = insert(n->left, data);
  else n->right = insert(n->right, data);
  return n;
}

// Search nodes
tNode* search(tNode* n, int data) {
  if(n == NULL || n->data == data) return n;
  if(data < n->data) return search(n->left, data);
  return search(n->right, data);
}

// In order traversal
void inorder(tNode* n) {
  if(n == NULL) return;
  inorder(n->left);
  cout << n->data << " ";
  inorder(n->right);
}

// Driver Program
int main() {
  tNode* root = createNode(50);
  insert(root, 10);
  insert(root, 90);
  insert(root, 40);
  insert(root, 60);
  insert(root, 20);
  inorder(root);
  cout << endl;

  tNode* test = search(root, 60);
  cout << test->data << endl;

  return 0;

}
