#include<iostream>
#include<queue>
using namespace std;

struct tNode {
  int data;
  tNode* left;
  tNode* right;
};

tNode* createNode(int data) {
  tNode* n = new tNode;
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;
}

tNode* insertNode(tNode* n, int data) {
  if(n == NULL) return createNode(data);

  if(data < n->data) n->left = insertNode(n->left, data);
  else if(data > n->data) n->right = insertNode(n->right, data);

  return n;
}

void BFS(tNode* n) {
  if(n == NULL) return;

  queue<tNode*> q;
  q.push(n);

  while(!q.empty()){
    n = q.front();
    cout << n->data << " ";
    q.pop();

    if(n->left != NULL) q.push(n->left);
    if(n->right != NULL) q.push(n->right);
  }

  cout << endl;
}

tNode* minValueNode(tNode* n) {
  tNode* current = n;
  while(current->left != NULL)
    current = current->left;
  return current;
}

tNode* deleteNode(tNode* n, int data) {
  if(n == NULL) return NULL;

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
      n->right = deleteNode(n->right, temp->data);
    }
  }

  return n;
}


int main() {
  tNode* root = createNode(50);
  root = insertNode(root, 10);
  root = insertNode(root, 30);
  root = insertNode(root, 60);
  root = insertNode(root, 80);
  root = insertNode(root, 90);
  root = insertNode(root, 20);
  root = insertNode(root, 40);

  BFS(root);
  root = deleteNode(root, 10);
  root = deleteNode(root, 50);

  BFS(root);

  return 0;
}
