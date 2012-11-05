/*
*   I don't realy understantd the concept of this class structure
*/
#include <iostream>

class Z2 {
public:

    static Z2 Plus;
    static Z2 Minus;

    //constructor
    Z2() : val_(Plus.val_) { }

    Z2& operator *= (const Z2& rhs)
    {
        return *this;
    }

    Z2 operator * (Z2 rhs)
    {

    }

    friend std::ostream& operator<<(std::ostream&, Z2);
    template <class T> friend T operator * (T, Z2);
    template <class T> friend T operator * (Z2, T);

private:
    Z2(int val) : val_(val) { }

    int val_;
};

/// Z2 members =================================

// to be completed: declaration of static members
Z2 Z2::Plus = 1; // definition outside class declaration
Z2 Z2::Minus = -1;

std::ostream& operator<<(std::ostream& os, Z2 a)
{
    if(a==Z2::Plus)
    {
        os<<"+";
    }
    else{ os<<"-";}

    return os;
}

template <class T>
T operator * (T a, Z2 b)
{
    // to be implemented
}

template <class T>
T operator * (Z2 b, T a)
{
    // to be implemented
}

/// end of Z2 members ==========================



template<class T>
T identity_element() { return T(1); }

// to be written: overload the previous function for Z2


template<class T>
T mypow(T a, unsigned int n)
{
    // to be implemented
}

int main()
{
    // test of constructors
    Z2 minus(Z2::Minus), plus(Z2::Plus);

	// some testing: feel free to add your own!
	std::cout << Plus*minus << std::endl;
	std::cout << plus*-1*Minus << std::endl;
	std::cout << (1.+3.)*mypow(minus,4) << std::endl;
	for (unsigned i=0; i<7; i++)
	    std::cout << "Plus^" << i << " = " << mypow(plus,i) << std::endl;
	for (unsigned i=0; i<7; i++)
	    std::cout << "Minus^" << i << " = " << mypow(minus,i) << std::endl;
	for (unsigned i=0; i<7; i++)
	    std::cout << "2^" << i << " = " << mypow(2.0,i) << std::endl;
	return 0;
}
