// This code tests inputs

#include <iostream>
#include <string>
using namespace std;

int main () {

  int num1 = 1;
  int num2 = 2;
  int num3 = 3;

  string s1 = "";
/*
  cout << "Type a number: ";
  cin >> num1;
  cout << "\nYou typed number " << num1 << "." << endl;

  cout << "Type another number: ";
  cin >> num2;
  cout << "\nYou now typed number " << num2 << "." << endl;

  cout << "Type a third number: ";
  cin >> num3;
  cout << "\nYou now typed number " << num3 << "." << endl;
*/

  // Strings
  cout << "What is your name? ";
  getline(cin,s1);
  cout << "\nYour name is " << s1 << endl;


  return 0;
}
