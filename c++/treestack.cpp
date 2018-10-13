// Traverses a tree inorder using a stack (no recursion)

#include <iostream>
using namespace std;

#define NUM_NODES 10

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


// Pushes an element into the stack
void push(sNode** stack, tNode* n) {

  sNode* newNode = new sNode;
  newNode->data = n;
  newNode->below = *stack;

  *stack = newNode;

}


// Pops an element from the stack
tNode* pop(sNode ** stack) {

  sNode* oldTop;

  if(stack == NULL) return NULL;
  else {
    oldTop = *stack;
    *stack = (*stack)->below;
    return oldTop->data;
  }
}



void inorder(tNode* root) {

  tNode* current = root;
  sNode* stack   = NULL;
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
        done = true;
        cout << endl;
      }
    }
  }
}






// Helper function to create a tree node
tNode* createNode(int data) {

  tNode* n = new tNode;

  n->data  = data;
  n->left  = NULL;
  n->right = NULL;

  return n;

}

int main () {

  tNode* root = createNode(7);
  root->left = createNode(3);
  root->right = createNode(9);
  root->left->left = createNode(1);
  root->left->right = createNode(5);
  root->left->left->left = createNode(0);
  root->left->left->right = createNode(2);
  root->left->right->left = createNode(4);
  root->left->right->right = createNode(6);
  root->right->left = createNode(8);
  root->right->right = createNode(10);

  inorder(root);


  return 0;
}
