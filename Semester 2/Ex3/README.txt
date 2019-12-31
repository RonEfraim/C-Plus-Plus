File: ex3a.cc 
Display the minimum and leaves
=============================================================
Written by: Ron Efraim, id = 204661425, login = ronef

The program receives from user numbers until number 0. 
The program insert values into the tree.
The program search the lowest value in the tree and print it.

Compile: g++ -Wall ex3a.cc –o ex3a
Run: ex3a

input:
  a. Numbers until number 0.
 
output:
  a. The lowest value in the tree.

Runtime:
- for building the three - linear in number of inputs.
- for finding the minimal value - linear.
- for print all tree's leaves - linear in size of the tree.

---------------------------------------------------------------------------------------------------------------------------------------------

File:ex3b.cc
Displays the shallowest leaf in the tree
=============================================================
Written by: Ron Efraim, id = 204661425, login = ronef

The program receives from user numbers until eof.
The program insert values into the tree.
The program search the shallowest leaf in the tree and print it.

Compile: g++ -Wall ex3b.cc –o ex3b
Run: ex3b

input:
  a. Numbers until eof.
 
output:
  a. The shallowest leaf in the tree.

Runtime:
- for building the three - linear in number of inputs.
- for finding the shallowest leaf - linear in size of the tree.

---------------------------------------------------------------------------------------------------------------------------------------------

File: ex3c.cc 
Tree to List
=============================================================
Written by: Ron Efraim, id = 204661425, login = ronef

The program receives from user numbers until eof.
The program copy all the leaves to linked list.
The program start to copy from the leaf that contain the lowest value.
Finally, the program summon a function that print the list.

Compile: g++ -Wall ex3c.cc –o ex3c
Run: ex3c

Input:
  a. Numbers until eof.

output:
  a. The linked list.

Runtime:
- for building the three - linear in number of inputs.
- for copy the bst values into a linked list - linear in size of tree.
- for print all tree's leaves - linear in size of tree.