#include <iostream>

namespace one {
  void print() {
    std::cout << "print1" << std::endl;
  }
}

namespace two {
  void print() {
    std::cout << "print2" << std::endl;
  }
}

int main () {
  one::print();
  two::print();
  return 0;
}
