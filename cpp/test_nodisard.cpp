#include <iostream>
#include <string> 
#include <type_traits>

struct B {
    [[nodiscard]] virtual bool foo() { return true; }
};

struct D : B {
    bool foo() override { return false; }
};

int main() {
    D d;
    d.foo();
    (&d)->foo();
    ((B*)&d)->foo();
}