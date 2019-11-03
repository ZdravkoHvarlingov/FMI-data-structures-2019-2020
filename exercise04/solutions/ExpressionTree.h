#pragma once
#include <string>
#include <sstream>


struct ExpressionTreeNode
{
	double number;
	//! will mean the node is number node, available operations: +, -, *, /
	char sign;
	ExpressionTreeNode* left, *right;

	ExpressionTreeNode(double number = -1, char sign = '!', ExpressionTreeNode *left = nullptr, ExpressionTreeNode *right = nullptr)
		: number(number), sign(sign), left(left), right(right)
	{}
};


void DeleteExpressionTree(ExpressionTreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}

	DeleteExpressionTree(node->left);
	DeleteExpressionTree(node->right);

	delete node;
}


double CalcValue(double num1, double num2, char sign)
{
	if (sign == '+')
	{
		return num1 + num2;
	}
	if (sign == '-')
	{
		return num1 - num2;
	}
	if (sign == '*')
	{
		return num1 * num2;
	}
	if (sign == '/')
	{
		return num1 / num2;
	}

	return -1;
}


double CalculateExpressionTree(ExpressionTreeNode* node)
{
	//Node should never be nullptr
	if (node->sign != '!')
	{
		double leftValue = CalculateExpressionTree(node->left);
		double rightValue = CalculateExpressionTree(node->right);

		return CalcValue(leftValue, rightValue, node->sign);
	}

	return node->number;
}


ExpressionTreeNode* ConstructionHelper(std::stringstream& str)
{
	if (str.peek() == '(')
	{
		str.get(); //We get the bracker
		ExpressionTreeNode* leftSubTree = ConstructionHelper(str);

		//We get the space
		str.get();
		char sign = str.get();
		str.get();

		ExpressionTreeNode* rightSubTree = ConstructionHelper(str);
		str.get(); //Remove the closing bracket

		return new ExpressionTreeNode(-1, sign, leftSubTree, rightSubTree);
	}

	double num;
	str >> num;
	return new ExpressionTreeNode(num);
}


// We have the following grammar for exression:
// <expr> := number(10, 15, 13.2, etc..)
// <sign> := +, -, *, /
// <expr> := (<expr> <sign> <expr>)
ExpressionTreeNode* ConstructExpressionTree(const std::string& expr)
{
	std::stringstream str(expr);
	return ConstructionHelper(str);
}


double CalculateStringExpression(const std::string& expr)
{
	ExpressionTreeNode* expressionTree = ConstructExpressionTree(expr);
	double res = CalculateExpressionTree(expressionTree);

	DeleteExpressionTree(expressionTree);

	return res;
}

