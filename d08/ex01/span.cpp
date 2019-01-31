#include "span.hpp"

#include <numeric>


template <typename T>
void				printElement(T &arr_el)
{
  std::cout << PINK << arr_el << NORMAL << " ";
}

template <typename T>
void				iter(std::vector<T> array, unsigned int &length, void (*f)(T &) )
{
	size_t i = 0;
	std::cout << PINK << "Here is an array: " << NORMAL << std::endl;
	while (i < length)
	{
		(*f)(array[i]);
		i++;
	}

	std::cout << std::endl;
}
/*************************************************** Coplien **********************************************************/

Span::Span()
{
	arr.reserve(0);
}

Span::Span(unsigned int N)
{
	if ( N <= 1 )
		throw( std::out_of_range::out_of_range("Error on an attempt to create a span containing less than 2 elements") );
	arr.reserve(N);
	_size = N;

}

Span::Span(Span const & copy)
{
	*this = copy;
}

Span::~Span(){}

Span & Span::operator=(Span const & obj)
{
	if (this != &obj)
	{
		this->arr = obj.arr;
		this->_size = obj.getSize();
	}
	return (*this);
}

unsigned int Span::getSize() const
{
	return this->_size;
}

/*************************************************** Coplien **********************************************************/


void Span::addNumber(int n)
{
	if (arr.size() < _size)
		arr.push_back(n);
	else
		throw std::out_of_range::out_of_range("Error on adding another element, the end of the span has been reached.");
}

unsigned int Span::shortestSpan() const
{
	if (arr.empty() && arr.size() < 2)
		throw std::out_of_range::out_of_range("Less than 2 values in a span");

	int							shortest;
	shortest = 0;


	std::vector<int> tmpArr = this->arr;

	std::sort(tmpArr.begin(),tmpArr.end());


	unsigned int k;
	 k = 0;
/*

	while (k < _size)
	{
		std::cout << tmpArr[k] << " ";
		k++;
	}
	std::cout << std::endl;

*/

	shortest = tmpArr[1] - tmpArr[0];
	k = 0;
	while((k + 1) < (_size ))
	{
		if (abs(tmpArr[k] - tmpArr[k + 1]) < shortest)
			shortest = tmpArr[k + 1] - tmpArr[k];
		k++;
	}
	return shortest;


/*

	if (this->arr.empty() || this->_size == 1)
		throw std::logic_error("Span is empty !");

	std::vector<int> tmp = this->arr;

	std::sort(tmp.begin(),tmp.end());

	std::adjacent_difference(tmp.begin(), tmp.end(), tmp.begin());

	shortest = *std::min_element(tmp.begin(), tmp.end());

	std::cout << RED <<  shortest << NORMAL << std::endl;


*/
	return (shortest);
	
}

unsigned int Span::longestSpan() const
{
	if (arr.size() < 2)
		throw std::out_of_range::out_of_range("Less than 2 values in a span\n");
	
	std::vector<int>::const_iterator min = std::min_element(std::begin(arr), std::end(arr));
	std::vector<int>::const_iterator max = std::max_element(std::begin(arr), std::end(arr));

	return (*max - *min);
}


void Span::printSpan()
{
	std::cout << "Span is size of " << _size << "element(s)\n";
	::iter(this->arr, this->_size, &printElement);
}
