// LinkedListIterator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedList.h"


void print_linked_list(LinkedList& ll)
{
	for (LinkedList::Iterator it = ll.begin(); it != ll.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


int main()
{
	LinkedList ll;
	ll.push(10);
	ll.push(11);
	ll.push(12);

	print_linked_list(ll);
}