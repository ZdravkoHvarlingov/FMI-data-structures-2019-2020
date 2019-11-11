#pragma once

using FilterFunc = bool(*)(int);

class LinkedList
{
public:
	class Iterator;
	class FilterIterator;

	LinkedList();
	LinkedList(const LinkedList& other);
	
	void add(int);
	Iterator begin();
	Iterator end();

	FilterIterator begin_filter(FilterFunc);
	FilterIterator end_filter(FilterFunc);
	
	LinkedList& operator=(LinkedList other);
	~LinkedList();

private:
	struct Node
	{
		int value;
		Node* next;

		Node(int value, Node* next);
	};

	void delete_helper(Node*);

	Node* head;

public:
	class Iterator
	{
	public:
		friend class LinkedList;

		void operator++();
		int& operator*();

		bool operator!=(const Iterator& other) const;
	private:
		Iterator(Node* head);

		Node* crr;
	};


	class FilterIterator
	{
	public:
		friend class LinkedList;

		void operator++();
		int& operator*();

		bool operator!=(const FilterIterator& other) const;
	private:
		FilterIterator(Node* head, FilterFunc f);
		void next();

		Node* crr;
		FilterFunc filterFunction;
	};
};
