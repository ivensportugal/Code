// The implementation of a heap

#include <iostream>
using namespace std;

bool insert(int heap[], int i) {
  
  if(heap[i % 10] > 0) return false;
  heap[i % 10] = 1;
  return true;

}

int main () {

  int size = 10;
  int* heap = new int[size];

  for(int i = 0; i < size; i++) heap[i] = 0;

  insert(heap, 1);
  insert(heap, 3);
  insert(heap, 67);

  for(int i = 0; i < size; i++)
    cout << "heap[" << i << "] = " << heap[i] << endl;

  return 0;

}
