/*
 * Left corner
 * =============================================================
 * Written by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program receives from the user 20 numbers.
 * Then the program checks if the values in the upper-left corner are greater
 * or equal to the other values in the matrix.
 * In the end, the program shows the row with the greater values in
 * left corner
 *
 * input:
 *  a. 20 numbers to a matrix, 5 rows and 4 columns.
 *
 * output:
 *  a. Print the row with the greater values in left corner.
 *
 */


//-------------Include---------------
#include <iostream>
#include <cstdlib>

//---------------Using---------------
using std::cout;
using std::cin;
using std::endl;

//-------------Constant---------------
const int ROWS=5,
          COLS=4;

//---------------Main---------------
int main()
{
    int corner[ROWS][COLS],                //a matrix of one dimensional arrays
        row, col, temp=0, max_value=0;     //variables

    bool exist=false;                      //boolean variable

//----------------------input loop----------------------------
    for(int row_ind=0; row_ind<ROWS; row_ind++)

        for(int col_ind=0; col_ind<COLS; col_ind++)

            cin>>corner[row_ind][col_ind];

//-------------------check left corner--------------------------
    for(row=0; row<ROWS; row++)         //run over the matrix
    {
        for(col=0; col<=row; col++)
        {
            //check if the value in matrix is greater than "max_value".
            //if so, the boolean variable change to true.
            if(corner[col][row-col] >= max_value)

                exist=true;

            else   //if the value is not greater, change the boolean
            {      //variable to false, and get out of the loop.
                exist=false;
                break;
            }
            //check if the value in matrix is greater than "temp".
            //if so, put the value in temp.
            if(corner[col][row-col] > temp)

                temp = corner[col][row-col];
        }

        max_value = temp;       //put the value of "temp" in "max_value".

        if(!exist)              //check if the boolean variable is false.
            break;              //if so, get out of the loop.
    }
    if(!exist)                  //check if the boolean variable is false.
        cout<<row;              //if so, print "row"


    return EXIT_SUCCESS;
}
