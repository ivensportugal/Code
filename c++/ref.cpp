#include <iostream>
using namespace std;

class Person {
  private:
    int age;
  public:
    Person() {};
    Person(int age) {this->age = age;};
    int getAge() { return this->age; };
};

void printPerson1(Person p) {
  cout << "this person is " << p.getAge() << " years old." << endl;
}

void printPerson2(Person& p) {
  cout << "This person is " << p.getAge() << " years old." << endl;
}

int main () {

  Person p1 = Person(10);

  cout << "this person is " << p1.getAge() << " years old." << endl;
  printPerson1(p1);
  printPerson2(p1);

  return 0;

}
