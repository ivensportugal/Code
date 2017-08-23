#include <iostream>
using namespace std;

int main (void) {
  int num;
  int numTests;

  cin >> numTests;
  for(int i = 0; i < numTests; i++) {
    cin >> num;
    for(int j = 0; j*(j+1) <= num; j++)
      cout << j*(j+1) << " ";
    cout << endl;
  }

  return 0;

}
