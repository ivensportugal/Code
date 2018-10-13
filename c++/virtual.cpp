#include <iostream>
using namespace std;

// Classes
class Shape {
  protected:
    int width;
    int height;
  public:
    Shape(int, int);
    int getWidth();
    int getHeight();
    virtual int getArea() = 0;
};

class Rectangle: public Shape {
  public:
    Rectangle(int, int);
    int getArea();
};

class Triangle: public Shape {
  public:
    Triangle(int, int);
    int getArea();
};


// Methods / Member Functions
Shape::Shape(int width, int height) {
  this->width  = width;
  this->height = height;
}

int Shape::getWidth() {
  return this->width;
}

int Shape::getHeight() {
  return this->height;
}



Rectangle::Rectangle(int width, int height): Shape(width, height) {}
int Rectangle::getArea() {
  return this->width * this->height;
}

Triangle::Triangle(int width, int height): Shape(width, height) {}
int Triangle::getArea() {
  return this->width * this->height * 1/2;
}


// Main

int main () {

  Rectangle r = Rectangle(10, 20);
  cout << "r.area = " << r.getArea() << endl;

  Triangle t = Triangle(10, 30);
  cout << "t.area = " << t.getArea() << endl;

  Shape *s;
  s = &r;
  cout << "s.area = " << s->getArea() << endl;
  s = &t;
  cout << "s.area = " << s->getArea() << endl;

  Shape s = Shape(1,2);

  return 0;
}
