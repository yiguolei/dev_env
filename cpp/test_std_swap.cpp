#include <iostream>
#include <memory>
#include <vector>

class Man {
public:
    Man(int age, int aa):age_(age) {
        std::cout << "Man constructor is called " << age_ << std::endl;
    }

    Man():age_(-1) {
        std::cout << "Man constructor is called " << age_ << std::endl;
    }

    ~Man() {
        std::cout << "Man deconstructor is called " << age_ << std::endl;
    }

public:
    void test_method() {
        std::cout << "test_methodMan is called " << age_ << std::endl;
    }
    int age_ = 0;
};

int main() {

    // test pointer swap

    Man* m1 = new Man(1,1);
    Man* m2 = new Man(2,2);

    m1->test_method();
    m2->test_method();

    std::cout << m1 << std::endl;
    std::cout << m2 << std::endl;

    std::cout << "test swap pointer" << std::endl;
    std::swap(m1, m2);
    
    m1->test_method();
    m2->test_method();


    std::cout << m1 << std::endl;
    std::cout << m2 << std::endl;

    std::cout << "test swap back" << std::endl;
    std::swap(m1, m2);

    std::cout << m1 << std::endl;
    std::cout << m2 << std::endl;
    // move a pointer, m2 will == m1
    std::cout << "test move pointer" << std::endl;
    m1 = std::move(m2);
    std::cout << m1 << std::endl;
    std::cout << m2 << std::endl;
    m1->test_method();
    m2->test_method();
}