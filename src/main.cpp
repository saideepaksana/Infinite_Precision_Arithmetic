#include "infinite_precision.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    using namespace InfiniteArithmetic;
    std::string s1 = argv[1];
    std::string s2 = argv[2];
    std::string s3 = argv[3];
    std::string s4 = argv[4];

    if (s1 == "int")
    {
        Integer a = Integer(s3);
        Integer b = Integer(s4);
        if (s2 == "add")
        {
            Integer d = a + b;
            d.print();
        }
        if (s2 == "sub")
        {
            Integer d = a - b;
            d.print();
        }
        if (s2 == "mul")
        {
            Integer d = a * b;
            d.print();
        }
        if (s2 == "div")
        {
            Integer d = a / b;
            d.print();
        }
    }

    if (s1 == "float")
    {
        Float a = Float(s3);
        Float b = Float(s4);
        if (s2 == "add")
        {
            Float d = a + b;
            d.print();
        }
        if (s2 == "sub")
        {
            Float d = a - b;
            d.print();
        }
        if (s2 == "mul")
        {
            Float d = a * b;
            d.print();
        }
        if (s2 == "div")
        {
            Float d = a / b;
            d.print();
        }
    }
    return 0;
}
