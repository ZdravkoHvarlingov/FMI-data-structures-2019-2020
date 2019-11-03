// BinTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

struct TreeNode 
{
	int value;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int value = 0, TreeNode *left = nullptr, TreeNode *right = nullptr)
		: value(value), left(left), right(right)
	{}
};


void PrintPreOrder(TreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	
	// Processing the current node 
	std::cout << node->value << " ";
	PrintPreOrder(node->left);
	PrintPreOrder(node->right);
}


void PrintInOrder(TreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}

	PrintInOrder(node->left);

	// Processing the current node 
	std::cout << node->value << " ";

	PrintInOrder(node->right);
}


void DeleteTree(TreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}

	DeleteTree(node->left);
	DeleteTree(node->right);

	std::cout << "NODE deleted: " << node->value << std::endl;
	delete node;
}


void InsertNode(int value, std::string path, TreeNode* node)
{
	if (path == "")
	{
		node = new TreeNode(value);
		return;
	}

	if (path[0] == 'L')
	{
		InsertNode(value, path.substr(1, path.length() - 1), node->left);
	}
	else
	{
		InsertNode(value, path.substr(1, path.length() - 1), node->right);
	}
}

int main()
{
	TreeNode* root = new TreeNode(100, 
		new TreeNode(200, new TreeNode(1), new TreeNode(-10)),
		new TreeNode(3, 
			new TreeNode(4, 
				new TreeNode(11), nullptr), nullptr));

	DeleteTree(root);
/*
	PrintInOrder(root);
	std::cout << std::endl;
	DeleteTree(root);*/

	TreeNode* root2 = nullptr;
	InsertNode(10, "", root2);
	InsertNode(11, "L", root2);
	InsertNode(12, "R", root2);
	InsertNode(15, "LR", root2);
	PrintInOrder(root2);

	DeleteTree(root2);
}
