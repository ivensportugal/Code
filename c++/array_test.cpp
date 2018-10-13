#include <iostream>
using namespace std;

int* troll() {

  int* arr_j = new int [2];
  arr_j[0] = 10;
  arr_j[1] = 11;

  return arr_j;

}

int main () {

  int* arr_i = new int [2];
  arr_i[0] = 1;
  arr_i[1] = 2;

  cout << arr_i[0] << " " << arr_i[1] << endl;

  arr_i = troll();

  cout << arr_i[0] << " " << arr_i[1] << endl;

  return 0;

}
