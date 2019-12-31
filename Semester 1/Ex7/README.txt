File: ex7a.cc 
Strings
=============================================
Written by: Ron Efraim, id = 204661425, login = ronef

The program receives 2 strings
Part A-
Displays a copy of the first string after all non-letter characters have been removed, 
and all lowercases has been converted to uppercases. 
For example: If the first string was: aAc1bBf! Then the output will be: AACBBF.
Part B-
Displays a copy of the first string after removing from it all the characters that 
appear in the second string. 
For example: If the first string was: aAc1bbBf! And the second string was: b! 
Then the output will be: aAc1Bf.

Compile: g++ -Wall ex7a.cc –o ex7a
Run: ex7a

Input: 	
Characters and signs.

Output: 
a. String that show only upper cases.
b. String of characters and signs.

Runtime:
2*(MAX_STR_LEN)    ->  (N)

-------------------------------------------------------------------------------------------------------------------------------------------

File:ex7b.cc
Locating text in dictionary
=============================================
Written by: Ron Efraim, id = 204661425, login = ronef

The program receives 2 strings
The program finds the largest sub string of "text" (string) that has all the words in the dictionary. 
The program will returns the number of the cell that start the sub string with a return value.
A reference parameter will return the length of the sub string.

Compile: g++ -Wall ex7b.cc –o ex7b
Run: ex7b

Input:
Characters to 2 strings.

Output:
a. where the sub string is start
b. the longest sub string

Runtime:
(MAX_STRS*MAX_STR_LEN*MAX_TEXT_LEN)   ->   (N*N*N)


---------------------------------------------------------------------------------------------------------------------------------------------

File:ex7c.cc
String overlap
=============================================================
Writen by: Ron Efraim, id = 204661425, login = ronef

The program receives 2 strings
The program checks if there is overlapping strings.
If there is, the program prints the length of the longest overlapping string.

Compile: g++ -Wall ex7c.cc –o ex7c
Run: ex7c

Input:
String overlap

Output:
The maximum length of overlap string

Runtime:
(N*N)


