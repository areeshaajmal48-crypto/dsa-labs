#include <iostream>
using namespace std;

class employe
{
public:
    virtual double calculate() = 0;
};
class fulltime : public employe {
private:
    double salary;
public:
    fulltime(double s) {
        salary = s;
    }
    double calculate() {
        return salary;
    }
};
class parttime : public employe {

    double hours;
    double rate;
public:
    parttime(double h, double r) {
        hours = h;
        rate = r;
    }
    double calculate() {
        return hours * rate;
    }
};

int main() {
    fulltime empl1(500);
    parttime emp2(5, 10);

    cout << "Full Time Salary = " << empl1.calculate() << endl;
    cout << "Part Time Salary = " << emp2.calculate() << endl;

    return 0;
}