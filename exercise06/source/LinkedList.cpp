#include "LinkedList.h"
#include <algorithm>


LinkedList::LinkedList()
	: head(nullptr)
{
}

LinkedList::LinkedList(const LinkedList& other)
{
	Node* crr = other.head;
	while (crr != nullptr)
	{
		add(crr->value);
	}
}

void LinkedList::add(int value)
{
	head = new Node(value, head);
}

LinkedList::Iterator LinkedList::begin()
{
	return Iterator(head);
}

LinkedList::Iterator LinkedList::end()
{
	return Iterator(nullptr);
}

LinkedList::FilterIterator LinkedList::begin_filter(FilterFunc f)
{
	return FilterIterator(head, f);
}

LinkedList::FilterIterator LinkedList::end_filter(FilterFunc f)
{
	return FilterIterator(nullptr, f);
}

LinkedList& LinkedList::operator=(LinkedList other)
{
	std::swap(head, other.head);

	return *this;
}

LinkedList::~LinkedList()
{
	delete_helper(head);
}

void LinkedList::delete_helper(Node *crr)
{
	if (crr == nullptr)
	{
		return;
	}

	delete_helper(crr->next);
	delete crr;
}

LinkedList::Node::Node(int value, Node* next = nullptr)
	: value(value), next(next)
{}

void LinkedList::Iterator::operator++()
{
	crr = crr->next;
}

int& LinkedList::Iterator::operator*()
{
	return crr->value;
}

bool LinkedList::Iterator::operator!=(const Iterator& other) const
{
	return crr != other.crr;
}

LinkedList::Iterator::Iterator(Node* head)
	: crr(head)
{}

void LinkedList::FilterIterator::operator++()
{
	crr = crr->next;
	next();
}

int& LinkedList::FilterIterator::operator*()
{
	return crr->value;
}

bool LinkedList::FilterIterator::operator!=(const FilterIterator& other) const
{
	return crr != other.crr || filterFunction != other.filterFunction;
}

LinkedList::FilterIterator::FilterIterator(Node* head, FilterFunc f)
	: crr(head), filterFunction(f)
{
	next();
}

void LinkedList::FilterIterator::next()
{
	while (crr != nullptr && !filterFunction(crr->value))
	{
		crr = crr->next;
	}
}
