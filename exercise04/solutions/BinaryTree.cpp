// BinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ExpressionTree.h"

struct BinNode
{
	int num;
	BinNode* left, * right;
};


void TraverseInOrder(BinNode* node)
{
	if (node == nullptr)
	{
		return;
	}

	TraverseInOrder(node->left);
	std::cout << node->num << " ";
	TraverseInOrder(node->right);
}


void TraversePreOrder(BinNode* node)
{
	if (node == nullptr)
	{
		return;
	}

	std::cout << node->num << " ";
	TraversePreOrder(node->left);
	TraversePreOrder(node->right);
}


void TraversePostOrder(BinNode* node)
{
	if (node == nullptr)
	{
		return;
	}

	TraversePostOrder(node->left);
	TraversePostOrder(node->right);
	std::cout << node->num << " ";
}


int SumOfAllNodes(BinNode* node)
{
	if (node == nullptr)
	{
		return 0;
	}

	return SumOfAllNodes(node->left) + node->num + SumOfAllNodes(node->right);
}


int NumberOfLeaves(BinNode* node)
{
	// Empty tree has no leaves!
	if (node == nullptr)
	{
		return 0;
	}

	// Tree is just a leaf!
	if (node->left == nullptr && node->right == nullptr)
	{
		return 1;
	}

	//Complex tree
	return NumberOfLeaves(node->left) + NumberOfLeaves(node->right);
}


int main()
{
	std::string expr = "((10 * ((40 - 20) * 3)) / 3)";
	std::cout << CalculateStringExpression(expr) << std::endl;
}
