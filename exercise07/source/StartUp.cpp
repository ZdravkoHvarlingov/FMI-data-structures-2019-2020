// BSearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BinSearchTree.h"


int main()
{
	BinSearchTree<int> nums;
	for (size_t i = 0; i < 11; i++)
	{
		nums.Insert(11 - i);
	}

	std::cout << nums.GetNumberOfElements() << std::endl;
	auto elements = nums.GetElements();
	for (int element : elements)
	{
		std::cout << element << " ";
	}
	std::cout << std::endl;

	std::cout << nums.Contains(2) << std::endl;
	std::cout << nums.Contains(12) << std::endl;
	std::cout << nums.Contains(3) << std::endl;

	
	nums.Delete(2);
	nums.Delete(11);
	std::cout << nums.GetNumberOfElements() << std::endl;
	elements = nums.GetElements();
	for (int element : elements)
	{
		std::cout << element << " ";
	}
	std::cout << std::endl;
	std::cout << nums.Contains(2) << std::endl;
	std::cout << nums.Contains(3) << std::endl;
}
