/* A not organized tree */

#include<iostream>
#include<queue>
using namespace std;

struct tNode {
  int data;
  tNode* left;
  tNode* right;
};

tNode* createNode(int data) {
  tNode* newNode = new tNode;
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void insert(tNode* root, int data) {

  queue<tNode*> q;
  q.push(root);

  while(!q.empty()) {

    tNode* temp = q.front();
    q.pop();

    if(!temp->left) {
      temp->left = createNode(data);
      return;
    }
    else
      q.push(temp->left);

    if(!temp->right) {
      temp->right = createNode(data);
      return;
    }
    else
      q.push(temp->right);
  }
}

void inorder(tNode* n) {
  if(n == NULL)  return;
  inorder(n->left);
  cout << n->data << " ";
  inorder(n->right);
}

int main() {

  tNode* root = createNode(1);
  root->left = createNode(2);
  root->left->left = createNode(3);

  inorder(root);
  cout << endl;

  return 0;


}
