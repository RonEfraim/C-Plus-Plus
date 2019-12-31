/*
 * locate a row and a column with the maximum value
 * =============================================================
 * Written by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program receives from the user 20 numbers.
 * Then the program calculates the sum for every row.
 * Then the program calculates the sum for every column.
 * In the end, the program shows the row and the column with the maximum
 * value in the matrix.
 *
 * input:
 *  a. 20 numbers to a matrix, 4 rows and 5 columns.
 *
 * output:
 *  a. Print the row with the maximum value.
 *  b. Print the column with the maximum value.
 */

//----------------Include-----------------
#include <iostream>

//----------------Using-----------------
using std::cout;
using std::cin;

//----------------Constant-----------------
const int ROWS=4,
          COLS=5;

//----------------Main-----------------
int main()
{
    int row, col, mat[ROWS][COLS],
        sum=0, max_sum=0, max_row=0, max_col=0;

//--------------Input loop-----------------
    for(row=0; row<ROWS; row++)

        for(col=0; col<COLS; col++)

        cin>>mat[row][col];

//--------------Max row loop-----------------
    for(row=0; row<ROWS; row++)         //run over the matrix
    {
        sum=0;
        for(col=0; col<COLS; col++)

            sum += mat[row][col];       //sum the value of each row

        if(sum > max_sum)      //check if the value of "sum" is greater
        {                      //than "max_sum". if so, put the value of
            max_sum = sum;     //"sum" in "max_sum", and the value of
            max_row = row;     //"row" in "max_row"
        }
    }

    max_sum=0;                 //reset "max_sum"

//--------------Max column loop----------------
    for(col=0; col<COLS; col++)         //run over the matrix
    {
        sum=0;
        for(row=0; row<ROWS; row++)

            sum += mat[row][col];       //sum the value of each column

        if(sum > max_sum)       //check if the value of "sum" is greater
        {                       //than "max_sum". if so, put the value of
            max_sum = sum;      //"sum" in "max_sum", and the value of
            max_col = col;      //"col" in "max_col"
        }
    }

//--------------------Output--------------------

    cout<<max_row<<" "<<max_col;

    return 0;
}
