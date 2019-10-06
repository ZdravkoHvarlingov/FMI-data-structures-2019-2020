# 06.10.2019

### What are we going to talk about today?
1. What is an abstract data type
    -   Can be considered to be a type;
    -   It has predefined interface;
    -   Constraints about the input and output;
    -   Constraints about time and space complexity;
    -   Abstract data type vs data structure - ADT is about (what does it do) and DS is about(how does it do it);
2. Vector
3. Queue and stack
   -    Constraints to the data structure;
   -    Implementation using vector(easy but not so efficient implementation);
4. Efficient vs Effective

### Tasks
1. Implement a stack using vector as an internal data structure
2. Implement a queue using vector as an internal data structure
3. Write a program to reverse a vector using stack
4. Write a program to reverse a string using stack
5. Check if a given string is well formatted considering the brackets:
   -    (okay string) -> YES
   -    (1 * (5 + 2) * 3) -> YES
   -    (10 + 1) * 2) -> NO
   -    (()) -> YES
   -    ))(()) -> NO
   -    Tip: use a stack for the check
   - More advanced: consider more than one type of brackets(), {}, [], etc...
6. Reverse a stack using recursion
7. Reverse a queue using recursion
  