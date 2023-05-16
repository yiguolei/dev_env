#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <list>

template <typename Derived>
class SmartPtrEnabler {
public:
    template <typename... Args>
    static std::shared_ptr<Derived> create_shared(Args&&... args) {
        return std::shared_ptr<Derived>(new Derived(std::forward<Args>(args)...));
    }
    
private:  
    // #1: To prevent allocation of scalar objects
    void * operator new(std::size_t size) {
        return ::operator new(size);
    }
    // #2: To prevent allocation of array of objects
    void * operator new [] (std::size_t size) {
        return ::operator new(size);
    }
}; 


class Man  : public SmartPtrEnabler<Man> {
public:
    friend class SmartPtrEnabler<Man>;
public:
    Man(int age):age_(age) {
        std::cout << "Man constructor is called " << age_ << std::endl;
    }

    ~Man() {
        std::cout << "Man deconstructor is called " << age_ << std::endl;
    }

public:
    void test_method() {
        std::cout << "test_methodMan is called" << std::endl;
    }
    int age_ = 0;
};

struct Woman : public Man {
public:
    Woman(int age):Man(age), age_(age) {
        std::cout << "Woman constructor is called " << age_ << std::endl;
    }

    ~Woman() {
        std::cout << "Woman deconstructor is called " << age_ << std::endl;
    }

public:
    void test_method() {
        std::cout << "test_methodWoman is called" << std::endl;
    }
    int age_ = 0;
};

int main() {
    Man m(10);
    m.test_method();
    //Man* m2 = new Man(10);
    //m2->test_method();
    std::shared_ptr<Man> m3 = Man::create_shared(10);
    m3->test_method();
    Woman w(11);
    w.test_method();
    //Woman* w2 = new Woman(12);
    //w2->test_method();

    std::shared_ptr<Woman> w3 = Woman::create_shared(13);
    w3->test_method();
}