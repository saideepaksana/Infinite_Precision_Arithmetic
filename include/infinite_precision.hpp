#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace InfiniteArithmetic
{
    class Integer
    {
        private:
            string str;
            int sign = 0;

        public:
            Integer()
            {
                str = "0";
            }

            Integer(std::string s)
            {
                str = s;
                if (s[0] == '-') sign = 1;
            }

            friend class Float;

            void parse(std::string &s);

            Integer operator+(Integer b);
            Integer operator-(Integer b);
            Integer operator*(Integer b);
            int operator > (Integer b);

            Integer operator / (Integer b);

            void print()
            {
                std::cout << str << std::endl;
            }
    };

    class Float
    {
        private:
            string str;
            int sign = 0;
            size_t point_position = -1;
            int pa, pb;

        public:
            Float(std::string s)
            {
                str = s;
                if (s[0] == '-') sign = 1;

                point_position = str.find('.');

                if (point_position == std::string::npos)
                {
                    str.push_back('.');
                    point_position = str.size() - 1;
                }

                pb = point_position;
                pa = str.size() - point_position - 1;
            }

            Float()
            {
                str = "0.";
                point_position = 1;
                sign = 0;
                pa = 0;
                pb = 1;
            }

            Float operator+(Float b);
            Float operator-(Float b);
            Float operator*(Float b);
            Float operator/(Float b);

            void print()
            {
                std::cout << str << std::endl;
            }
    };

}
