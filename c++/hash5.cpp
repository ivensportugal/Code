#include <iostream>
using namespace std;
#define SIZE 10

struct hNode {
  int key;
  int value;
  hNode* next;
};

hNode* createNode(int key, int value) {
  hNode* n = new hNode;
  n->key = key;
  n->value = value;
  n->next = NULL;
  return n;
}

int hashFunction(int key) {
  return key % SIZE;
}

void insert(hNode* hash[], hNode* n) {
  if(n == NULL) return;
  int pos = hashFunction(n->key);
  n->next = hash[pos];
  hash[pos] = n;
}

int getValue(hNode* hash[], int key) {
  int pos = hashFunction(key);
  hNode* current = hash[pos];
  while(current != NULL  && current->key != key)
    current = current->next;
  if(current != NULL) return current->value;
  else                return -1;
}

int main() {
  hNode* hash[SIZE];
  insert(hash, createNode(10,10));
  insert(hash, createNode(11,10));
  cout << "getValue(10): " << getValue(hash, 10) << endl;
  return 0;
}
