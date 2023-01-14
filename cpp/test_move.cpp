#include <iostream>

class Person {

public:
    void funcd() {
        std::cout << "funcd called" << std::endl;
    }

    void funcb() const & {
        std::cout << "funcb called" << std::endl;
    }

    void funca() const && {
       // a = 10; // compile failed because it is const
        std::cout << "funca called "  << a << std::endl;
    }

int a = 0;
};


int main() {
    Person p;
    // compile will failed, because funca only allow right value to call
    // p.funca();
    std::move(p).funca();
    p.funcb();
    p.funcd();
}