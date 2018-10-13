#include <iostream>
#include <queue>
using namespace std;

struct tNode* {
  int data;
  tNode* left;
  tNode* right;
};

tNode* createNode(int data) {
  tNode* newNode = new tNode;
  newNode->data = datal;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

tNode* insertNode(tNode* n, int data) {
  queue<tNode*> q;
  q.push(n);

  while(!q.empty) {
    tNode* temp = q.front();
    q.pop();

    if(!temp->left) {
      temp->left = createNode(data);
      break;
    else {
      q.push(temp->left)
    }

    if(!temp->right) {
      temp->right = createNode(data);
      break;
    else {
      queue.push(temp->right);
    }
  }
}

int main( {
  tNode* root = createNode(20);
  insertNode(root, 10);
  insertNode(root, 40);
