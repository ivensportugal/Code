#include<iostream>
using namespace std;

struct tNode {
  int data;
  tNode* left;
  tNode* right;
};

tNode* createNode(int data) {
  tNode* n =  new tNode;
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;
}

tNode* insert(tNode* n, int data) {
  if(n == NULL) return createNode(data);
  if(data < n->data) n->left  = insert(n->left,  data);
  if(data > n->data) n->right = insert(n->right, data);
  return n;
}

void inorder(tNode* n) {
  if(n == NULL) return;
  inorder(n->left);
  cout << n->data << " ";
  inorder(n->right);
}

tNode* search(tNode* n, int data) {
  tNode* current = n;
  while(current != NULL && current->data != data) {
    if(data < current->data) current = current->left;
    else if(data > current->data) current = current->right;
  }
  if(current != NULL) return current;
  else                return NULL;
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
    else if(n->right == NULL) {
      tNode* temp = n->left;
      delete n;
      return temp;
    }
    else {
      tNode* temp = minValueNode(n->right);
      n->data = temp->data;
      deleteNode(n->right, temp->data);
    }
  }
  return n;
}

int main() {
  tNode* root = createNode(50);
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 70);
  root = insert(root, 60);
  root = insert(root, 80);

  inorder(root);
  cout << endl;

  tNode* s = search(root, 10);
  cout << "search(10): " << s->data << endl;
  s = search(root, 60);
  cout << "search(60): " << s->data << endl;
  s = search(root, 40);
  cout << "search(40): " << s->data << endl;
}
