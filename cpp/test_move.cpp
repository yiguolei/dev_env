#include <iostream>
#include <memory>
#include <vector>

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

void functiona(std::shared_ptr<Person>& returnval) {
    std::shared_ptr<Person> p = std::make_shared<Person>();
    p->a = 11;
    returnval = p;
}


int main() {

    std::shared_ptr<Person> res = nullptr;
    functiona(res);
    std::cout << res->a << std::endl;
/*
    std::vector<std::unique_ptr<Person>> person1;
    person1.push_back(std::make_unique<Person>());
    person1.push_back(std::make_unique<Person>());
    person1.push_back(std::make_unique<Person>());
    person1.push_back(std::make_unique<Person>());

    std::vector<std::unique_ptr<Person>> person2;
    person2 = std::move(person1);
    Person p;
    // compile will failed, because funca only allow right value to call
    // p.funca();
    std::move(p).funca();
    p.funcb();
    p.funcd();
    */
}