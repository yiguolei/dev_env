#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <list>

#define ENABLE_FACTORY_CREATOR(TypeName)                                                    \
private:                                                                                    \
    void* operator new(std::size_t size) { return ::operator new(size); }                   \
    void* operator new[](std::size_t size) { return ::operator new[](size); }               \
                                                                                            \
public:                                                                                     \
    void* operator new(std::size_t count, void* ptr) { return ::operator new(count, ptr); } \
    void operator delete(void* ptr, std::size_t size) { ::operator delete(ptr, size); }     \
    void operator delete[](void* ptr, std::size_t size) { ::operator delete[](ptr, size); } \
    void operator delete(void* ptr, void* place) { ::operator delete(ptr, place); }         \
    template <typename... Args>                                                             \
    static std::shared_ptr<TypeName> create_shared(Args&&... args) {                        \
        return std::make_shared<TypeName>(std::forward<Args>(args)...);                     \
    }                                                                                       \
    template <typename... Args>                                                             \
    static std::unique_ptr<TypeName> create_unique(Args&&... args) {                        \
        return std::unique_ptr<TypeName>(new TypeName(std::forward<Args>(args)...));        \
    }\


class Man {
    ENABLE_FACTORY_CREATOR(Man);
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
        std::cout << "test_methodMan is called" << std::endl;
    }
    int age_ = 0;
};


class Woman : public Man {
    ENABLE_FACTORY_CREATOR(Woman);
public:
    Woman(int age):Man(age,1), age_(age) {
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
    Man m(10,1);
    m.test_method();
    Man m11;
    m11 = m;
    m11.test_method();
    
    
    //Man* m2 = new Man(10,1);
    //m2->test_method();
    
    std::shared_ptr<Man> m3 = Man::create_shared(10,1);
    m3->test_method();
    std::shared_ptr<Man> m4 = std::make_shared<Man>(10,1);
    m4->test_method();
    //std::unique_ptr<Man> m5 = std::make_unique<Man>(10,1);
    //m5->test_method();
    std::unique_ptr<Man> m6 = Man::create_unique(11,1);
    m6->test_method();
    
    char * a = new char[1000];
    Man* m7 = new (a) Man(12,1);
    m7->test_method();

    Woman w(11);
    w.test_method();
    //Woman* w2 = new Woman(12);
    //w2->test_method();

    std::shared_ptr<Woman> w3 = Woman::create_shared(13);
    w3->test_method();
}