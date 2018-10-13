// Traverses a tree without recursion

#include <iostream>
#include <list>
using namespace std;

struct tNode {
  int data;
  tNode* left;
  tNode* right;
};

struct sNode {
  tNode* data;
  sNode* below;
};


// Tree
tNode* createNode(int data) {
  tNode* n = new tNode;
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;
}


// Stack
void push(sNode** stack, tNode* n) {
  sNode* newTop = new sNode;
  newTop->data = n;
  newTop->below = *stack;
  *stack = newTop;
}

tNode* pop(sNode** stack) {
  sNode* oldTop = *stack;
  *stack = (*stack)->below;
  return oldTop->data;
}


// Traversal
void inorder(tNode* root) {

  tNode* current = root;
  sNode* stack = NULL;
  bool done = false;

  while(!done) {
    if(current != NULL) {
      push(&stack, current);
      current = current->left;
    }
    else {
      if(stack != NULL) {
        current = pop(&stack);
        cout << current->data << " ";
        current = current->right;
      }
      else {
        cout << endl;
        done = true;
      }
    }
  }
}

int main () {

  tNode* root = createNode(10);
  root->left = createNode(11);
  root->right = createNode(20);
  root->left->left = createNode(12);
  root->left->right = createNode(7);
  root->right->left = createNode(30);
  root->right->right = createNode(40);

  inorder(root);

  return 0;
}
