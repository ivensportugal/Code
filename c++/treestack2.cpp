// Traverses a tree inorder without recursion

#include <iostream>
using namespace std;

// Tree struct
struct tNode {
  int data;
  tNode* left;
  tNode* right;
};


// Stack struct
struct sNode {
  tNode* data;
  sNode* below;
};


// Pushes an element to the stack
void push(sNode** stack, tNode* n) {
  sNode* newTop = new sNode;
  newTop->data = n;
  newTop->below = *stack;
  *stack = newTop;
}

// Pops the top element from the stack
tNode* pop(sNode** stack) {
  if(stack == NULL) return NULL;
  sNode* oldTop = *stack;
  *stack = (*stack)->below;
  return oldTop->data;
}


// Traverses the tree
void inorder(tNode* root) {

  sNode* stack = NULL;
  tNode* current = root;
  bool done = false;

  while(!done) {
    if(current != NULL) {
      push(&stack, current);
      current = current->left;
    } else {
      if(stack != NULL) {
        current = pop(&stack);
        cout << current->data << " ";
        current = current->right;
      } else {
        cout << endl;
        done = true;
      }
    }
  }
}


tNode* createNode(int data) {
  tNode* n = new tNode;

  n->data = data;
  n->left = NULL;
  n->right = NULL;

  return n;
}


int main () {

  tNode* root = createNode(5);
  root->left  = createNode(3);
  root->right = createNode(10);
  root->left->left  = createNode(1);
  root->left->right = createNode(4);

  inorder(root);
  
  return 0;
}
