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
        std::cout << "test_methodMan is called" << std::endl;
    }
    int age_ = 0;
};

int main() {

    std::vector<int> a;
    a.push_back(0);
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    int i = 0;
    int j = a[i++];
    std::cout << i << " " << j << std::endl;

    std::vector<Man> v1;
    v1.push_back(Man(1,12));
}