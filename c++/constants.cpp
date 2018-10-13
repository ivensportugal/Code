// This program tests constraints

#include <iostream>
#include <string>
using namespace std;

#define MAX  100

const int num = 10;
const string name = "Ivens";

int main () {
  for(int i = 0; i < num; i++) {
    cout << "My name is " << name << endl;
  }

  for(int i = 10; i < MAX / 2; i++) {
    cout << i << endl;
  }

  return 0;

}
