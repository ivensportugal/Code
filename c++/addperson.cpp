#include <iostream>
#include <string>
using namespace std;

class Person {
  private:
    string name;
    int age;
  public:
    Person(string, int);
    string getName();
    int getAge();
    Person operator+(Person&);    
};

Person::Person(string name, int age) {
  this->name = name;
  this->age  = age;
}

string Person::getName() {
  return this->name;
}

int Person::getAge() {
  return this->age;
}

Person Person::operator+(Person& p) {
  return Person(this->name + p.name, this->age + p.age);
}

Person operator-(Person& p1, Person& p2) {
  if (p1.getAge() > p2.getAge()) 
    return Person(p1.getName() + p2.getName(), p1.getAge() - p2.getAge());
  else
    return Person(p1.getName() + p2.getName(), p2.getAge() - p1.getAge());
}


int main() {

  Person p1 = Person("Ivens", 29);
  Person p2 = Person("Marcelo", 31);

  Person p3 = p1 + p2;
  Person p4 = p1 - p2;

  cout << p3.getName() << " is " << p3.getAge() << " years old." << endl;
  cout << p4.getName() << " is " << p4.getAge() << " years old." << endl;

  return 0;
}

