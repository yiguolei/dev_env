#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <list>

enum PrimitiveType {
    TYPE1,
    TYPE2,
    TYPE3
};

enum DataTypeTType {
    DataTypeTType1,
    DataTypeTType2,
    DataTypeTType3
};

class StringParser {
public:
    template<PrimitiveType pt>
    static void func1() {
        std::cout << "func1: " << pt << std::endl;
    }
};

template <PrimitiveType Pt, DataTypeTType Dt>
class DataType {
public:
    DataType() {
        std::cout << Pt << "," << Dt << std::endl;
    }
    static constexpr PrimitiveType getPtype() {
        
        if constexpr (Dt == DataTypeTType1) {
            return TYPE1;
        } else if constexpr (Dt == DataTypeTType2) {
            return TYPE2;
        } else {
            return TYPE3;
        }
    }

    void dtFunc() {
        StringParser::func1<getPtype()>();
    }
};

int main() {
    DataType<TYPE1, DataTypeTType2> dataType;
    dataType.dtFunc();
}