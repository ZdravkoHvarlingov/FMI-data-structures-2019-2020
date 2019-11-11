// LinkedListIterator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedList.h"


bool IsEven(int num)
{
	return num % 2 == 0;
}

int main()
{
	LinkedList ll;
	for (size_t i = 0; i < 10; i++)
	{
		ll.add(i);
	}

	for (LinkedList::FilterIterator it = ll.begin_filter(IsEven); it != ll.end_filter(IsEven); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
    std::cout << "Hello World!\n";
}
