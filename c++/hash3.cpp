#include<iostream>
using namespace std;
#define SIZE 10

// A Hash Node
struct hNode {
  int key;
  int value;
  hNode* next;
};

// Creates a hash node
hNode* createHNode(int key, int value) {
  hNode* n = new hNode;
  n->key = key;
  n->value = value;
  n->next = NULL;
  return n;
}

// A hash function to hash keys
int hashFunction(int key) {
  return key % SIZE;
}

// Inserts a node in the hash
void insert(hNode* hash[], hNode* n) {
  if(n == NULL) return;
  int pos = hashFunction(n->key);
  n->next = hash[pos];
  hash[pos] = n;
}

// Returns the value of a key
int getValue(hNode* hash[], int key) {
  int pos = hashFunction(key);
  hNode* current = hash[pos];
  while(current != NULL && current->key != key)
    current = current->next;

  if(current != NULL) return current->value;
  else                return -1;
}

// Driver function
int main () {
  hNode* hash[SIZE];
  insert(hash, createHNode(0,0));
  insert(hash, createHNode(1,1));

  cout << "getValue(0): " << getValue(hash, 0) << endl;
  cout << "getValue(1): " << getValue(hash, 1) << endl;

  return 0;
} 
