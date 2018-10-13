#include <iostream>
#include <fstream>
#define MAX 100
using namespace std;

int main() {

  char data[MAX];


  ofstream file_output;
  file_output.open("bigfile.txt", ios::app);

  file_output << "the brown fox did something that I could not memorize" << endl;
  file_output << "another sentence" << endl;

  file_output.seekp(4);
  file_output << "lazy ";

  file_output.close();


  ifstream file_input;
  file_input.open("bigfile.txt");

  file_input >> data;
  cout << data << endl;

  file_input >> data;
  cout << data << endl;

  file_input.close();

  return 0;

}
