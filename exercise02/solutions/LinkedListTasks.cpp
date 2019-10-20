#include <iostream>
#include <stack>

#define DUMMY_VALUE 100000

struct Node
{
	int value;
	Node* next;
};


void DeleteAllNodes(Node* head)
{
	if (head == nullptr)
	{
		return;
	}

	DeleteAllNodes(head->next);
	delete head;
}


void Reverse(Node* head)
{
	Node* previous = nullptr;
	Node* current = head;
	Node* next = nullptr;

	while (current != nullptr)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
}


Node* GetMiddle(Node* head)
{
	if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
	{
		return head;
	}
	Node* slow = head, * fast = head;
	while (fast->next != nullptr && fast->next->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}


bool HasCycle(Node* head)
{
	if (head == nullptr)
	{
		return false;
	}

	Node* slow = head, * fast = head;
	while (fast->next != nullptr && fast->next->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			return true;
		}
	}

	return false;
}


void MakeCircular(Node* head)
{
	if (head == nullptr)
	{
		return;
	}

	Node* iterator = head;
	while (iterator->next != nullptr)
	{
		iterator = iterator->next;
	}

	iterator->next = head;
}


bool IsCircular(Node* head)
{
	if (head == nullptr)
	{
		return false;
	}

	Node* slow = head, * fast = head;
	while (fast->next != nullptr && fast->next->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;

		// If linked list is circular, they will meet at the head
		if (slow == fast && slow == head)
		{
			return true;
		}
	}

	return false;
}


int FindNthNodeFromTheEndHelper(Node* head, int& n)
{
	if (head == nullptr)
	{
		return DUMMY_VALUE;
	}

	int result = FindNthNodeFromTheEndHelper(head->next, n);
	--n;
	if (n == 0)
	{
		return head->value;
	}

	return result;
}


int FindNthNodeFromTheEnd(Node* head, int n)
{
	return FindNthNodeFromTheEndHelper(head, n);
}


bool IsPalindrome(Node* head)
{
	std::stack<Node*> reversedNodes;
	Node* crr = head;
	while (crr != nullptr)
	{
		reversedNodes.push(crr);
		crr = crr->next;
	}

	crr = head;
	while (crr != nullptr)
	{
		Node* top = reversedNodes.top(); reversedNodes.pop();
		if (top->value != crr->value)
		{
			return false;
		}

		crr = crr->next;
	}

	return true;
}


int main()
{
    std::cout << "Linked list solutions are presented here.";
}
