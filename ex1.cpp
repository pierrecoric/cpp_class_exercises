#include <iostream>
using std::cout;

const float PI = 3.1416;

class Circle {
    private:
        float radius;
    public:
        Circle(float r) : radius(r) {};
        float getRadius() const {return radius;}
        void setRadius(float r) {radius = r;}
        float circumference() {return 2 * radius * PI;}
        float area() {return PI * radius * radius;}
        void printInfo();
};

void Circle::printInfo() {
    cout << "This circle has a radius of: " << radius << ".\n"
         << "It has therefore a circumference of: " << circumference() << ".\n"
         << "And it has an area of: " << area() << ".\n";
}

int main () {
    Circle circleA(10);
    cout << circleA.getRadius() << "\n";
    cout << circleA.circumference() << "\n";
    cout << circleA.area() << "\n";
    cout << "printing infos. \n";
    circleA.printInfo();
    circleA.setRadius(12.2);
    cout << "Modified radius, printing infos again: \n";
    circleA.printInfo();
    return 0;
}