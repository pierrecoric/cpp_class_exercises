#include <iostream>
using std::cout;

class Rectangle {
    private:
        float length;
        float width;
    public:
        Rectangle(float l, float w) : length(l), width(w) {};
        float getLength() const {return length;}
        float getWidth() const {return width;}
        void setLength(float l) {length = l;}
        void setWidth(float w) {width = w;}
        //comput the area
        float area() {return length * width;}
        //compute the perimeter
        float perimeter() {return length * 2 + width * 2;}
        void printInfo();
};

void Rectangle::printInfo() {
    cout << "This rectangle has a length of: " << length << "\n"
         << "It has a width of: " << width << "\n"
         << "It has a permieter of: " << perimeter() << "\n"
         << "it has an area of: " << area() << "\n";
}

int main() {
    Rectangle rectangleA(10,12);
    rectangleA.printInfo();
    return 0;
}