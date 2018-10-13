#include <iostream>
#include <string>
using namespace std;

int main () {

  int size;

  cout << "Type a number: ";
  cin >> size;

  cout << "Now, type " << size << " words. One per line." << endl;
  string words[size];
  for(int i = 0; i < size; i++) {
    cout << "Word " << i << ": ";
    cin >> words[i];
  }

  cout << "These are the words you typed, but in reverse order:" << endl;
  for(int i = size-1; i >= 0; i--)
    cout << words[i] << endl;


  return 0;

}
