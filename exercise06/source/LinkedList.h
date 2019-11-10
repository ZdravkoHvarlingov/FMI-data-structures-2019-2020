#pragma once


class LinkedList
{
private:
	struct Node
	{
		int value;
		Node* next;

		Node(int, Node*);
	};

public:
	class Iterator
	{
		friend class LinkedList;

	public:
		void operator++();
		int& operator*() const;

		bool operator!=(const Iterator& other) const;

	private:
		Iterator(Node* head);

		Node* crr;
	};

	LinkedList();
	LinkedList(const LinkedList& other);

	void push(int);
	Iterator begin();
	Iterator end();


	LinkedList& operator=(LinkedList other);
	~LinkedList();
	
private:
	void delete_helper(Node*);

	Node* head;
};
