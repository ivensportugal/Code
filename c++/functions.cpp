// This code tests functions

#include <iostream>
#include <string>
using namespace std;

void above () {
  cout << "I'm above!" << endl;
}

void below () {
  cout << "I'm below!" << endl;
}

int sumOfSquares1 (int a, int b) {
  a *= a;
  b *= b;
  return a+b;
}

int sumOfSquares2 (int &a, int &b) {
  a *= a;
  b *= b;
  return a+b;
}

int main () {

  int a = 3;
  int b = 2;

  int c = sumOfSquares2(a,b);

  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "sumOfSquares(a,b): " << c << endl;

  return 0;
}
