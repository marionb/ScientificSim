/* Programming Techniques for Scientific Simulations, HS 2012
 * Exercise 8.2a
 * by Troyer's group, ETH Zurich
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <exception>
#include <stdexcept>

/**
    this function is not realy wokting I get the error
    shadows template param 'class Iterator' ????
*/
template<class Iterator>
class Sorter
{
public:
	virtual void sort(Iterator begin, Iterator end) const = 0;
};

template<class Iterator>
class BubbleSort : public Sorter<Iterator>
{
public:
	void sort(Iterator begin, Iterator end) const
	{
        // http://en.wikipedia.org/wiki/Bubble_sort

        // Complete me!
        Iterator i, j;
        for (i = begin; i != end; i++)
            for (j = begin; j < i; j++)
                if (*i < *j)
                    std::iter_swap(i, j); // or std::swap(*i, *j);

};

template<class Iterator>
class StdSort : public Sorter<Iterator>
{
public:
	void sort(Iterator begin, Iterator end) const
	{
		std::sort(begin, end);
	}
};

template<class Iterator>
class InsertionSort : public Sorter<Iterator>
{
	typedef typename Iterator::value_type value_t;
public:
	void sort(Iterator begin, Iterator end) const
	{
        // http://en.wikipedia.org/wiki/Insertionsort

        // Complete me!
        Iterator min = begin;
        for( Iterator i = begin + 1; i < end; ++i )
            if ( *i < *min )
                min = i;

        std::iter_swap( begin, min);
        while( ++begin < end )
            for( Iterator j = begin; *j < *(j - 1); --j )
                std::iter_swap( (j - 1), j );

};

template<class Iterator>
Sorter<Iterator> * sortingFactory(std::string algorithm)
{
    // Complete me!
    Sorter *srt;
    if(algorithm=="BubbleSort")
    {
        srt=new BubbleSort();
    }
    else if(algorithm=="StdSort")
    {
        srt= new StdSort();
    }

    else if(algorithm=="InsertionSort")
    {
        srt=new InsertionSort();
    }
    else
    {
        throw std::runtime_error("I don't know this function.");
    }

    return srt;



}

typedef double T;
typedef std::vector<T>::iterator iterator_t;

int main(int argc, char ** argv)
{
	if (argc != 2) {
		std::cerr << argv[0] << " <sorting algorithm>" << std::endl;
		exit(1);
	}

	Sorter<iterator_t> *mysort = sortingFactory<iterator_t>(std::string(argv[1]));

    std::cout << "Please insert your sequence of numbers (stop the sequence with Ctrl+D):" << std::endl;
	std::vector<T> foo;
	std::copy(std::istream_iterator<T>(std::cin),
		 std::istream_iterator<T>(),
		 std::back_inserter(foo));

	mysort->sort(foo.begin(), foo.end());

    std::cout << std::endl << "The sorted sequence is:" << std::endl;
	std::copy(foo.begin(), foo.end(), std::ostream_iterator<T>(std::cout, "\n"));
	std::cout << std::endl;

	delete mysort;
	return 0;
}
