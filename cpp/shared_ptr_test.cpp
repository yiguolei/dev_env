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

    void test_method() {
        std::cout << "test_method is called" << std::endl;
    }
    int age_ = 0;
};

int main() {
    std::cout << "begin test" << std::endl;
    {
        std::shared_ptr<void> voidperson = std::make_shared<Person>(10);
        std::cout << voidperson.use_count() << std::endl;
        std::static_pointer_cast<Person>(voidperson)->test_method();
        std::cout << voidperson.use_count() << std::endl;
        std::shared_ptr<Person> p = std::static_pointer_cast<Person>(voidperson);
        std::cout << voidperson.use_count() << std::endl;

        std::cout << p.use_count() << std::endl;
    }
    std::cout << "end test" << std::endl;
    {
        std::shared_ptr<Person> voidperson = std::make_shared<Person>(10);
        std::cout << voidperson.use_count() << std::endl;
        std::shared_ptr<Person> voidperson2 = voidperson;
        std::cout << voidperson.use_count() << std::endl;
        // Reference will not increase use count
        std::shared_ptr<Person>& voidperson3 = voidperson;
        std::cout << voidperson.use_count() << std::endl;
        std::shared_ptr<Person> voidperson4 = voidperson;
        std::cout << voidperson.use_count() << std::endl;
        
    }
}