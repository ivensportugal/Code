#include <iostream>

class Student {
  private:
    int age;
  public:
    Student(int);
    int getAge() const;
    bool operator< (const Student&);
};

Student::Student(int age):age(age) {}
int Student::getAge() const {
  return this->age;
}

bool Student::operator< (const Student& s) {
  return (this->age < s.age);
}

template <typename T> T const& highest(T const& t1, T const& t2) {
  return (t1 < t2)? t1 : t2;
}

bool operator< (const Student& s1, const Student& s2) {
  return (s1.getAge() < s2.getAge());
}

int main () {

  Student s1 = Student(29);
  Student s2 = Student(31);
  Student sr = highest(s1, s2);


  int i1 = 10;
  int i2 = 11;

  double d1 = 10.1;
  double d2 = 101.1;

  std::cout << "Results" << std::endl;

  std::cout << "Int    : " << highest(i1, i2) << std::endl;
  std::cout << "Double : " << highest(d1, d2) << std::endl;
  std::cout << "Student: " <<     sr.getAge() << std::endl;

  return 0;

}

