#include <iostream>

template <class T> class Student {
  private:
    T age;
  public:
    Student(T age): age(age) {}
    T getAge() { return this->age; }
};


int main () {

  Student<int>    si = Student<int>(2);
  Student<double> sd = Student<double>(2.1);  


  std::cout << "Age si: " << si.getAge() << std::endl;
  std::cout << "Age sd: " << sd.getAge() << std::endl;

  return 0;

}
