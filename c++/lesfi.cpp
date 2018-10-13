#include <iostream>
#include <fstream>
using namespace std;

int main () {

  ofstream outfile;
  outfile.open("file.txt", ios::out);

  cout << "test" << endl;
  return 0;
}
