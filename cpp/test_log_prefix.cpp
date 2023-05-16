#include <iostream>
#include <string> 
#include <type_traits>

template <typename T, typename = void>
struct has_log_name : std::false_type {};

template <typename T>
struct has_log_name<T, std::void_t<decltype(T::log_name), std::enable_if_t<std::is_same<decltype(T::log_name), std::string>::value>>> : std::true_type {};

class Person {
public:
    std::string log_name = "abc";
};

class Man : public Person {
public: 
    std::string name = "";
};

class Animal {
public:
    std::string kind = "xxx";
};

int main() {
    Man p;
    Animal a;
    std::cout << has_log_name<std::decay_t<decltype(p)>>::value << std::endl;
    std::cout << has_log_name<std::decay_t<decltype(a)>>::value << std::endl;
}