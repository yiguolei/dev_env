#include <iostream>
#include <string> 
#include <type_traits>
#include <vector>

enum EnumTest{
    e1,
    e2,
};
/*
class WhichDataType {
public:
    static bool get_value(EnumTest e) {
        if (e == e1) {
            return false;
        } else {
            return true;
        }
    }
};


int main2(int argc, char** argv) {

    EnumTest e;
    if (argc > 1) {
        e = EnumTest::e1;
    } else {
        e = EnumTest::e2;
    }
    static_assert(WhichDataType::get_value(EnumTest::e1) == false);
    std::cout << WhichDataType::get_value(EnumTest::e1) << std::endl;
}
*/

int main() {
    std::vector<int> a(2);
    a.push_back(1);
    a.push_back(2);
    std::cout << a.size() << std::endl;
}