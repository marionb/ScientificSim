#include <iostream>

enum Z2 { Plus, Minus };

/**
*   This function is not programed very nice but I did not realy have abetter idea on how to overload the function only using a different returne type.
*   What I tried was working with identity_element<T>() for all of the T not equalt to Z2 and call identity_element() for the rest. But ist did not
*   realy work as I have to figure out the specific type and then distinguish. Another idea was to just definr Z2 {Plus, Minus} then I don't have
*   to overload the function at all as identity_element() would automaticaly giveme the identity element for Z2 as it is (but I guess this is not the point)
*   PRE:    a is a dummy variable determining the type and which function touse
*   POST:   return the identity element of the type given ba a.
*/
template<class T>
T identity_element(T a) { return T(1); }

Z2 identity_element(Z2 a) { return Plus;}

// to be written: overload the previous function for Z2

/**
*   PRE:    a and b have to be part of Z2, meaning either Plus or Minus
*   POST:   The function returnes Plus or Minus depending on the a and b. The function is based on the folowing law:
*                Plus*Plus=Plus
*                Minus*Minue=Plus
*                Minus*Plus=Minus
*                Plus*Minus=Minus
*/
Z2 operator*(Z2 a, Z2 b)
{
    if(a==b)
    {
        return Plus;
    }
    return Minus;
}

/**
*   PRE:    function takes an ostream pointer os and an element of Z2
*   POST:   this function overloads the ostream << operator for the type Z2
*/
std::ostream& operator <<(std::ostream& os, Z2 a)
{
    if(a==Plus)
    {
        os<<"+";
    }
    else{ os<<"-";}

    return os;
}

/**
*   PRE:    a must be of a type T which can be multiplied by -1 and +1; b has to be of typpe Z2 (either Plus of Minus)
*   POST:   the function returnes the value of a*b=-a (if b==Minus ) and +a (else)
*/
template<class T>
T operator*(T a, Z2 b)
{
    return b*a;
}

/**
*   PRE:    a must be of a type T which can be multiplied by -1 and +1; b has to be of typpe Z2 (either Plus of Minus)
*   POST:   the function returnes the value of a*b=-a (if b==Minus ) and +a (else)
*   REMARK: I inlied this function as it is very short and I am using it in the operator*(T a, Z2 b). I am not sure if this is correct
*/
template<class T>
inline T operator*(Z2 b, T a)
{
    if(b==Plus)
    {
        return a;
    }
    return -a;
}

/**
*   PRE:    a has to be of a type (int, double, float, ...) for which the multiplication of two elements is defined; n is of integer type
*   POST:   the function returnes a^n
*/
template<class T>
T mypow(T a, unsigned int n)
{
    if(n==0)
    {
        return identity_element(a);
    }
    T res= identity_element (a);

    for(int i=1;i<=n;i++)
    {

        res=res*a;
    }
    return res;
}

int main()
{
	// some testing: feel free to add your own!
	std::cout << Plus*Minus << std::endl;
	std::cout << Minus*Plus<< std::endl;
	std::cout << Plus*Plus << std::endl;
	std::cout << Minus*Minus << std::endl;
	std::cout << Plus*-1*Minus << std::endl;
	std::cout << (1.+3.)*mypow(Minus,5) << std::endl;
	for (unsigned i=0; i<7; i++)
	    std::cout << "Plus^" << i << " = " << mypow(Plus,i) << std::endl;
	for (unsigned i=0; i<7; i++)
	    std::cout << "Minus^" << i << " = " << mypow(Minus,i) << std::endl;
	for (unsigned i=0; i<7; i++)
	    std::cout << "2^" << i << " = " << mypow(2.0,i) << std::endl;
	return 0;
}
