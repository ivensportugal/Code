/* Deletion on a binary tree */

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


void inorder(tNode* n) {
  if(n == NULL) return;
  inorder(n->left);
  cout << n->data << " ";
  inorder(n->right);
}

void deleteDeepest(tNode* root, tNode* d_node) {
  queue<tNode*> q;
  q.push(root);

  tNode* temp;
  while(!q.empty()) {

    temp = q.front();
    q.pop();

    if(temp->right) {
      if(temp->right == d_node) {
        temp->right = NULL;
        delete(d_node);
        return;
      }
      else
        q.push(temp->right);
    }

    if(temp->left) {
      if(temp->left == d_node) {
        temp->left = NULL;
        delete(d_node);
        return;
      }
      else
        q.push(temp->left);
    }
  }
}

void deletion(tNode* root, int data) {
  queue<tNode*> q;
  q.push(root);

  tNode* temp;
  tNode* data_node = NULL;

  while(!q.empty()) {
    temp = q.front();
    q.pop();

    if(temp->data == data)
      data_node = temp;

    if(temp->left)
      q.push(temp->left);

    if(temp->right)
      q.push(temp->right);
  }

  int x = temp->data;
  deleteDeepest(root, temp);
  data_node->data = x;
}

int main() {
  tNode* root = createNode(10);

  root->left = createNode(11);
  root->left->left = createNode(7);
  root->left->right = createNode(12);

  root->right = createNode(9);
  root->right->left = createNode(15);
  root->right->right = createNode(8);

  cout << "Inorder traversal before deletion:";
  inorder(root);
  cout << endl;

  int key = 11;
  deletion(root, key);

  cout << "Inorder traversal after deletion:";
  inorder(root);
  cout << endl;

  return 0;
}


