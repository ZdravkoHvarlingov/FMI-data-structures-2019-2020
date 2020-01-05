#pragma once

#include <vector>
using std::vector;

class Heap
{
public:
	Heap(bool = false);
	void Push(int element);
	int Pop();
	int Peek() const;
	void Heapify(const vector<int>&);
	size_t GetSize() const;

private:
	vector<int> tree;
	bool isMax;

	void SiftUp(int);
	void SiftDown(int);
	int GetParent(int);
	int GetLeftChild(int);
	int GetRightChild(int);
};
