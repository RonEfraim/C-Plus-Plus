/*
 * Sum of cells
 * =============================================================
 * Written by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program receives two names of 2 files to the arguments vector.
 * Then the program copy all the values in each file to dynamic matrix.
 * Finally, the program calculate the sum of two values in different files,
 * for example: sum = matrix_file_1[0][1] + matrix_file_2[0][1].
 * The program will not calculate the sum for a different cell number.
 *
 * output:
 *  a. The sum of two values in different files.
 */

//------------------------------Include---------------------------------------
#include <iostream>
#include <new>
#include <cstdlib>
#include <fstream>

//-------------------------------Using---------------------------------------
using std::cout;
using std::cin;
using std::nothrow;
using std::ifstream;
using std::endl;
using std::cerr;

//-----------------------------Prototype--------------------------------------
void read_file(ifstream &inp_file, int **&first_dyn_arr);
void alloc_row(int **&dyn_arr, int row_size);
void alloc_cel(int *&dyn_arr, int cel_size);
void dyn_to_temp_arr(int **&dyn_arr, int *&temp_arr, int &cel_size,
                     int &curr_row, int &curr_col, int value);
void dyn_to_temp(int **&dyn_arr, int **&temp, int &cel_size,
                 int &curr_row, int &curr_cel);
void sum(int **first_dyn_arr, int **second_dyn_arr);
void delete_array(int **dyn_arr);

//-------------------------------Main-----------------------------------------
int main(int argc, char **argv)
{
    int **first_dyn_arr,
        **second_dyn_arr;

    if(argc < 2)
    {
        cerr << "can not open input file";

        exit(EXIT_FAILURE);
    }

    ifstream inp_f1;

    inp_f1.open(argv[1]);

    ifstream inp_f2;

    inp_f2.open(argv[2]);

    if(!inp_f1.is_open() || !inp_f2.is_open())
    {
        cerr << "can not open input file";

        exit(EXIT_FAILURE);
    }

    read_file(inp_f1, first_dyn_arr);

    read_file(inp_f2, second_dyn_arr);

    sum(first_dyn_arr, second_dyn_arr);

    delete_array(first_dyn_arr);

    delete_array(second_dyn_arr);

    inp_f1.close();

    inp_f2.close();

    return (EXIT_SUCCESS);
}

//read_file-------------------------------------------------------------------
//Function that get the input file, and dynamic array.
//The function read values from file until the end of file.
void read_file(ifstream &inp_file,
               int **&dyn_arr)
{
    int **temp,
        *arr_temp;

    int value,
        curr_row = 0, curr_cel=0;

    int row_size = 1,
        cel_size = 1;

    alloc_row(dyn_arr, row_size);

    inp_file >> value;

    while(!inp_file.eof())
    {
        alloc_cel(dyn_arr[curr_row], cel_size);

        if(value != 0)
        {
            alloc_cel(arr_temp, cel_size);

            dyn_to_temp_arr(dyn_arr, arr_temp, cel_size,
                            curr_row, curr_cel, value);

           inp_file >> value;
        }

        dyn_arr[curr_row][curr_cel] = 0;

        row_size *= 2;

        alloc_row(temp, row_size);

        dyn_to_temp(dyn_arr, temp, cel_size, curr_row, curr_cel);

        inp_file >> value;

    }

    dyn_arr[curr_row] = NULL;
}

//alloc_row-------------------------------------------------------------------
//Function that allocate rows for dynamic matrix
void alloc_row(int **&dyn_arr,
               int row_size)
{
    dyn_arr = new(nothrow) int*[row_size * 2];

    if(dyn_arr == NULL)
    {
        cout << "can not allocate memory \n";
        exit(EXIT_FAILURE);
    }

    dyn_arr[row_size] = NULL;
}

//alloc_cel-------------------------------------------------------------------
//Function that allocate cells for dynamic matrix
void alloc_cel(int *&dyn_arr,
               int cel_size)
{
    dyn_arr =  new(nothrow) int[cel_size * 2];

    if(dyn_arr == NULL)
    {
        cout << "can not allocate memory \n";
        exit(EXIT_FAILURE);
    }
}

//dyn_to_temp_arr-------------------------------------------------------------
//Function that copy row from dynamic matrix to temporary array, than free
//the allocated memory, and than send the dynamic matrix to pointer like
//the temporary array.
void dyn_to_temp_arr(int **&dyn_arr, int *&temp_arr,
                     int &cel_size, int &curr_row,
                     int &curr_cel, int value)
{
    for(int ind = 0; ind < cel_size; ind++)

        temp_arr[ind] = dyn_arr[curr_row][curr_cel];

    cel_size *= 2;

    curr_cel++;

    delete [] dyn_arr[curr_row];

    dyn_arr[curr_row] = temp_arr;

    dyn_arr[curr_row][curr_cel] = value;
}

//dyn_to_temp-----------------------------------------------------------------
//Function that copy the dynamic matrix to temporary matrix, than free
//the allocated memory, and than send the dynamic matrix to pointer like
//the temporary matrix.
void dyn_to_temp(int **&dyn_arr, int **&temp,
                 int &cel_size,
                 int &curr_row, int &curr_cel)
{
    for(int ind = 0; dyn_arr[ind] != NULL; ind++)

        temp[ind] = dyn_arr[ind];

    curr_cel = 0;

    curr_row++;

    cel_size = 1;

    delete[] dyn_arr;

    dyn_arr = temp;

}

//sum-------------------------------------------------------------------------
//Function that calculate the sum of two values in different files
//and print it
void sum(int **first_dyn_arr,
        int **second_dyn_arr)
{
	for(int row_ind = 0; first_dyn_arr[row_ind] != NULL; row_ind++)
	{
		for(int cel_ind = 0; first_dyn_arr[row_ind][cel_ind] != 0; cel_ind++)

            cout << first_dyn_arr[row_ind][cel_ind] +
                    second_dyn_arr[row_ind][cel_ind] << " ";
		cout << endl;
	}
}

//delete_array----------------------------------------------------------------
//Function that free allocated memory
void delete_array(int **dyn_arr)
{
	for (int ind = 0; dyn_arr[ind] != NULL; ind++)

		delete[] dyn_arr[ind];

	delete[] dyn_arr;
}
