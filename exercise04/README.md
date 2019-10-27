# 28.10.2019

### What are we going to talk about today?
1. Non linear data structures;
2. Binary tree, implementation, how it works(not oriented tree);
3. Traversals: in order traversal, post order traversal, pre order traversal(DFS for a tree);


### Task descriptions
1. Create struct representing a binary tree with numbers as node values;
2. Create all the tree traversals - in, pre, post order traverals;
3. Find the sum of all elements inside the tree;
4. Find the number of leaves which the tree has;
5. You have a function which receives a tree with two types of nodes(the leaves should always be numbers!):
   -    number
   -    operation sign - +, -, *, /
   -    the tree represents an expression. If the current node is just a number - return that number. If the current node is an opration sign - calculate the values from the left and right subtrees and then apply the operation on these values.

### Bonus task:
1. Give an expression string -> construct a tree from it:
   -    ( ( 10 + 20 ) * ( 3 * 5 ) )