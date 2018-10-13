#include<iostream>
using namespace std;
#define SIZE 10

struct hNode {
  int key;
  int value;
  hNode* next;
};

hNode* createHNode(int key, int value) {
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
  while(current != NULL && current->key != key)
    current = current->next;
  if(current != NULL) return current->value;
  else                return -1;
}

int main () {
  hNode* hash[SIZE];
  insert(hash, createHNode(10,100));
  insert(hash, createHNode(20,200));
  insert(hash, createHNode(30,300));
  insert(hash, createHNode(12,12));

  cout << "getValue(10): " << getValue(hash, 10) << endl;
  cout << "getValue(12): " << getValue(hash, 12) << endl;
  cout << "getValue(30): " << getValue(hash, 30) << endl;
  cout << "getValue(20): " << getValue(hash, 20) << endl;

  return 0;
}
