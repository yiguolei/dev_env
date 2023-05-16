#include <iostream>
#include <memory>
#include <vector>

int main() {

    int32_t a = 2000000000;
    int32_t b = 4;

    int64_t c = a * b;
    std::cout << c << std::endl;

    int64_t d = (int64_t)a * b;
    std::cout << d << std::endl;

    int64_t e = (int64_t)(a * b);
    std::cout << e << std::endl;
}