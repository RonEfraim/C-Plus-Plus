File: ex6a.cc 
locate a row and a column with the maximum value
=============================================
Written by: Ron Efraim, id = 204661425, login = ronef

The program receives from the user 20 numbers, 4 rows, 5 columns
Then the program calculates the sum for every row.
Then the program calculates the sum for every column.
In the end, the program shows the row and the column with the maximum value in the matrix.

Compile: g++ -Wall ex6a.cc –o ex6a
Run: ex6a

Input: 	
20 numbers to a matrix, 4 rows and 5 columns.

Output: 
a. 20 numbers to a matrix, 4 rows and 5 columns.
b. Print the column with the maximum value.

Runtime:
2*(ROWS*COLS)    ->  (N*N)

-------------------------------------------------------------------------------------------------------------------------------------------

File:ex6b.cc
Containing row
=============================================
Written by: Ron Efraim, id = 204661425, login = ronef

The program receives from the user 20 numbers, 4 rows, 5 columns
Then the program checks if there is a row that contain all the values.
For two one-dimensional arrays, one array is contain the second array if each value in the first 
array also appears in the second array (ignoring the amount of each value in each array).
In the end, the program checks if there is a row that contain the same quantity of values.
One dimensional array contains the second one-dimensional array only if each value 
(except for a zero) appears in the second array the same number of times, 
or less times, than it does in the first array.

Compile: g++ -Wall ex6b.cc –o ex6b
Run: ex6b

Input:
20 numbers to a matrix, 4 rows and 5 columns.

Output:
  a. Print the row containing all values in the matrix.
  b. Print the row contain the same quantity of values.
  c. if there is no containing row the output is "-1".

Runtime:
Part A- (ROWS*ROWS*COLS*COLS)   ->   (N*N*N*N)
Part B- (ROWS*ROWS*COLS*COLS)   ->   (N*N*N*N)

---------------------------------------------------------------------------------------------------------------------------------------------

File:ex6c.cc
Sudoku test
=============================================================
Writen by: Ron Efraim, id = 204661425, login = ronef

The program receives from the user 81 numbers, 9 rows, 9 columns
Then the program checks if in every row, column and sub square
the numbers are between 1-9, and if every number appears only once.

A matrix will be called a "Valid Sudoku Table" if:
- every row contains values between 1-9 and every value appears only one time.
- every column contains values between 1-9 and every value appears only one time.
- every sub square contains values between 1-9 and every value appears only one time.

Compile: g++ -Wall ex6c.cc –o ex6c
Run: ex6c

Input:
20 numbers to a matrix, 5 rows and 4 columns.

Output:
Print the row with the greater values in left corner.

Runtime:
(ROWS*COLS)^3     ->  (N*N)^3


