File: ex1a.cc 
Average values in a 2D array is dynamically assigned
=============================================================
Written by: Ron Efraim, id = 204661425, login = ronef

A program that reads from the user how many rows of data he wants to enter, 
and assigns a set of pointers.
The program reads data to the matrix, line by line. 
For each line the user enter, first, how many values he wants to enter, 
and secondly the values themselves.
Finally, the program calculates and returns the average values in the matrix.

Compile: g++ -Wall ex1a.cc –o ex1a
Run: ex1a

Input:
 a. Values to 2D array.
 
Output:
 a. The average

---------------------------------------------------------------------------------------------------------------------------------------------

File:ex1b.cc
Sum of cells
=============================================================
Written by: Ron Efraim, id = 204661425, login = ronef

The program receives two names of 2 files to the arguments vector.
The program will read the data in each input file into a dynamically matrix.
The program will print the sum of the values in the two arrays. 
If, in array A, any row is longer than the corresponding row in array B, 
then only the value from array A should be displayed, 
and similarly to the number of rows in one array larger than the number of rows in the second array.

Compile: g++ -Wall ex1b.cc –o ex1b
Run: ex1b

Output:
  a. The sum of two values in different files.

---------------------------------------------------------------------------------------------------------------------------------------------

File: ex1c.cc 
Data Structure
=============================================================
Written by: Ron Efraim, id = 204661425, login = ronef

The program receives from the user a command
The program allows the user to perform the following actions
on the data structure

 * al - add a new line to the data structure.
 * dl - delete the selected line from the data structure.
 * jl - join two selected lines from the data structure.
 * sl - split two selected lines from the data structure.
 * av - add a value to a selected line from the data structure.
 * dv - delete a value from exist line in data structure.
 * pr - present the data structure.
 * pg - clean the unused rows and cells from the data structure.
 * e -  end the program.

Compile: g++ -Wall ex1c.cc –o ex1c
Run: ex1c

Input:
  a. A command according to the instructions above.
