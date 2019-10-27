#pragma once
#include <vector>
#include <algorithm>


void InsertionSort(std::vector<int> &numbers)
{
	for (size_t i = 1; i < numbers.size(); i++)
	{
		int numToPut = numbers[i];
		int j = i - 1;
		while (j >= 0 && numbers[j] > numToPut)
		{
			numbers[j + 1] = numbers[j];
			--j;
		}

		numbers[j + 1] = numToPut;
	}
}


void BubleSort(std::vector<int> &numbers)
{
	for (size_t i = 0; i < numbers.size() - 1; i++)
	{
		for (size_t j = 0; j < numbers.size() - 1 - i; j++)
		{
			if (numbers[j] > numbers[j + 1])
			{
				std::swap(numbers[j], numbers[j + 1]);
			}
		}
	}
}


void SelectionSort(std::vector<int> &numbers)
{
	for (size_t i = 0; i < numbers.size() - 1; i++)
	{
		for (size_t j = i + 1; j < numbers.size() - 1; j++)
		{
			if (numbers[i] > numbers[j])
			{
				std::swap(numbers[i], numbers[j]);
			}
		}
	}
}
