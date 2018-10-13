#include<iostream>
using namespace std;

struct lNode {
  int data;
  lNode* next;
};

lNode* createNode(int data) {
  lNode* n = new lNode;
  n->data = data;
  n->next = NULL;
  return n;
}

void push(lNode** l, int data) {
  lNode* n = createNode(data);
  n->next = *l;
  *l = n;
}

void insertAfter(lNode* prev, int data) {
  lNode* n = createNode(data);
  n->next = prev->next;
  prev->next = n;
}

void append(lNode** l, int data) {
  lNode* n = createNode(data);
  lNode* last = *l;

  if(*l == NULL) {
    *l = n;
    return ;
  }

  while(last->next != NULL)
    last = last->next;

  last->next = n;
  return;
}

int main() {
  return 0;
}
