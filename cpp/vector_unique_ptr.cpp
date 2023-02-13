#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <list>

class Person {

public:
    Person(int age):age_(age) {
        std::cout << "person constructor is called " << age_ << std::endl;
    }

    ~Person() {
        std::cout << "person deconstructor is called " << age_ << std::endl;
    }

    int age_ = 0;
};

void func(Person** p) {
    *p = new Person(11);
}

    std::vector<std::unique_ptr<Person>> personlist;
    std::list<std::unique_ptr<Person>> personlist2;
void funcd(std::unique_ptr<Person>&& p) {
    personlist2.emplace_back(std::move(p));
}

// use constant will fail here
void funce( std::vector<std::unique_ptr<Person>>& list1) {

    for (auto& b : list1) {
        personlist2.emplace_back(std::move(b));
    }
}
int main() {
    personlist.emplace_back(std::make_unique<Person>(10));
    personlist.emplace_back(std::make_unique<Person>(20));

    //std::unique_ptr<Person> aa = personlist.pop_front();

   // std::cout << "person info " <<aa->age_ << std::endl;

    for (int i  = 0; i < personlist.size(); ++i) {
        std::cout << "person info " << personlist[i]->age_ << std::endl;
    }
    for (auto& b : personlist) {
        personlist2.emplace_back(std::move(b));
    }
    std::unique_ptr<Person> bb;
    //personlist.emplace_back(std::move(bb));
    funcd(std::move(bb));
    //funce(personlist);
    //func(&(bb.get()));
    std::cout << "bb" << bb->age_ << std::endl;
}