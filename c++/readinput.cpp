#include <iostream>
#include <string>
using namespace std;

int main () {
  char data1[10];
  char data2[10];

  cout << "Enter your name: ";
  cin.getline(data1, 10);

  for(int i = 0; i < 10; i++) {
    if (data1[i] == '\0') {
      cout << "EOF";
      break;
    }
    cout << data1[i] << "-";
  }

  cout << endl;
}
