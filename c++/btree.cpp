/* The implementation of a Binary Tree */

#include <iostream>
using namespace std;

struct tNode {
  int data;
  tNode* l;
  tNode* r;
};

tNode* newNode(int data) {

  tNode* newNode = new tNode;
  newNode->data = data;
  newNode->l    = NULL;
  newNode->r    = NULL;

  return newNode;

}

int main() {

  // create node
  tNode* root = newNode(1);

  root->l = newNode(2);
  root->r = newNode(3);
  root->l->l = newNode(4);

  return 0;
}
