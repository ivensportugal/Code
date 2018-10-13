// The implementation of a Hash

#include <iostream>
using namespace std;

#define SIZE 10

// A hash node
struct hNode {
  int key;
  int value;
  hNode* next;
};

// Creates a hNode
hNode* createHNode(int key, int value) {

  hNode* n = new hNode;
  n->key   = key;
  n->value = value;
  n->next  = NULL;

  return n;
}


// A hash function
int hashFunction (int i) {
  return i % SIZE;
}

// Inserts a node
void insert(hNode hash[], hNode* n) {

  if(n == NULL) return;

  int pos = hashFunction(n->key);

  // Inserts a node. Works for both empty or non empty positions
  n->next = &hash[pos];
  hash[pos] = *n;
  
}

// Returns a key, given a value
int getValue(hNode hash[], int key) {

  int pos = hashFunction(key);

  hNode* current = &hash[pos];
  while(current->key != key && current != NULL)
    current = current->next;

  if(current !=  NULL) return current->value;
  else                 return -1;

}


int main () {

  hNode* hash = new hNode[SIZE];

  insert(hash, createHNode(1,0));
  insert(hash, createHNode(4,3));
  insert(hash, createHNode(9,10));
  insert(hash, createHNode(11,12));

  cout << getValue(hash, 4)  << endl;
  cout << getValue(hash, 11) << endl;

  return 0;

}
