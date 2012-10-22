#ifndef Z2_HPP_INCLUDED
#define Z2_HPP_INCLUDED

enum Z2 {Plus, Minus};

class Ze2
{
    public:
    Z2 operator* (Z2 a, Z2 b);

    ostream& operator<< (ostream& os, Z2 a);

    template<class T> T operator*(T a,Z2 b);

    template<class T> T operator*(z2 b, T a);
}

#endif // Z2_HPP_INCLUDED
