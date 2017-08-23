#include <iostream>
using namespace std;

int main (void) {

  int numTests;
  cin >> numTests;

  for(int i = 0; i < numTests; i++) {
    int sizeArray;
    cin >> sizeArray;

    int num = 0;
    int sum = 0;
    for(int j = 0; j < sizeArray; j++) {
      cin >> num;
      sum += num;
    }

    if(sum % 2) cout << 1 << endl;
    else cout << 2 << endl;
  }

  return 0;
}
