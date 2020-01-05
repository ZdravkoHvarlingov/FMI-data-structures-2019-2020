#include "stdafx.h"
#include "Heap.h"
#include <exception>

Heap::Heap(bool isMax)
	: isMax(isMax)
{
	tree.push_back(0);
}

//O(logn)
void Heap::Push(int element)
{
	if (isMax)
	{
		element = -element;
	}

	tree.push_back(element);
	SiftUp(tree.size() - 1);
}

//O(logn)
int Heap::Pop()
{
	if (tree.size() == 1)
	{
		throw "No tree elements!";
	}

	int returnValue = isMax? -tree[1] : tree[1];
	tree[1] = tree[tree.size() - 1];
	tree.pop_back();
	SiftDown(1);

	return returnValue;
}

int Heap::Peek() const
{
	return isMax? -tree[1] : tree[1];
}

//O(n)
void Heap::Heapify(const vector<int>& numbers)
{
	tree.clear();
	tree.reserve(numbers.size() + 1);
	tree.push_back(0);

	//O(n)
	for (size_t i = 0; i < numbers.size(); ++i)
	{
		tree.push_back(isMax? -numbers[i] : numbers[i]);
	}

	//O(n)
	//amount / 2 gives us the first node with atleast one child
	for (size_t i = tree.size() / 2; i >= 1; --i)
	{
		SiftDown(i);
	}
}

size_t Heap::GetSize() const
{
	return tree.size() - 1;
}

//O(logn)
void Heap::SiftUp(int index)
{
	int parent = GetParent(index);
	if (index == 1 || tree[parent] < tree[index])
	{
		return;
	}

	std::swap(tree[index], tree[parent]);
	SiftUp(parent);
}

//O(logn)
void Heap::SiftDown(int index)
{
	int leftChild = GetLeftChild(index);
	int rightChild = GetRightChild(index);
	if (index >= tree.size() || leftChild >= tree.size())
	{
		return;
	}

	int minIndex = leftChild;
	if (rightChild < tree.size() && tree[minIndex] > tree[rightChild])
	{
		minIndex = rightChild;
	}
	
	if (tree[minIndex] < tree[index])
	{
		std::swap(tree[minIndex], tree[index]);
		SiftDown(minIndex);
	}
}

int Heap::GetParent(int index)
{
	return index / 2;
}

int Heap::GetLeftChild(int index)
{
	return index * 2;
}

int Heap::GetRightChild(int index)
{
	return index * 2 + 1;
}
