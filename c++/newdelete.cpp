#include <iostream>
using namespace std;

int main() {

  int* n = NULL;
  n = new int;
  *n = 3;

  cout << "*n = " << *n << endl;

  delete n;

  return 0;

}
