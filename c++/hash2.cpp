#include <iostream>
using namespace std;
#define SIZE 10

struct hNode {
  int key;
  int value;
  hNode* next;
};

int hashFunction(int i) {
  return i % SIZE;
}

void insert(hNode hash[], hNode* n) {
  if(n == NULL) return;
  int pos = hashFunction(n->key);

  n->next = &hash[pos];
  hash[pos] = *n;
}

// Returns a key, given a value
int getValue()

int main () {

  hNode* hash = new hNode[SIZE];

  return 0;
}
