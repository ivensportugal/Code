#include <iostream>
using namespace std;

int main () {


  int a = -10;
  int b = 10;
  
  int c = 100;

  for(int i = a; i < b; i++) {
    try {
      //if(i == 0) throw "Division By ZERO!!";
      cout << c << "/" << i << ": " << c/i << endl;
    } catch (std::exception const& e) {
      cout << "oh oh" << endl;
    } catch (...) {
      cout << "oh oh oh" << endl;
    }
  }

  return 0;

}
