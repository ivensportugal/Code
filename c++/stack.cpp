// The implementation of a stack data structure in C++

#include <iostream>
using namespace std;

#define MAX 10


// Properties
int stack [MAX];
int top = 0;

// Stack methods

// Inserts an element in the stack if possible
template <typename T>
bool push(T element) {

  if(top >= MAX) {
    return 0;
  }
  stack[top++] = element;

  return 1;
}


// Returns the top element of the stack
int pop() {
  if(top <= 0)
    return 0;
  return stack[--top];
}


int main () {

  push(1);
  push(2);
  cout << "The top element was " << pop() << endl;

  return 0;
}



