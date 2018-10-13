#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
  private:
    int id;
    string name;
    int age;

  public:
    Student(int, string, int);
    void print();
};

Student::Student(int _id, string _name, int _age): id(_id), name(_name), age(_age) {}
Student::print() {
  cout << "Hi. I'm " << this->name << ". I'm " << age << " years old and  I'm registered under the id " << id << "." << endl;

Student* load() {}
void save(Student[]) {
  
}

int main() {

  Student 

  return 0;

}
