// Traverses a tree using a stack

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

// Pushes an element in the stack
void push(sNode** stack, tNode* n) {

  sNode* newTop = new sNode;

  newTop->data = n;
  newTop->below = *stack;
  *stack = newTop;

}

// Pops an element from the stack
tNode* pop(sNode** stack) {

  if(stack == NULL) return NULL;

  sNode* oldTop = *stack;
  tNode* oldTopData = oldTop->data;
  *stack = (*stack)->below;
  delete oldTop;
  return oldTopData;

}

// Returns the top element without removing it from the stack
tNode* peak(sNode** stack) {

  if(stack != NULL) return (*stack)->data;
  else return NULL;

}


// Helper function to create a tree
tNode* createNode(int data) {

  tNode* n = new tNode;
  
  n->data  = data;
  n->left  = NULL;
  n->right = NULL;

  return n;
}


int main () {

  tNode* root = createNode(6);
  root->left = createNode(4);

  sNode* stack = NULL;

  push(&stack, root);
  push(&stack, root);

  tNode* result = pop(&stack);
  cout << "result: " << result->data << endl;
  peak(&stack);

  return 0;

}
