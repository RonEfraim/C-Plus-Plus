File: ex4a.cc 
Compare between rectangle to point
=============================================================
Written by: Ron Efraim, id = 204661425, login = ronef

The program receives from user:
 - Type of print: "-" without brackets.
                Any other character, with brackets.
 - How many coordinates the user wants to input:
   coordinates to:
                Point:
                      (X and Y),

                Rectangle:
                      The top left corner of rectangle (X and Y)
                      The bottom right (X and Y)
 - Type of comparison:
                Point: "x"- sort by X
                          "y"- sort by Y
                          "r"- sort by radius
                          "a"- sort by alpha
                Rectangle:
                          "a"- sort by area
                          "c"- sort by circumference
                          "d"- sort by diagonal_length

Then the program print the sorting arrays according to the user's choice.

Compile: g++ -Wall ex4a.cc –o ex4a
Run: ex4a


input:
  a. Type of print: "-" without brackets 
                           any other character, with brackets -> for example: [(1, 5), (17, 2)]
  b. Coordinates.
  c. Type of comparison

output:
  a. Sorting arrays according to the user's choice.

---------------------------------------------------------------------------------------------------------------------------------------------

File:ex4b.cc
Compare between rectangle area to circle area
=============================================================
Written by: Ron Efraim, id = 204661425, login = ronef

The program receives from user coordinates to
Circle:
        The center point of the circle (X and Y)
        and the radius.
        The input series will end with a center point 0 0.
Rectangle:
           The top left corner of rectangle (X and Y)
           The bottom right (X and Y)
           The input series will end with the coordinates 0 0 0 0.

Then the program insert the coordinates of circle to a tree and the same action for rectangle's coordinates.
Then the program search the the largest circle area in the tree, and the same for rectangle.

Compile: g++ -Wall ex4b.cc –o ex4b
Run: ex4b

input:
 a. Coordinates.

output:
  a. The largest circle area in the tree.
  b. the largest rectangle area in the tree.
