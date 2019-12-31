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

//-------------Include-------------
#include <iostream>
#include <cstdlib>

//--------------Using---------------
using std::cin;
using std::cout;
using std::endl;

//-------------Constant-------------
const int ROWS=4,
          COLS=5;

//-------------prototype-------------
void input_func(int mat[][COLS]);
int max_row(const int mat[][COLS]);
int sum_row(const int mat[][COLS], int row);
int max_col(const int mat[][COLS]);
int sum_col(const int mat[][COLS], int col);

//-------------Main-------------
int main()
{
    int mat[ROWS][COLS],
        row=0, col=0;

    input_func(mat);

    row = max_row(mat);

    col = max_col(mat);

    cout<< row <<" "<< col;

    return EXIT_SUCCESS;
}

//-------------Input Function--------------------
//receive numbers to matrix
void input_func(int mat[][COLS])
{
    for(int ind_row=0; ind_row<ROWS; ind_row++)

        for(int ind_col=0; ind_col<COLS; ind_col++)

            cin>>mat[ind_row][ind_col];
}

//-------------Maximum row-----------------------
//Check which row contain the highest sum
//the function receive the matrix

int max_row(const int mat[][COLS])
{
    int max_sum=0, temp_sum=0, max_sum_row=0;   //Variables

    for(int row=0; row<ROWS; row++)     //run over the rows
    {
        temp_sum = sum_row(mat, row);   //summon "sum_row" an save the value
                                        //in "temp_sum"
        if(max_sum < temp_sum)          //check if "temp_sum" is greater
        {                               //than "max_sum"
            max_sum = temp_sum;         //If so, put the value from "temp_sum"
            max_sum_row = row;          //in "max_sum", and save the row
        }                               //number in "max_sum_row".

    }                                   //return to main function which
        return (max_sum_row);           //row contain the highest sum.
}

//-------------Sum row-----------------------
//Calculates the sum for each row
//the function receive the matrix and one row

int sum_row(const int mat[][COLS], int row)
{
    int sum=0;                      //variable

    for(int col=0; col<COLS; col++) //run over the columns

        sum += mat[row][col];       //for each row calculate the sum

    return (sum);    //return to "max_row" function the sum of row.
}

//-------------Maximum column-----------------------
//Check which column contain the highest sum
//the function receive the matrix

int max_col(const int mat[][COLS])
{
    int max_sum=0, temp_sum=0, max_sum_col=0;   //variables

    for(int col=0; col<COLS; col++)     //run over the columns
    {
        temp_sum = sum_col(mat, col);   //summon "sum_col" an save the value
                                        //in "temp_sum"
        if(max_sum < temp_sum)          //check if "temp_sum" is greater
        {                               //than "max_sum"
            max_sum = temp_sum;         //If so, put the value from "temp_sum"
            max_sum_col = col;          //in "max_sum", and save the column
        }                               //number in "max_sum_col".
    }
                                        //return to main function which
    return (max_sum_col);               //column contain the highest sum.
}

//-------------Sum row-----------------------
//Calculates the sum for each row
//the function receive the matrix and one column

int sum_col(const int mat[][COLS], int col)
{
    int sum=0;                      //variable

    for(int row=0; row<ROWS; row++) //run over the rows

        sum += mat[row][col];       //for each column calculate the sum

    return (sum);   //return to "max_col" function the sum of column.
}






