#include<iostream>
using namespace std;

void doNothing1(char  c[]) {}
void doNothing2(char* c  ) {}

int main () {

  char  c1 = 'a';
  char  c2[] = "Hello World!";
  char* c3;
  c3 = c2;

  char* c4[3];
  c4[0] = c3;
  c4[1] = c2;

  doNothing1(c2);
  doNothing1(c3);

  doNothing2(c2);
  doNothing2(c3);



  return 0;

}
