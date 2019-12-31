/*
 * Average values in a 2D array is dynamically assigned
 * =============================================================
 * Written by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program receives from user how many rows he wants to enter.
 * Then the user enter how many cells he wants in each line, and then
 * insert values.
 * Finally, the program summon a function that calculates the average.
 *
 * input:
 *  a. Values to 2D array.
 *
 * output:
 *  a. The average.
 */


//------------------------------Include---------------------------------------
#include <iostream>
#include <new>
#include <stdlib.h>

//-------------------------------Using---------------------------------------
using std::cin;
using std::cout;
using std::nothrow;

//-----------------------------Prototype--------------------------------------
void read_rows(int **&arr_average);
void input_values(int **&arr_average, int rows);
void check_alloc_rows(int **&arr_average, int rows);
void check_alloc_c(int **&arr_average, int ind, int cells);
void delete_array(int **arr_average, int rows);

//-------------------------------Main-----------------------------------------
int main()
{
    int **arr_average;

    read_rows(arr_average);

    return(EXIT_SUCCESS);
}

//read_rows-------------------------------------------------------------------
//Function that allocate rows, and then summon two functions
void read_rows(int **&arr_average)
{
    int rows = 0;

    cin >> rows;

    check_alloc_rows(arr_average, rows);

    input_values(arr_average, rows);

    delete_array(arr_average, rows);
}

//input_values----------------------------------------------------------------
//Function that allocate cells for each row.
//The function read value for each cell, then sum all the values in array
//and print the average
void input_values(int **&arr_average,
                  int rows)
{
    int cells = 0, temp = 0,
        sum = 0, value = 0;

    for(int row_ind = 0; row_ind != rows; row_ind++)
    {
        cin >> cells;

        if(cells == 0)

            continue;

        check_alloc_c(arr_average, row_ind, cells);

        for(int val_ind = 0; val_ind != cells; val_ind++)
        {
            cin >> value;

            arr_average[row_ind][val_ind] = value;

            sum += value;
        }

        temp += cells;
    }

    cout << (double) sum / temp;
}

//check_alloc_rows------------------------------------------------------------
//Function that checks if allocate rows was successful
void check_alloc_rows(int **&arr_average,
                      int rows)
{
    arr_average = new(nothrow)int *[rows];

    if(arr_average == NULL)
    {
        cout << "can not allocate memory \n";
        exit(EXIT_FAILURE);
    }
}

//check_alloc_c---------------------------------------------------------------
//Function that checks if allocate cells was successful
void check_alloc_c(int **&arr_average,
                   int ind,
                   int cells)
{
    arr_average[ind] = new(nothrow)int [cells];

    if(arr_average[ind] == NULL)
    {
        cout << "can not allocate memory \n";
        exit(EXIT_FAILURE);
    }
}

//delete_array----------------------------------------------------------------
//Function that free allocated memory
void delete_array(int **arr_average, int rows)
{
    for(int ind = 0; ind < rows; ind++)

        delete [] arr_average[ind];

    delete [] arr_average;
}
