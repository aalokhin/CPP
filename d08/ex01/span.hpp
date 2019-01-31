#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <set>

#include <stdexcept>
#include <cstdlib>


#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define PINK "\033[1;35m"
#define GREEN "\033[1;32m"
#define NORMAL "\033[0m"
#define BLUE "\033[1;34m"

class Span
{
	public:
		Span();
		Span(unsigned int N);
		Span(Span const & copy);
		~Span();
		Span & operator=(Span const & obj);

		void addNumber(int n);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;


		template <typename Range>

		void addRangeNumbers(Range start, Range end)
		{
			Range i = start;
			while (i != end)
			{
				addNumber(*i);
				i++;
			}

		}
		unsigned int getSize() const;

		void printSpan();
	private:
		std::vector<int> arr;

		unsigned int    _size;
};

#endif
