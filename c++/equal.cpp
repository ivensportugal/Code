// This code tests templates
#include <iostream>
using namespace std;

template <class T, class U>
bool are_equal(T a, U b) {
  return a == b;
}

int main () {
  int a = 1;
  int b = 2;
  int c = 1;
  double d = 3.0;

  cout << "are_equal(a, b) = " << are_equal(a, b) << "." << endl;
  cout << "are_equal(a, c) = " << are_equal(a, c) << "." << endl;
  cout << "are_equal(a, d) = " << are_equal(a, d) << "." << endl;

  return 0;
}
