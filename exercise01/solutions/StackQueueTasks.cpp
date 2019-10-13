// StackQueueTasks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Stack.hpp"
#include "Queue.hpp"
#include <iostream>
#include <string>


template <typename T>
void ReverseVector(std::vector<T> &elements)
{
	Stack<T> st;
	for (size_t i = 0; i < elements.size(); i++)
	{
		st.Push(elements[i]);
	}
	for (size_t i = 0; i < elements.size(); i++)
	{
		elements[i] = st.GetTop(); st.Pop();
	}
}


void ReverseString(std::string& str)
{
	Stack<char> st;
	for (size_t i = 0; i < str.length(); i++)
	{
		st.Push(str[i]);
	}
	for (size_t i = 0; i < str.length(); i++)
	{
		str[i] = st.GetTop(); st.Pop();
	}
}


bool AreBracketsCorrect(const std::string& str)
{
	Stack<char> brackets;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			brackets.Push('(');
		}
		else if (str[i] == ')' && brackets.IsEmpty())
		{
			return false;
		}
		else if (str[i] == ')')
		{
			brackets.Pop();
		}
	}

	return brackets.IsEmpty();
}


template <typename T>
void InsertAtTheBottom(Stack<T>& st, const T &element)
{
	if (st.IsEmpty())
	{
		st.Push(element);
		return;
	}

	T top = st.GetTop();
	st.Pop();
	InsertAtTheBottom(st, element);
	st.Push(top);
}


template <typename T>
void ReverseStack(Stack<T>& st)
{
	if (st.IsEmpty())
	{
		return;
	}

	T top = st.GetTop();
	st.Pop();
	ReverseStack(st);
	InsertAtTheBottom(st, top);
}


template <typename T>
void ReverseQueue(Queue<T>& q)
{
	if (q.IsEmpty())
	{
		return;
	}

	T front = q.GetFront();
	q.Pop();
	ReverseQueue(q);
	q.Push(front);
}


int main()
{
    std::cout << "Hello World!\n";

	Queue<int> st;
	for (size_t i = 0; i < 10; i++)
	{
		st.Push(i);
	}
	ReverseQueue(st);
	while (!st.IsEmpty())
	{
		std::cout << st.GetFront() << std::endl;
		st.Pop();
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
