#include <iostream>
using std::cout;
using std::ostream;

const float PI = 3.1416;

class Shape{
    public:
        virtual float perimeter() {return 0;}
        virtual float area() {return 0;}
};

class Circle : public Shape {
    private:
        float radius;
    public:
        Circle() : radius(0) {};
        Circle(float r) : radius(r) {};
        float getRadius() const {return radius;}
        void setRadius(float r) {radius = r;}
        float perimeter() {return 2 * radius * PI;}
        float area() {return PI * radius * radius;}
        friend ostream& operator << (ostream& outs, Circle& circle);
};

class Rectangle : public Shape {
    private:
        float length;
        float width;
    public:
        Rectangle() : length(0), width(0) {};
        Rectangle(float l, float w) : length(l), width(w) {};
        float getLength() const {return length;}
        float getWidth() const {return width;}
        void setLength(float l) {length = l;}
        void setWidth(float w) {width = w;}
        float perimeter() {return width * 2 + length * 2;}
        float area() {return width * length;}
        friend ostream& operator << (ostream& outs, Rectangle& rectangle);
};

ostream& operator << (ostream& outs, Circle& circle) {
    outs << "This circle has a radius of: " << circle.radius << ".\n"
         << "It has therefore a circumference of: " << circle.perimeter() << ".\n"
         << "And it has an area of: " << circle.area() << ".\n";
    return outs;
}

ostream& operator << (ostream& outs, Rectangle& rectangle) {
    outs << "This rectangle has a length of " << rectangle.length << ".\n"
         << "It has a width of " << rectangle.width << ".\n"
         << "Its perimeter is " << rectangle.perimeter() << ".\n"
         << "Its area is " << rectangle.area() << ".\n";
    return outs;
}



int main() {
    Circle circleA(10);
    Rectangle rectangleA(100,25);
    cout << circleA;
    cout << rectangleA;
    return 0;
}