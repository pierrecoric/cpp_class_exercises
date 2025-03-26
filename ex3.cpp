#include <iostream>
#include <string>
using std::cout;
using std::ostream;
using std::string;

class Person {
    private:
        string name;
        int age;
        string country;
    public:
        Person(string n, int a, string c) : name(n), age(a), country(c) {};
        string getName() const {return name;}
        int getAge() const {return age;}
        string getCountry() const {return country;}
        void setName(string n) {name = n;}
        void setAge(int a) {age = a;}
        void setCountry(string c) {country = c;}

        friend ostream& operator << (ostream& outs, const Person& person);

};

ostream& operator << (ostream& outs, const Person& person) {
    outs << "Please meet " << person.getName() << "\n"
         << person.getName() << " is from " << person.getCountry() << " and is " << person.getAge() << " years old.\n";
    return outs;
}

int main() {
    Person pierre("Pierre", 30, "Belgium");
    cout << pierre;
    return 0;
}