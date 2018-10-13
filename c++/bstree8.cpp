#include <iostream>
using namespace std;

struct tNode {
  int data;
  tNode* left;
  tNode* right;
};

tNode* createNode(int data){
  tNode* n = new tNode;
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;
}

void inorder(tNode* n) {
  if(n == NULL) return;
  inorder(n->left);
  cout << n->data << " ";
  inorder(n->right);
}

tNode* insertNode(tNode* n, int data) {
  if(n == NULL) return createNode(data);
  if(data < n->data) n->left = insertNode(n->left, data);
  if(data > n->data) n->right = insertNode(n->right, data);
  return n;
}

tNode* minValueNode(tNode* n) {
  tNode* current = n;
  while(current->left != NULL)
    current = current->left;
  return current;
}

tNode* deleteNode(tNode* n, int data) {
  if(n == NULL) return n;
  if(data < n->data) n->left = deleteNode(n->left, data);
  else if(data > n->data) n->right = deleteNode(n->right, data);
  else {
    if(n->left == NULL) {
      tNode* temp = n->right;
      delete n;
      return temp;
    }

    if(n->right == NULL) {
      tNode* temp = n->left;
      delete n;
      return temp;
    }

    tNode* temp = minValueNode(n->right);
    n->data = temp->data;
    n->right = deleteNode(n->right, temp->data);
  }
  return n;
}

int main() {
  tNode* root = createNode(50);
  insertNode(root, 59);
  insertNode(root, 84);
  insertNode(root, 24);
  insertNode(root, 87);
  insertNode(root, 3);
  insertNode(root, 90);
  deleteNode(root, 36);
  deleteNode(root, 90);
  deleteNode(root, 3);
  deleteNode(root, 87);
  deleteNode(root, 24);
  deleteNode(root, 84);

  inorder(root);
  cout << endl;

  return 0;
}
