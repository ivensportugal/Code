// This code calculates the factorial of a number

#include <iostream>
using namespace std;

int factorial(int);

int main () {
  int n = 0;

  cout << "Type a number: ";
  cin >> n;
  cout << "factorial(" << n << ") is " << factorial(n) << "." << endl;

  return 0;
}

int factorial (int n) {
  if(n == 1) return 1;
  return n * factorial(n-1);
}
