File: ex0a.cc 
Input and Output
=============================================================
Written by: Ron Efraim, id = 204661425, login = ronef

The program receives from user numbers of row, column and then the value. 
Until eof (end of file)
The function read a single line,  from the file opened to read, and send the result of that line 
to the output file.
For each string in the input line, the following output will be sent:
    - if there is a letter print 'a'
    - if there is a number print '0'
    - if the string are mixed (letters, numbers and other) symbols print 'x'.
    - if there are similar strings print only one.

Compile: g++ -Wall ex0a.cc –o ex0a
Run: ex0a

Input:
 a. File with characters.
 
Output:
 a. According to the above instructions.

---------------------------------------------------------------------------------------------------------------------------------------------

File:ex0b.cc
Delete Documentation
=============================================================
Written by: Ron Efraim, id = 204661425, login = ronef

The program receives a program code or group of words.
Delete of documentation notes will be done according to the following rules:
    - If there are a pair of slashes that are inclined to the right (//) 
      this is a documentation note that extends to the end of the line.       
      Read all the characters to the end of the line, and ignore them all.

    -  If there is a documentation type * / 
       the program delete all characters until they are closed (by * /), 
       if another note is opened in the current note, then all characters deleted before closing the two notes. 
       If there is a document  type "//" should be treated as described in section A above.


Compile: g++ -Wall ex0b.cc –o ex0b
Run: ex0b

Input:
  a. program code or group of words.

Output:
  a. print without documentation.