#include <iostream>
using namespace std;

class Shape
{
public:
    virtual double area() = 0;
};

class Circle: public Shape {

    double rad;

public:
    Circle(double r)
    {
        rad = r;
    }

    double area() {
        return 3.14 * rad * rad;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double area() {
        return length * width;
    }
};

int main() {
    Circle c(15);
    Rectangle r(14, 26);

    cout << "Circle Area = " << c.area() << endl;
    cout << "Rectangle Area = " << r.area() << endl;

    return 0;
}