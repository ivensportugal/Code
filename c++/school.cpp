// This code tests classes in C++
#include <iostream>
#include <string>
using namespace std;

class Student {
  string givenName;
  string familyName;
  int age;

  public:

    Student(string, string, int);

    string getFullName() {
      return givenName + " " + familyName;
    }

    int getAge() {
      return age;
    }

};

Student::Student(string givenName, string familyName, int age) {
  this->givenName = givenName;
  this->familyName = familyName;
  this->age = age;
}

int main () {

  string gName;
  string fName;
  int age;
  

  cout << "Type the given name of the student: ";
  cin >> gName;

  cout << "Type the family name of the student: ";
  cin >> fName;

  cout << "Type the age of the student: ";
  cin >> age;

  Student s1 (gName, fName, age);

  cout << s1.getFullName() << " is " << s1.getAge() << " years old." << endl;

  return 0;

}

