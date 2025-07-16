#include "../include/infinite_precision.hpp"

#include <algorithm>


namespace InfiniteArithmetic
{
    Float Float::operator+(Float b)
    {
        std::string c;

        if (sign == 0 && b.sign == 0)
        {
            Float dummy = *this;

            if (dummy.pb < b.pb)
            {
                for (int i = 0; i < b.pb - dummy.pb; i++)
                {
                    dummy.str.insert(0, 1, '0');
                }
            }

            if (dummy.pb > b.pb)
            {
                for (int i = 0; i < dummy.pb - b.pb; i++)
                {
                    b.str.insert(0, 1, '0');
                }
            }

            if (dummy.pa < b.pa)
            {
                for (int i = 0; i < b.pa - dummy.pa; i++)
                {
                    dummy.str.push_back('0');
                }
            }

            if (dummy.pa > b.pa)
            {
                for (int i = 0; i < dummy.pa - b.pa; i++)
                {
                    b.str.push_back('0');
                }
            }

            dummy = Float(dummy.str);
            b = Float(b.str);

            if (dummy.str.size() == b.str.size())
            {
            }

            int y = dummy.str.size() - 1 - dummy.point_position;
            dummy.str.erase(dummy.point_position, 1);
            b.str.erase(b.point_position, 1);
            Integer add = Integer(dummy.str) + Integer(b.str);

            add.str.insert(add.str.size() - y, 1, '.');
            c = add.str;

            return Float(c);
        }

        if (sign == 0 && b.sign == 1)
        {

            Float dummy = *this;
            b.str.erase(0, 1);
            b = Float(b.str);

            return dummy - b;
        }

        if (sign == 1 && b.sign == 0)
        {
            Float dummy = *this;
            dummy.str.erase(0, 1);
            dummy = Float(dummy.str);
            return b - dummy;
        }

        if (sign == 1 && b.sign == 1)
        {
            Float dummy = *this;
            dummy.str.erase(0, 1);
            dummy = Float(dummy.str);
            b.str.erase(0, 1);
            b = Float(b.str);
            Float t = dummy + b;
            t.str.insert(0, 1, '-');

            return (Float(t.str));
        }

        return Float("0");
    }

    Float Float::operator-(Float b)
    {
        std::string c;

        if (sign == 0 && b.sign == 0)
        {
            Float dummy = *this;

            if (dummy.pb < b.pb)
            {
                for (int i = 0; i < b.pb - dummy.pb; i++)
                {
                    dummy.str.insert(0, 1, '0');
                }
            }

            if (dummy.pb > b.pb)
            {
                for (int i = 0; i < dummy.pb - b.pb; i++)
                {
                    b.str.insert(0, 1, '0');
                }
            }

            if (dummy.pa < b.pa)
            {
                for (int i = 0; i < b.pa - dummy.pa; i++)
                {
                    dummy.str.push_back('0');
                }
            }

            if (dummy.pa > b.pa)
            {
                for (int i = 0; i < dummy.pa - b.pa; i++)
                {
                    b.str.push_back('0');
                }
            }

            dummy = Float(dummy.str);
            b = Float(b.str);

            if (dummy.str.size() == b.str.size())
            {
            }

            int y = dummy.str.size() - 1 - dummy.point_position;

            dummy.str.erase(dummy.point_position, 1);
            b.str.erase(b.point_position, 1);
            Integer sub = Integer(dummy.str) - Integer(b.str);

            sub.str.insert(sub.str.size() - y, 1, '.');
            c = sub.str;
            return Float(c);
        }

        if (sign == 0 && b.sign == 1)
        {
            Float dummy = *this;
            b.str.erase(0, 1);
            b = Float(b.str);

            return dummy + b;
        }

        if (sign == 1 && b.sign == 0)
        {
            Float dummy = *this;
            dummy.str.erase(0, 1);
            dummy = Float(dummy.str);
            Float t = dummy + b;
            t.str.insert(0, 1, '-');

            return (Float(t.str));
        }

        if (sign == 1 && b.sign == 1)
        {
            Float dummy = *this;
            dummy.str.erase(0, 1);
            dummy = Float(dummy.str);
            b.str.erase(0, 1);
            b = Float(b.str);

            return b - dummy;
        }

        return Float("0");
    }

    Float Float::operator*(Float b)
    {
        std::string c;

        if (sign == 0 && b.sign == 0)
        {
            Float dummy = *this;
            int y1 = dummy.str.size() - 1 - dummy.point_position;
            int y2 = b.str.size() - 1 - b.point_position;
            dummy.str.erase(dummy.point_position, 1);
            b.str.erase(b.point_position, 1);
            Integer mul = Integer(dummy.str) * Integer(b.str);
        a:
            if (mul.str.size() > y1 + y2)
            {
                mul.str.insert(mul.str.size() - y1 - y2, 1, '.');
            }

            else
            {
                mul.str.insert(0, 1, '0');
                goto a;
            }
            c = mul.str;
            return Float(c);
        }

        if (sign == 1 && b.sign == 0)
        {
            Float dummy = *this;
            dummy.str.erase(0, 1);
            dummy = Float(dummy.str);
            Float t = dummy * b;
            t.str.insert(0, 1, '-');

            return (Float(t.str));
        }

        if (sign == 0 && b.sign == 1)
        {
            Float dummy = *this;
            b.str.erase(0, 1);
            b = Float(b.str);
            Float t = dummy * b;
            t.str.insert(0, 1, '-');
            return (Float(t.str));
        }

        if (sign == 1 && b.sign == 1)
        {
            Float dummy = *this;
            dummy.str.erase(0, 1);
            dummy = Float(dummy.str);
            b.str.erase(0, 1);
            b = Float(b.str);
            Float t = dummy * b;

            return t;
        }

        return Float("0");
    }

    Float Float::operator/(Float b)
    {
        std::string c;
        if (sign == 0 && b.sign == 0)
        {

            Float dummy = *this;
            int y1 = dummy.str.size() - 1 - dummy.point_position;
            int y2 = b.str.size() - 1 - b.point_position;
            dummy.str.erase(dummy.point_position, 1);
            b.str.erase(b.point_position, 1);

            for (int i = 0; i < 1000; i++)
            {
                dummy.str.push_back('0');
            }

            Integer c = Integer(dummy.str) / Integer(b.str);
            c.str.insert(c.str.size() - 1000 - y1 + y2, 1, '.');

            return Float(c.str);
        }

        if (sign == 0 && b.sign == 1)
        {
            Float dummy = *this;
            b.str.erase(0, 1);
            b = Float(b.str);
            Float t = dummy / b;
            t.str.insert(0, 1, '-');

            return (Float(t.str));
        }

        if (sign == 1 && b.sign == 0)
        {
            Float dummy = *this;
            dummy.str.erase(0, 1);
            dummy = Float(dummy.str);
            Float t = dummy / b;
            t.str.insert(0, 1, '-');

            return (Float(t.str));
        }

        if (sign == 1 && b.sign == 1)
        {
            Float dummy = *this;
            dummy.str.erase(0, 1);
            dummy = Float(dummy.str);
            b.str.erase(0, 1);
            b = Float(b.str);
            Float t = dummy / b;

            return t;
        }

        return Float("0");
    }
}