/*
 * Sudoku Puzzle
 * =============================================================
 * Written by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program builds a sudoku puzzle.
 * The program receives from user numbers of row, column and then
 * the value. If the user does not enter a number then the cell remains
 * with zero.
 * The program checks if exists cell with zero, if so, the program puts a
 * number between 1-4 and checks for each number if there is no similar
 * number in the row, column, and cube.
 * In the end, the program prints the complete sudoku board.
 *
 * input:
 *  a. row, to end the input, put -1 in row.
 *  b. column
 *  c. value
 *
 * output:
 *  a. print the complete sudoku board.
 */

//---------------Include-----------------
#include <iostream>
#include <cstdlib>

//---------------Using-------------------
using std::cin;
using std::cout;
using std::endl;

//---------------Constants---------------
const int N = 2,
          EMPTY = 0;

//---------------prototype---------------
void input(int sudoku[][N*N]);
bool fill_board(int sudoku[][N*N], int row, int col);
bool row_check(int sudoku[][N*N], int row, int col, int value);
bool col_check(int sudoku[][N*N], int row, int col, int value);
bool square_check(int sudoku[][N*N], int row, int col, int value);
bool check(int arr[][N*N], int row, int col, int value);
void print(const int sudoku[][N*N]);

//---------------Main--------------------
int main()
{
	int sudoku[N*N][N*N] = {{0}};
	int col =0;

	input(sudoku);

	for(int row = 0; row < N*N; row++)

        fill_board(sudoku, row, col);

    print(sudoku);

	return EXIT_SUCCESS;

}

//Input----------------------------------
//function that receive numbers from user until he puts -1
void input(int sudoku[N*N][N*N])
{
	int row, col, value;

	while(row != -1)
    {
        cin >> row;

        if(row != -1)
        {
            cin >> col >> value;

            sudoku[row][col] = value;
        }
	}
}

//Fill_board-----------------------------
//Function that puts values in empty cells.
//The function receive the sudoku board, number of row and column.
//The function summon another function to checks if the value is allowed.
//The function run recursively until it reaches the last cell.
bool fill_board(int sudoku[][N*N],
				int row, int col)
{
	if(row == N*N && col == N*N)

        if(sudoku[row][col] != 0)

            return true;

	if(sudoku[row][col] == EMPTY)
	{
		for(int value = 1; value <= N*N; value++)
		{
            if(check(sudoku, row, col, value))
            {
                sudoku[row][col] = value;

                if (fill_board(sudoku, row, col))

                    return true;

            }
		}
        sudoku[row][col] = 0;

        return false;
	}

	else
    {
        if(col == N*N - 1)

            fill_board(sudoku, row + 1, 0);

        else

            fill_board(sudoku, row, col + 1);
    }

    return true;
}

//Row_check-----------------------------
//Function that check if the value is allowed on a particular line.
//The function receive the sudoku board, number of row ,column and value.
bool row_check(int sudoku[][N*N],
			   int row, int col,
			   int value)
{
	for(int ind_c = 0; ind_c < N*N; ind_c++)
	{
		if(ind_c != col)
		{
			if(sudoku[row][ind_c] == value)

				return false;
		}
	}

	return true;
}

//Col_check-----------------------------
//Function that check if the value is allowed on a particular column.
//The function receive the sudoku board, number of row ,column and value.
bool col_check(int sudoku[][N*N],
			   int row, int col,
			   int value)
{
	for(int ind_r = 0; ind_r < N*N; ind_r++)
	{
		if(ind_r != row)
		{
			if(sudoku[ind_r][col] == value)

				return false;
		}
	}

	return true;
}

//Square_check---------------------------
//Function that check if the value is allowed on a particular cube.
//The function receive the sudoku board, number of row ,column and value.
bool square_check(int sudoku[][N*N],
			   	  int row, int col,
				  int value)
{
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
                if(sudoku[ind_r][ind_c] == value)
                {               //if there is equal values
                	return false;
                }
            }
        }
    }
    return true;
}

//Check----------------------------------
//Function that summon the other functions that checks if value is allowed.
//The function receive the sudoku board, number of row ,column and value.
bool check(int sudoku[][N*N],
           int row, int col,
           int value)
{
	if (row_check(sudoku, row, col, value)
        && col_check(sudoku, row, col, value)
        && square_check(sudoku, row, col, value))

            return true;

    return false;
}

//Print----------------------------------
//Function receive the sudoku board and print it
void print(const int sudoku[][N*N])
{
	for(int row = 0; row < N*N; row++)

		for(int col = 0; col < N*N; col++)
        {
			if(col == N*N - 1)

                cout << sudoku[row][col] << endl;
            else

                cout << sudoku[row][col] << " ";
        }
}

