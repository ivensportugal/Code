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
  queue<tNode*> q;
  q.push(n);

  while(!q.empty()) {
    n = q.front();
    cout << n->data << " ";
    q.pop();

    if(n->left != NULL) q.push(n->left);
    if(n->right != NULL) q.push(n->right);
  }

  cout << endl;
}

void inorder(tNode* n) {
  if(n == NULL) return;
  inorder(n->left);
  cout << n->data << " ";
  inorder(n->right);
}

int main() {
  tNode* root = createNode(50);
  root = insertNode(root, 10);
  root = insertNode(root, 60);

  BFS(root);
  inorder(root);
  cout << endl;

  return 0;
}
