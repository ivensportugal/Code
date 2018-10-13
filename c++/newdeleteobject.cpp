#include <iostream>
#define MAX 10
using namespace std;

class Student {
  public:
    Student() {
      cout << "Creating a student!" << endl;
    }
    ~Student() {
      cout << "Destryoing a student!" << endl;
    }
};

int main() {

  Student* s = new Student[MAX];
  delete [] s;

  return 0; 

}


