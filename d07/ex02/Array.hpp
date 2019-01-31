
#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template < typename T = int >

class Array
{

private:
	unsigned int 	_size;
	T				*_array;

public:
	class	ExceedsLimits: public std::exception
	{
		public:
			ExceedsLimits(void) {}
			~ExceedsLimits(void) throw() {}
		char const	*what(void) const throw() { return ("Exceed limits");}
	};

	Array<T>(void)
	{
		_array = new T();
		_array = NULL;
		_size = 0;
	}


	Array<T>(unsigned int n)
	{
		_size = n;
		_array = new T[_size];
	
	}

	

	Array<T> (Array< T > const & copy) { *this = copy; }

	~Array<T> ( ) { delete [] _array; }


	Array<T> & operator=(Array const & obj )
	{
		delete _array;

		_size = obj._size;

		_array = new T [_size];



		for (unsigned int i = 0; i < _size; i++)
			_array[i] = obj._array[i];

		return *this;
	}

	void setElement(T elem, unsigned int n)
	{
		this->_array[n] = elem;
	}

	T 			&operator[]( unsigned int n )  throw(ExceedsLimits)
	{
		if ( !_array || n >= _size )
			 throw(ExceedsLimits());
		return _array[n];

	}

	unsigned int	size( void ) const
	{
		return _size;
	}

};

#endif
