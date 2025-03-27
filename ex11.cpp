#include <iostream>
#include <cstring>
using std::cout;

class StringHolder {
    private:
        char* data;
    public:
        StringHolder(const char* str);
        StringHolder(const StringHolder& other);
        ~StringHolder() {delete[] data;}
        StringHolder& operator = (const StringHolder& other);
        void printSH() const;
};

StringHolder::StringHolder(const char* str) {
    data = new char[strlen(str) + 1];
    strcpy(data, str);
}

StringHolder::StringHolder(const StringHolder& other) {
    data = new char[strlen(other.data) + 1];
    strcpy(data, other.data);
}

StringHolder& StringHolder::operator = (const StringHolder& other) {
    if(this != &other) {
        delete[] data;
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }
    return *this;
}

void StringHolder::printSH() const {
    cout << data << "\n";
}


int main() {
    StringHolder sh1("test");
    sh1.printSH();
    StringHolder sh2(sh1);
    sh2.printSH();
    StringHolder sh3 = sh1;
    sh3.printSH();
    sh3 = "youpi";
    sh3.printSH();
}