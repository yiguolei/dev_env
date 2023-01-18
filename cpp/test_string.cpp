#include <iostream>
#include <string>


int main() {
    std::string a;
    std::cout << a.empty() << std::endl;
    std::cout << a.size() << std::endl;
    a = "123";

    std::cout << a.empty() << std::endl;
    std::cout << a.size() << std::endl;
}