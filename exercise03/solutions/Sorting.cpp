// Sorting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Algorithms.h"

struct Occurrences
{
	int number, occurrences;
};


std::vector<Occurrences> FindNumberOfOccurences(std::vector<int> nums)
{
	InsertionSort(nums);
	std::vector<Occurrences> result;

	if (nums.size() == 0)
	{
		return result;
	}

	int count = 1;
	for (size_t i = 1; i < nums.size(); i++)
	{
		if (nums[i - 1] != nums[i])
		{
			result.push_back({ nums[i - 1], count });
			count = 0;
		}

		++count;
	}

	result.push_back({ nums[nums.size() - 1], count });
	return result;
}


std::vector<int> RemoveDuplicates(std::vector<int> nums)
{
	InsertionSort(nums);
	std::vector<int> res;

	if (nums.size() == 0)
	{
		return res;
	}

	res.push_back(nums[0]);
	for (size_t i = 1; i < nums.size(); i++)
	{
		if (nums[i] != res[res.size() - 1])
		{
			res.push_back(nums[i]);
		}
	}

	return res;
}


bool AreTheSame(std::vector<int> first, std::vector<int> second)
{
	if (first.size() != second.size())
	{
		return false;
	}

	InsertionSort(first);
	InsertionSort(second);

	for (size_t i = 0; i < first.size(); i++)
	{
		if (first[i] != second[i])
		{
			return false;
		}
	}

	return true;
}


struct Couple
{
	int a, b;
};


std::pair<bool, Couple> HasTwoNumbersWithSumC(std::vector<int> nums, int c)
{
	InsertionSort(nums);
	int i = 0;
	int j = nums.size() - 1;
	
	while (i < j)
	{
		if (nums[i] + nums[j] == c)
		{
			return std::make_pair<bool, Couple>(true, { nums[i], nums[j] });
		}
		else if (nums[i] + nums[j] > c)
		{
			--j;
		}
		else
		{
			++i;
		}
	}

	return std::make_pair<bool, Couple>(false, { -1, -1 });
}


int main()
{
	std::vector<int> nums = { 3, 1, -1, 10, 25, 20, 1, 3 };
	auto occurences = FindNumberOfOccurences(nums);
	for (size_t i = 0; i < occurences.size() - 1; i++)
	{
		std::cout << occurences[i].number << ": " << occurences[i].occurrences << std::endl;
	}

	auto noDuplicates = RemoveDuplicates(nums);
	for (size_t i = 0; i < noDuplicates.size(); i++)
	{
		std::cout << noDuplicates[i] << " ";
	}
	std::cout << std::endl;
}
