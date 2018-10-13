/* Just a binary tree */

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
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void insert(tNode* root, int data) {

  queue<tNode*> q;
  q.push(root);
  
  tNode * temp;
  while(!q.empty()) {
    temp = q.front();
    q.pop();

    if(!temp->left) {
      temp->left = createNode(data);
      return;
    } else
      q.push(temp->left);

    if(!temp->right) {
      temp->right = createNode(data);
      return;
    } else
      q.push(temp->right);
  }
}

void delete_deepest_right(tNode* root, int data) {
  queue<tNode*> q;
  q.push(root);

  tNode* temp = NULL;
  while(!q.empty()) {
    temp = q.front();
    q.pop();

    if(temp->left) {
      if(temp->left->data == data) {
        tNode* to_delete = temp->left;
        temp->left = NULL;
        delete(to_delete);
        return;
      } else {
        q.push(temp->left);
      }
    }
    if(temp->right) {
      if(temp->right->data == data) {
        tNode* to_delete = temp->right;
        temp->right = NULL;
        delete(to_delete);
        return;
      } else {
        q.push(temp->right);
      }
    }
  }
}

void remove(tNode* root, int data) {

  queue<tNode*> q;

  tNode* to_remove;
  tNode* deep_right = NULL;

  q.push(root);
  while(!q.empty()) {
    deep_right = q.front();
    q.pop();

    if(deep_right->data == data)
      to_remove = deep_right;

    if(deep_right->left)
      q.push(deep_right->left);

    if(deep_right->right)
      q.push(deep_right->right);
  }

  int x = deep_right->data;
  delete_deepest_right(root, x);
  to_remove->data = x;
}

void inorder(tNode* n) {
  if(n == NULL) return;

  if(n->left)
    inorder(n->left);
  cout << n->data << " ";
  if(n->right)
    inorder(n->right);
}

int main() {

  tNode* root = createNode(10);
  root->left = createNode(5);
  root->right = createNode(20);

  root->left->left = createNode(3);
  root->left->left->left = createNode(1);

  root->right->left = createNode(15);
  root->right->right = createNode(25);
  root->right->left->left = createNode(13);
  root->right->right->left = createNode(17);

  cout << "Inorder before manipulation: ";
  inorder(root);

  cout << "Insert 51" << endl;
  insert(root, 51);
  cout << "Insert 41";
  insert(root, 41);

  cout << "Inorder after insertions: ";
  inorder(root);

  cout << "Remove 13" << endl;
  remove(root, 13);

  cout << "Inorder after removals: ";
  inorder(root);

  return 0;
}
