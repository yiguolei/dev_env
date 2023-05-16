#include <iostream>
#include <string> 
#include <type_traits>

enum TestEnum {
    e1 = 10,
    e2 = 11,
    e3 = 19
};


int main() {

    TestEnum v1 = TestEnum::e2;
    int16_t a = static_cast<int16_t>(v1);
    std::cout << a << std::endl;
    std::cout << v1 << std::endl;
    if (v1 == 11) {
        std::cout << "aaa" << std::endl;
    } else {
        std::cout << "bbb" << std::endl;
    }
    TestEnum v2 = static_cast<TestEnum>(a);
    std::cout << v2 << std::endl;
       if (v2 == TestEnum::e2) {
        std::cout << "aaa" << std::endl;
    } else {
        std::cout << "bbb" << std::endl;
    }
}