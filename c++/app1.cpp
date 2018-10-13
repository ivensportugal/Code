#include <iostream>
#include <string>
#define MAX 10
using namespace std;

class Person {
  private:
    string name;
    int age;

  public:
    Person() {};
    Person(string, int);
    ~Person();
    Person(const Person&);

    string getName();
    int getAge();
};

Person::Person(string name, int age) {
  this->name = name;
  this->age  = age;
}

Person::~Person() {

}

Person::Person(const Person& p) {
  this->name = p.name;
  this->age  = p.age;
}

string Person::getName() {
  return this->name;
}

int Person::getAge() {
  return this->age;
}


int main () {

  Person p[MAX];
  int counter = 0;
  string name;
  int age;

  while(1) {
    cout << "Please, enter your name: ";
    cin >> name;

    if(name == "exit") break;
    

    cout << "Please, enter your age: ";
    cin >> age;
    cout << "Thank you " << name << endl;

    p[counter] = Person(name, age);
    counter++;
    if(counter == MAX)
      cout << "Max number of people reached! Exiting..." << endl;

  }

  cout << endl << "People in the database:" << endl;
  for(int i = 0; i < counter; i++)
    cout << p[i].getName() << " -- " << p[i].getAge() << endl;
    

  return 0;

}
