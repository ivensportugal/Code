#include <iostream>
#include <string>

using namespace std;

class A {
  public:
    int a;
};

class B:A {
  public:
    int b;
};

class C:B,A {
  public:
    int c;
};

int main () {

  A a;
  B b;
  C c;

  return 0;
}
