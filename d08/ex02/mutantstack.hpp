#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <vector>
#include <iostream>
#include <vector>
#include <stack>
#include <iostream>

#include <numeric>
#include <vector>
#include <set>


#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define PINK "\033[1;35m"
#define GREEN "\033[1;32m"
#define NORMAL "\033[0m"
#define BLUE "\033[1;34m"


template <typename T>

class MutantStack : public std::stack <T>
{
  public:
  	typedef typename std::deque<T>::iterator iterator;
	MutantStack(){};
	MutantStack(unsigned int n);
	MutantStack  & operator=(MutantStack const & assignment) {

		this->c = assignment.c;
		return *this;
	}
	~MutantStack(){};

	MutantStack(MutantStack const & copy)
	{ this->c = copy.c; }
	
	iterator begin() {
		return std::begin(this->c);
	}
	iterator end(){
		return std::end(this->c);
	}

  private:

};

#endif



