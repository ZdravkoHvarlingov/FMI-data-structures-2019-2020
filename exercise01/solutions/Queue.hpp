#pragma once

#include <vector>

template <typename T>
class Queue
{
public:
	void Push(const T& element);
	void Pop();
	const T& GetFront() const;
	bool IsEmpty() const;

private:
	std::vector<T> elements;
};

template<typename T>
inline void Queue<T>::Push(const T& element)
{
	elements.push_back(T());
	for (size_t i = elements.size() - 1; i > 0; --i)
	{
		elements[i] = elements[i - 1];
	}
	elements[0] = element;
}

template<typename T>
inline void Queue<T>::Pop()
{
	elements.pop_back();
}

template<typename T>
inline const T& Queue<T>::GetFront() const
{
	return elements.back();
}

template<typename T>
inline bool Queue<T>::IsEmpty() const
{
	return elements.size() == 0;
}
