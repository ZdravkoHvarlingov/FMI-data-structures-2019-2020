#pragma once

#include <vector>

template <typename T>
class Stack
{
public:
	void Push(const T& element);
	void Pop();
	const T& GetTop() const;
	bool IsEmpty() const;

private:
	std::vector<T> elements;
};

template<typename T>
inline void Stack<T>::Push(const T& element)
{
	elements.push_back(element);
}

template<typename T>
inline void Stack<T>::Pop()
{
	elements.pop_back();
}

template<typename T>
inline const T& Stack<T>::GetTop() const
{
	return elements.back();
}

template<typename T>
inline bool Stack<T>::IsEmpty() const
{
	return elements.size() == 0;
}
