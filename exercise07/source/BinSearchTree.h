#pragma once
#include <vector>
#include <algorithm>


// Contains only unique elements
template<typename T>
class BinSearchTree
{
private:
	struct Node
	{
		T value;
		Node* left, * right;

		Node(const T&, Node* = nullptr, Node* = nullptr);
	};
public:
	BinSearchTree();
	BinSearchTree(const BinSearchTree<T>& other);
	BinSearchTree<T>& operator=(BinSearchTree<T> other);

	void Insert(const T&);
	void Delete(const T&);
	bool Contains(const T&) const;
	std::vector<T> GetElements() const;
	int GetNumberOfElements() const;

	~BinSearchTree();

private:

	void PerformInOrderTraversal(Node*, std::vector<T>&) const;
	void DeleteHelper(Node*);
	void CopyHelper(Node*, Node*&);
	void InsertHelper(Node*&, const T&);
	void DeleteHelper(Node*&, const T&);
	Node* GetMaxNode(Node*) const;

	int numberOfNodes;
	Node* root;
};


#include "BinSearchTree.tpp"
