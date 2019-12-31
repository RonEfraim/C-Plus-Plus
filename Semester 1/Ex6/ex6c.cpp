/*
 * Sudoku test
 * =============================================================
 * Written by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program receives from the user 81 numbers into sudoku table.
 * Then the program checks if in every row, column and sub square
 * the numbers are between 1-9, and if every number appears only once.
 *
 *
 * input:
 *  a. 81 numbers to a matrix, 9 rows and 9 columns.
 *
 * output:
 *  a. Print 1 if sudoku table is valid.
 *  b. Print 0 if sudoku table is not valid.
 */

//----------------Include----------------------
#include <iostream>
#include <cstdlib>

//----------------Using----------------------
using std::cout;
using std::cin;
using std::endl;

//----------------Constant----------------------
const int N=3;

//---------------Prototype----------------------
void input_func(int mat[][N*N]);
void check(const int mat[][N*N]);
bool row_ok(const int mat[N*N]);
bool col_ok(const int mat[][N*N], int col);
bool square_ok(const int mat[][N*N], int row, int col);

//----------------Main----------------------
int main()
{
    int mat[N*N][N*N];  //Array of 2D

    input_func(mat);    //summon functions to Main function

    check(mat);

    return EXIT_SUCCESS;
}

//-------------Input Function--------------------
//receive numbers into matrix
//check if the inputs are between 1-9

void input_func(int mat[][N*N])
{
    for(int ind_row=0; ind_row<N*N; ind_row++)

        for(int ind_col=0; ind_col<N*N; ind_col++)
        {
            cin>>mat[ind_row][ind_col];

            if(mat[ind_row][ind_col] > N*N || mat[ind_row][ind_col] < 0)

                ind_col--;
        }
}

//-------------Check Function--------------------
//check if every row, column and sub square are ok
//the function receive the matrix

void check(const int mat[][N*N])
{
    bool check_row=false,       //boolean variables
         check_col=false,
         check_square=false;

    for(int row=0; row<N*N; row++)  //run over the rows
    {
        if(row_ok(mat[row]))        //summon "row_ok" boolean function
                                    //if the function returns "true", puts
            check_row = true;       //"true" in "check_row"
        else                        //if the function returns "false", puts
        {                           //"false" in "check_row" and break
            check_row = false;      //the loop
            break;
        }
    }

    for(int col=0; col<N*N; col++)  //run over the columns
    {
        if(col_ok(mat, col))        //summon "col_ok" boolean function
                                    //if the function returns "true", puts
            check_col = true;       //"true" in "check_col"
        else                        //if the function returns "false", puts
        {                           //"false" in "check_col" and break
            check_col = false;      //the loop
            break;
        }
    }

    for(int row=0; row<N*N; row++)      //run over the rows
    {
        for(int col=0; col<N*N; col++)  //run over the columns
        {
            if(square_ok(mat, row, col))//summon "square_ok" boolean function
                                        //if the function returns "true", puts
                check_square = true;    //"true" in "check_square"
            else                        //if the function returns "false",puts
            {                           //"false" in "check_square" and break
                check_square = false;   //the loop
                break;
            }
        }
    }

    //check if "check_row", "check_col" and "check_square" are true
    if(check_row && check_col && check_square)

        cout<< "1";     //if they are true, print "1"
                        //it means, sudoku table is valid
    else
                        //if they are false, print "0"
        cout<< "0";     //it means, sudoku table is not valid
}

//-------------Check row--------------------
//check if every row is ok
//the function receive only one row each time

bool row_ok(const int mat[N*N])
{
    bool exist=false;   //boolean variable

    for(int col=0; col<N*N; col++)  //rum over columns
    {
        if(mat[col] == 0)   //check if value is equal to 0
            continue;       //if so, continue the loop.

        //run over the columns, and check if there is equal values
        for(int temp=col+1; temp<N*N; temp++)
        {
            if(mat[col] == mat[temp])
            {                   //if there is equal values
                exist=true;     //change the boolean variable "exist" to true
                break;          //and break the loop.
            }
        }
        if(exist)           //check if "exist" is true
            return false;   //if so, return false to "check" function
    }
    if(!exist)              //check if "exist" is false
        return true;        //if so, return true to "check" function
}

//-------------Check column--------------------
//check if every column is ok
//the function receive matrix, and one column each time

bool col_ok(const int mat[][N*N], int col)
{
    bool exist=false;       //boolean variable

    for(int row=0; row<N*N; row++)  //run over the rows
    {
        if(mat[row][col] == 0)      //check if value is equal to 0
            continue;               //if so, continue the loop.

        //run over the rows, and check if there is equal values
        for(int temp=row+1; temp<N*N; temp++)
        {
            if(mat[row][col] == mat[temp][col])
            {                   //if there is equal values
                exist=true;     //change the boolean variable "exist" to true
                break;          //and break the loop.
            }
        }
        if(exist)           //check if "exist" is true
            return false;   //if so, return false to "check" function
    }
    if(!exist)              //check if "exist" is false
        return true;        //if so, return true to "check" function
}

//-------------Check sub square--------------------
//check if every sub square is ok
//the function receive matrix, row and column.

bool square_ok(const int mat[][N*N], int row, int col)
{
    bool exist=false;           //boolean variable

    //put in "temp_row" the calculation of row number divide by N
    //put in "temp_col" the calculation of column number divide by N
    int temp_row = row / N,   //(N = size of sub square)
        temp_col = col / N;

    //run over the rows in sub square
    for(int ind_r=temp_row * N; ind_r<(temp_row * N + N); ind_r++)
    {
        //run over the columns in sub square
        for(int ind_c=temp_col*N; ind_c<(temp_col*N + N); ind_c++)
        {
            //check if "row" is not equal to "ind_r"
            //and "col" is not equal to "ind_c"
            if(row != ind_r && col != ind_c)
            {   //check if the values in sub square are equal
                if(mat[row][col] == mat[ind_r][ind_c])
                {               //if there is equal values
                    exist=true; //change the boolean variable "exist" to true
                    break;      //and break the loop.
                }
            }
        }
        if(exist)           //check if "exist" is true
            return false;   //if so, return false to "check" function
    }
    if(!exist)              //check if "exist" is false
        return true;        //if so, return true to "check" function

}

