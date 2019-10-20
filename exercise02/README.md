# 14.10.2019

### What are we going to talk about today?
1. Linked list, doubly linked list;
2. Fast and slow pointers technique;
3. Efficient vs Effective;

### Task format
All the tasks will be in the following format:
1. the linked list will be represented by a single Node* pointer;
2. each task will be represented by a single function(of course helper functions can be implemented) which gets the head as an argument:
```
    struct Node
    {
    	int value;
    	Node *next;
    
    	Node(int value, Node *next = nullptr)
    		: value(value), next(next)
    	{}
    };

    <type> DoSomething(Node *head) 
    {
        //code
    }
```

### Task descriptions
1. If you are still not comfortable with linked list(exercise07 OOP course in GitHub):
   -    insert an element to a linked list head/tail
   -    delete an element from a linked list head/tail
   -    insert at a specific position
   -    delete from a specific position
2. Write a function that deletes a linked list from the memory
3. Write a function that reverses a linked list(with and without additional memory);
4. Write a function that finds the middle element of a linked list
5. Write a function that detects if there is a cycle inside a linked list;
6. Write a function that makes a given singly linked list(which does not have cycles) into a circular one;
7. Write a function that checks if a given singly linked list is a circular one;
8. Write a function that finds the nth node from the end of linked list;
9. Write a function to check if a singly linked list is a palindrome;