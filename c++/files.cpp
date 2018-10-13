#include <iostream>
#include <fstream>
#include <string>
#define TIMES 2
#define MAX 100
using namespace std;


int main () {

  ofstream outfile;
  outfile.open("word.txt", ios::trunc);
  for(int i = 0; i < TIMES; i++)
    outfile << "test " << i  << endl;

  char data[MAX];

  ifstream infile;
  infile.open("word.txt");

  for(int i = 0; i < TIMES; i++) {
 
    infile.getline(data, MAX);

    for(int j = 0; j < MAX; j++) {
      if(data[j] == '\0') {
        cout << "EOF";
        break;
      }
      cout << data[j];
    }
    cout << endl;
  }

  return 0;

}
