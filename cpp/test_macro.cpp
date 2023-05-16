#include <iostream>
#include <string>

#define M1(p1) std::cout << p1 << std::endl;

#define M2(P1) M1(P1)

#undef M1



int main() {
    M2(123);
}