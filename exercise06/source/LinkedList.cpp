#include "LinkedList.h"
#include <algorithm>


LinkedList::LinkedList()
	: head(nullptr)
{
}

LinkedList::LinkedList(const LinkedList& other)
	: LinkedList()
{
	Node *crr = other.head;
	while (crr != nullptr)
	{
		push(crr->value);
		crr = crr->next;
	}
}

void LinkedList::push(int value)
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

LinkedList::Node::Node(int value, Node *next)
	: value(value), next(next)
{
}

void LinkedList::Iterator::operator++()
{
	crr = crr->next;
}

int& LinkedList::Iterator::operator*() const
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
