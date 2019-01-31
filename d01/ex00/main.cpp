#include "Pony.hpp"
#include <iostream>
#include <cstdlib>

void ponyOnTheHeap(void)
{
	const Pony*	lil_pony = new Pony("Shetland", "Carl", true);
	delete lil_pony;
}

void ponyOnTheStack(void)
{
	const Pony	lil_pony("Garrano", "Carl", false);;
}


int		main( void )
{
	ponyOnTheHeap();
	ponyOnTheStack();
	system("leaks -q pony");
	return 0;
}


