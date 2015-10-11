Assignment 7
Due: Tuesday, October 13, 2015

GENERAL
In this assignment, you are to impleent a set calss, where an object represents a set of
non-negative integers. The integers are drawn from the universe {1,...,M}.

THE SET CALSS
The class should have a public static constant M which should be set to 30.
Public fields: The set class should have one private field:
bool in_set[M].
Invariant: Array cell in_set[i-1] is true if element i is in the set; else it is false.
The set class should have the following public methods:
  1. a constructor, which constructs the empty set.
  2. void add(integer x): when add is called the integer x is added to the set.
  3. void onion(set b): when onion is called, set b is added to the set. //onion because union is reserved in C++
  4. void intersection(set b): when intersection b is called, the set is intersected with b.
  5. int cardinality() const: when cardinality is called the function returns the number of elements in the set.
  6. void print_set() const: prints the set in the form {.,.,.,.,.}.

DESIGN
Specify and design the class. Write a design document.

IMPLEMENTATION, TESTING AND RUNNING
Write a short program, called demo_set.cxx that does the following:
  1.The user is asked to input two sets. For each set the program asks "Type in the integers in your set. Type a       negative numeber when you are done:"
  2.For these two sets a and b the program then outputs (a *union* b) *intersection* {1,3,5,7,9,15,22,25,30} 
    as well as the cardinality of that set. 
    
set.h - the header file for the set class
set.cxx - the implementation for the set class
demo_set.cxx
