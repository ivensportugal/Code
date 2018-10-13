// Traverses two BSTs and prints data in order

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


// Pushes an element into the stack
void push(sNode** stack, tNode* n) {

  sNode* newTop = new sNode;
  
  newTop->data = n;
  newTop->below = *stack;
  *stack = newTop;

}


// Pops the top element of the stack
tNode* pop(sNode** stack) {
  sNode* oldTop = *stack;
  *stack = (*stack)->below;
  return oldTop->data;
}

void inorder(tNode* root1, tNode* root2) {

  sNode* stack1 = NULL;
  sNode* stack2 = NULL;
  tNode* current1 = root1;
  tNode* current2 = root2;
  bool done = false;

  while(!done) {

    if(current1 != NULL) {
      push(&stack1, current1);
      current1 = current1->left;
    }
    else if(current2 != NULL ) {
      push(&stack2, current2);
      current2 = current2->left;
    }
    else {
      if(stack1 != NULL && stack2 == NULL) {
        current1 = pop(&stack1);
        cout << current1->data << " ";
        current1 = current1->right;
      }
      else if(stack1 == NULL && stack2 != NULL) {
        current2 = pop(&stack2);
        cout << current2->data << " ";
        current2 = current2->right;
      }
      else if(stack1 != NULL && stack2 != NULL) {
        current1 = pop(&stack1);
        current2 = pop(&stack2);

        if(current1->data <= current2->data) {
          push(&stack2, current2);
          current2 = NULL;
          cout << current1->data << " ";
          current1 = current1->right;
        }
        else if(current1->data > current2->data) {
          push(&stack1, current1);
          current1 = NULL;
          cout << current2->data << " ";
          current2 = current2->right;
        }
      }
      else if(stack1 == NULL && stack2 == NULL) {
        cout << endl;
        done = true;
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

  // TEST SET 1
/*
  // Tree #1
  tNode* root1 = createNode(3);
  root1->left  = createNode(1);
  root1->right = createNode(5);

  // Tree #2
  tNode* root2 = createNode(4);
  root2->left  = createNode(2);
  root2->right = createNode(6);
*/

  // TEST SET 2

  // Tree #1
  tNode* root1 = createNode(8);
  root1->left  = createNode(2);
  root1->left->left = createNode(1);
  root1->right = createNode(10);

  // Tree #2
  tNode* root2 = createNode(5);
  root2->left  = createNode(3);
  root2->left->left = createNode(0);


  inorder(root1, root2);

  return 0;
}
