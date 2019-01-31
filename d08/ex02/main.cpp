#include "mutantstack.hpp"

void	print_stack(MutantStack <int> const & mstack)
{
	for (std::stack<int> dump = mstack; !dump.empty(); dump.pop())
		std::cout << dump.top() << ' ';

	std::cout << std::endl;

	std::cout << "(" << mstack.size() << " elements)\n";
}


int main()
{


	std::cout << GREEN << "..................... Testing basics ...................." << NORMAL << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	mstack.pop();

	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737); //[...]
	mstack.push(0);


	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	try
	{
		--it;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::stack<int> s(mstack);
		std::cout << GREEN << ".................... Testing copy ......................" << NORMAL << std::endl;


	{
		std::cout << CYAN << "... Creating new stack ..." << NORMAL << std::endl;
		MutantStack<int> mstack2;
		mstack2.push(99);
		mstack2.push(98);
		mstack2.push(97);
		print_stack(mstack2);
		std::cout << CYAN << "... Creating its copy and printing copy ..." << NORMAL << std::endl;

		MutantStack<int> mstack3(mstack2);
		print_stack(mstack3);
		std::cout << GREEN << "..................... And it works! ...................." << NORMAL << std::endl << std::endl;

	}

		std::cout << GREEN << ".................. Testing assignment .................." << NORMAL << std::endl << std::endl;

	{

		std::cout << CYAN << "... Creating new stack and printing ..." << NORMAL << std::endl;
		MutantStack<int> mstack2;
		mstack2.push(1);
		mstack2.push(2);
		mstack2.push(3);
		print_stack(mstack2);


		std::cout << CYAN << "... Creating another stack and printing ..." << NORMAL << std::endl;


		MutantStack<int> mstack3;
		mstack3.push(4);
		mstack3.push(5);
		mstack3.push(6);
		print_stack(mstack3);

		mstack3 = mstack2;
		std::cout << CYAN << "... Assignment operator for 2 new stacks: ..." << NORMAL << std::endl;
		print_stack(mstack3);

		std::cout << GREEN << "..................... And it works! ...................." << NORMAL << std::endl << std::endl;

		std::stack<int> s1(mstack3);
		std::stack<int> s2(mstack2);
	}

	return (0);
}