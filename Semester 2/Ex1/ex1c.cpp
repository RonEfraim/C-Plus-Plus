/*
 * Data Structure
 * =============================================================
 * written by: Ron Efraim, id:204661425, login:ronef
 *
 *
 * The program receives from the user a command
 * The program allows the user to perform the following actions
 * on the data structure
 *
 * al - add a new line to the data structure.
 * dl - delete the selected line from the data structure.
 * jl - join two selected lines from the data structure.
 * sl - split two selected lines from the data structure.
 * av - add a value to a selected line from the data structure.
 * dv - delete a value from exist line in data structure.
 * pr - present the data structure.
 * pg - clean the unused rows and cells from the data structure.
 * e -  end the program.
 *
 *
 * input:
 *  a. A command according to the instructions above.
 *
 */

//------------------------------Include---------------------------------------
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <iomanip>

//-------------------------------Using---------------------------------------
using std::ifstream;
using std::ofstream;
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::setw;
using std::getline;
using std::nothrow;

//------------------------------Constant--------------------------------------
const int OPTION = 3,
          ONE = 1;

//-----------------------------Prototype--------------------------------------
void menu_func();
void transfer_func(char choice[], int **&data_struct, int **&temp_1,
                   bool *&use_rows, bool *temp_bool, int *temp_2,
                   int &rows, int &rows_counter, int *&len_row,
                   int *&value_row, int &ind);
void add_row(int **&data_struct, int **&temp_1, bool *&use_rows,
             bool *temp_bool, int *temp_2,
             int &rows, int &rows_counter,
			 int *&len_row, int *&value_row, int &ind);
void alloc_rows(int **&data_struct, int **&temp_1, bool *&use_rows,
                int &rows, int &rows_counter,
                int *&len_row, int *&value_row);
void alloc_cells(int **&data_struct, int **&temp_1, bool *&use_rows,
                 int &rows, int &rows_counter,
                 int *&len_row, int *&value_row);
void alloc_value_row(int *temp_2, int *&value_row,
                     int &rows, int &rows_counter);
void alloc_len_row(int *temp_2, int *&len_row,
                   int &rows, int &rows_counter);
void alloc_bool(bool *&use_rows, bool *temp_bool,
                int &rows, int &rows_counter);
void del_row(int **&data_struct, bool *&use_rows, int *&len_row,
             int &rows_counter, int *&value_row, int inp_1);
void add_line(int **&data_struct, int **&temp_1, bool *&use_rows,
			   int &rows, int &rows_counter,
			   int *&len_row, int *&value_row, int inp_1, int inp_2);
void division_line(int **&data_struct, int **&temp_1, bool *&use_rows,
                   bool *temp_bool, int *temp_2, int &rows, int &rows_counter,
                   int *&len_row, int *&value_row,int inp_1, int num);
void add_num(int **&data_struct, int **&temp_1, bool *&use_rows, int &rows,
             int &rows_counter, int *len_row, int *&value_row,
             int inp_1, int num);
void del_num(int **&data_struct, int **&temp_1, bool *&use_rows, int &rows,
             int &rows_counter, int *&len_row, int *&value_row,
             int inp_1, int num);
void perform_data_struct(int **&data_struct, int **&temp_1, bool *&use_rows,
                         int &rows, int &rows_counter,
                         int *&len_row, int *&value_row);
void clean_data_struct(int **&data_struct, int **&temp_1, bool *&use_rows,
                       int &rows, int &rows_counter,
                       int *&len_row, int *&value_row);
void delete_p(int **data_struct, int **temp_1,
              bool *use_rows, bool *temp_bool,
              int *temp_2, int *len_row, int *value_row);

//-------------------------------Main-----------------------------------------
int main()
{
    menu_func();


return EXIT_SUCCESS;
}
//menu_func-------------------------------------------------------------------
//Function that read command from user
void menu_func()
{
	int ind = 0,
        rows = 0,
		rows_counter = 0;
	int *len_row = 0,
		*value_row = 0,
		*temp_2;
	int **data_struct,
        **temp_1;

	bool *use_rows;
	bool *temp_bool;

	char choice[OPTION];

	cin >> setw(OPTION) >> choice;

	while(strcmp(choice, "e") != 0)
	{
		transfer_func(choice, data_struct, temp_1, use_rows, temp_bool,
                      temp_2, rows, rows_counter, len_row, value_row, ind);

		cin >> setw(OPTION) >> choice;
	}

	delete_p(data_struct, temp_1, use_rows, temp_bool, temp_2,
             len_row, value_row);

	exit(EXIT_SUCCESS);
}

//transfer_func---------------------------------------------------------------
//Function that get the user's command and send it to the appropriate function
void transfer_func(char choice[], int **&data_struct, int **&temp_1,
                   bool *&use_rows, bool *temp_bool, int *temp_2,
                   int &rows, int &rows_counter, int *&len_row,
                   int *&value_row, int &ind)
{
	int inp_1, inp_2,
		num;

	if(strcmp(choice, "al") == 0)

		add_row(data_struct, temp_1, use_rows, temp_bool, temp_2,
			 	 rows, rows_counter, len_row, value_row, ind);

	else if(strcmp(choice, "dl") == 0)
	{
		cin >> inp_1;

		del_row(data_struct, use_rows, len_row, rows_counter,
                value_row, inp_1);
	}

	else if(strcmp(choice, "jl") == 0)
	{
		cin >> inp_1 >> inp_2;

		add_line(data_struct, temp_1, use_rows, rows, rows_counter,
                 len_row, value_row, inp_1, inp_2);
	}

	else if(strcmp(choice, "sl") == 0)
	{
		cin >> inp_1 >> num;

		division_line(data_struct, temp_1, use_rows, temp_bool, temp_2,
                      rows, rows_counter, len_row, value_row, inp_1, num);
	}

	else if(strcmp(choice, "av") == 0)
	{
		cin >> inp_1 >> num;

		add_num(data_struct, temp_1, use_rows, rows, rows_counter,
                len_row, value_row, inp_1, num);
	}

	else if(strcmp(choice, "dv") == 0)
	{
		cin >> inp_1 >> num;

		del_num(data_struct, temp_1, use_rows, rows, rows_counter,
                len_row, value_row, inp_1, num);
	}

	else if(strcmp(choice, "pr") == 0)

		perform_data_struct(data_struct, temp_1, use_rows, rows,
                            rows_counter, len_row, value_row);

	else if(strcmp(choice, "pg") == 0)

		clean_data_struct(data_struct, temp_1, use_rows, rows,
                          rows_counter, len_row, value_row);
}

//add_row---------------------------------------------------------------------
//Function that insert a new row to data structure
void add_row(int **&data_struct, int **&temp_1, bool *&use_rows,
             bool *temp_bool, int *temp_2,
             int &rows, int &rows_counter,
			 int *&len_row, int *&value_row, int &ind)
{
	int input;

	cin >> input;

	for(int ind_1 = 0; ind_1 < rows; ind_1++)
	{
		if(len_row[ind_1] == 0)
		{
			ind = ind_1;
			len_row[ind] = 1;
			break;
		}
	}

	while(input != 0)
	{
		if(rows == 0)
		{
			data_struct = new(nothrow) int*[ONE];

			if(data_struct == NULL)
			{
				cerr << "cannot allocate memory";

				exit (EXIT_FAILURE);
			}

			data_struct[rows_counter] = new(nothrow) int[ONE];

			value_row = new(nothrow) int[ONE];

			len_row = new(nothrow) int[ONE];

			use_rows = new(std::nothrow) bool[ONE];

			if(value_row == NULL && len_row == NULL &&
               data_struct == NULL && use_rows == NULL)
			{
				cerr << "cannot allocate memory";

				exit (EXIT_FAILURE);
			}

			len_row[ind]++;

			rows++;

			use_rows[ind] = true;
		}

		else if(rows_counter == rows)
		{
			rows *= 2;

			alloc_value_row(temp_2, value_row, rows, rows_counter);

			alloc_len_row(temp_2, len_row, rows, rows_counter);

			alloc_bool(use_rows, temp_bool, rows, rows_counter);

			len_row[ind] ++;

			use_rows[ind] = true;

			alloc_rows(data_struct, temp_1, use_rows, rows, rows_counter,
                       len_row, value_row);
		}

		if(value_row[ind] == len_row[ind])
		{
			len_row[ind] *= 2;

			alloc_cells(data_struct, temp_1, use_rows, rows, rows_counter,
                        len_row, value_row);
		}

		data_struct[rows_counter][value_row[ind]] = input;

		value_row[ind]++;

		cin >> input;
	}

	use_rows[ind] = true;

	ind++;

	rows_counter++;

	len_row[ind] = 1;
}

//alloc_rows---------------------------------------------------------------------
//Function that allocate rows for data structure
//than copy row from data structure to temporary matrix,
//and than send the data structure to pointer like the temporary matrix.
void alloc_rows(int **&data_struct, int **&temp_1, bool *&use_rows,
                int &rows, int &rows_counter,
                int *&len_row, int *&value_row)
{
	temp_1 = new (nothrow) int *[rows];

	if(temp_1 == NULL)
	{
		cerr << "cannot allocate memory";

		exit (EXIT_FAILURE);
	}

	for(int ind = 0; ind < rows; ind++)
	{
		temp_1[ind] = new(nothrow) int[len_row[ind]];

		if(temp_1 == NULL)
		{
			cerr << "cannot allocate memory";

			exit (EXIT_FAILURE);
		}
	}

	for(int ind_1 = 0; ind_1 < rows; ind_1++)

		for(int ind_2 = 0; ind_2 < value_row[ind_1]; ind_2++)

			temp_1[ind_1][ind_2] = data_struct[ind_1][ind_2];

	data_struct = temp_1;
}

//alloc_cells---------------------------------------------------------------------
//Function that allocate cells for data structure
//than copy data structure to temporary array,
//and than send the data structure to pointer like the temporary array.
void alloc_cells(int **&data_struct, int **&temp_1, bool *&use_rows,
                 int &rows, int &rows_counter,
                 int *&len_row, int *&value_row)
{
	temp_1 = new (nothrow) int *[rows];

	if(temp_1 == NULL)
	{
		cerr << "cannot allocate memory";

		exit (EXIT_FAILURE);
	}

	for(int ind = 0; ind < rows; ind++)
	{
		temp_1[ind] = new (nothrow) int [len_row[ind]];

		if(temp_1 == NULL)
		{
			cerr << "cannot allocate memory";

			exit (EXIT_FAILURE);
		}
	}

	for(int ind_1 = 0; ind_1 < rows; ind_1++)

		for(int ind_2 = 0; ind_2 < value_row[ind_2]; ind_2++)

			temp_1[ind_1][ind_2] = data_struct[ind_1][ind_2];

	data_struct = temp_1;
}
//alloc_value_row-------------------------------------------------------------
void alloc_value_row(int *temp_2, int *&value_row,
                     int &rows, int &rows_counter)
{
	temp_2 = new(nothrow) int[rows];

	if(temp_2 == NULL)
	{
		cerr << "cannot allocate memory";

		exit (EXIT_FAILURE);
	}
	for(int ind = 0; ind < rows_counter; ind++)

		temp_2[ind] = value_row[ind];

	value_row = temp_2;
}

//alloc_len_row---------------------------------------------------------------
void alloc_len_row(int *temp_2, int *&len_row,
                   int &rows, int &rows_counter)
{
	temp_2 = new(nothrow) int[rows];

	if(temp_2 == NULL)
	{
		cerr << "cannot allocate memory";

		exit (EXIT_FAILURE);
	}
	for(int ind = 0; ind < rows_counter ; ind++)

		temp_2[ind] = len_row[ind];

	len_row = temp_2;
}
//alloc_bool------------------------------------------------------------------
void alloc_bool(bool *&use_rows, bool *temp_bool,
                int &rows, int &rows_counter)
{
	temp_bool = new(nothrow) bool[rows];

	if(temp_bool == NULL)
	{
		cerr << "cannot allocate memory";

		exit (EXIT_FAILURE);
	}

	for(int ind = 0; ind < rows_counter; ind++)

		temp_bool[ind] = use_rows[ind];

	use_rows = temp_bool;
}

//del_row---------------------------------------------------------------------
//Function that delete a selected row from data structure
void del_row(int **&data_struct, bool *&use_rows, int *&len_row,
             int &rows_counter, int *&value_row, int inp_1)
{
	if(inp_1 <= rows_counter)
	{
		value_row[inp_1] = 0;

		len_row[inp_1] = 0;

		rows_counter--;
	}
}

//add_line--------------------------------------------------------------------
//Function that add a line to data structure
void add_line(int **&data_struct, int **&temp_1, bool *&use_rows,
			   int &rows, int &rows_counter,
			   int *&len_row, int *&value_row, int inp_1, int inp_2)
{
	int index = 0;

	if(inp_1 > rows_counter - 1 || inp_2 > rows_counter - 1)

        return;

	do
	{
		if(value_row[inp_1] == len_row[inp_1])
		{
			len_row[inp_1] *= 2;

			alloc_cells(data_struct, temp_1, use_rows, rows,
                        rows_counter, len_row, value_row);
		}

		data_struct[inp_1][value_row[inp_1]] = data_struct[inp_2][index];

		value_row[inp_1]++;

		index++;
	}

	while(index < value_row[inp_2]);

	value_row[inp_2] = 0;

	len_row[inp_2] = 0;

	rows_counter--;
}

//division_line---------------------------------------------------------------
//Function that split two selected lines from data structure
void division_line(int **&data_struct, int **&temp_1, bool *&use_rows,
                   bool *temp_bool, int *temp_2, int &rows, int &rows_counter,
                   int *&len_row, int *&value_row,int inp_1, int num)
{
	int row_new;

	for(int ind = 0 ; ind < rows ; ind++)
	{
		if(use_rows[ind] == false)
		{
			row_new = ind;

			if(value_row[inp_1] - num < len_row[row_new])
            {
				for(int ind = num, i = 0; ind < value_row[inp_1]; ind++, i++)
				{
					data_struct[row_new][i] = data_struct[inp_1][ind];

					value_row[inp_1]--;
				}
            }

			if(num == 0)

				use_rows[inp_1] = false;
		}
	}

	if(rows <= rows_counter)
	{
		rows *= 2;

		alloc_rows(data_struct, temp_1, use_rows, rows, rows_counter,
                   len_row, value_row);

		row_new = inp_1 + 1;

		len_row[row_new] = 1;

		while(len_row[row_new] < value_row[inp_1] - num)
		{
			len_row[row_new] *= 2;

			alloc_cells(data_struct, temp_1, use_rows, rows, rows_counter,
                        len_row, value_row);
		}

		for(int ind = num, i = 0; ind <= len_row[inp_1] - num; ind++, i++)
		{
			data_struct[row_new][i] = data_struct[inp_1][ind];

			value_row[inp_1]--;

			value_row[row_new]++;
		}
	}

	use_rows[row_new] = true;

	rows_counter++;
}
//add_num---------------------------------------------------------------------
//Function that add a value to selected line from data structure
void add_num(int **&data_struct, int **&temp_1, bool *&use_rows, int &rows,
             int &rows_counter, int *len_row, int *&value_row,
             int inp_1, int num)
{
	if(inp_1 <= rows_counter)
	{
		if(value_row[inp_1] == len_row[inp_1])
		{
			len_row[inp_1] *=2;

			alloc_cells(data_struct, temp_1, use_rows, rows, rows_counter,
                        len_row, value_row);
		}

		data_struct[inp_1][value_row[inp_1]] = num;

		value_row[inp_1]++;
	}
}
//del_nu----------------------------------------------------------------------
//Function that delete a value on a selected line from data structure
void del_num(int **&data_struct, int **&temp_1, bool *&use_rows, int &rows,
             int &rows_counter, int *&len_row, int *&value_row,
             int inp_1, int num)
{
	if(inp_1 <= rows_counter)
	{
		for(int index = 0 ; index < value_row[inp_1] ; index++)
		{
			if(data_struct[inp_1][index] == num)
			{
				for(int i = index ; i < value_row[inp_1] ; i++)

					data_struct[inp_1][i] = data_struct[inp_1][i+1];

				value_row[inp_1]--;

				return;
			}
		}
	}
}
//perform_data_struct---------------------------------------------------------
//Function that perform the data structure
void perform_data_struct(int **&data_struct, int **&temp_1, bool *&use_rows,
                         int &rows, int &rows_counter,
                         int *&len_row, int *&value_row)
{
	if(rows == 0)
	{
		cout << rows << " "
             << rows_counter << endl;

		return;
	}

	cout << rows << " "
         << rows_counter << endl;

	for(int ind_1 = 0; ind_1 < use_rows[ind_1]; ind_1++)
	{
		cout << ind_1 << " "
             << len_row[ind_1] << " "
             << value_row[ind_1] << " ";

		for(int ind_2 = 0; ind_2 < value_row[ind_1] ; ind_2++)

			cout << data_struct[ind_1][ind_2] << " ";


		cout << endl;
	}
}
//clean_data_struct-------------------------------------------
//Function that clean the unused rows and cells from data structure.
void clean_data_struct(int **&data_struct, int **&temp_1, bool *&use_rows,
                       int &rows, int &rows_counter,
                       int *&len_row, int *&value_row)
{
	rows = rows_counter;

	alloc_rows(data_struct, temp_1, use_rows, rows, rows_counter,
               len_row, value_row);

	for(int ind = 0 ; ind < rows_counter ; ind++)
	{
		len_row[ind] = value_row[ind];

		alloc_rows(data_struct, temp_1, use_rows, rows, rows_counter,
                   len_row, value_row);
	}
}

//delete_p--------------------------------------------------------------------
//Function that free the allocated memory
void delete_p(int **data_struct, int **temp_1,
              bool *use_rows, bool *temp_bool,
              int *temp_2, int *len_row, int *value_row)
{
	for(int ind = 0; data_struct[ind] != NULL; ind++)

		delete[] data_struct[ind];

	for(int ind_1 = 0 ; temp_1[ind_1] != NULL ; ind_1++)

		delete[] temp_1[ind_1];

	delete[] data_struct;
	delete[] temp_1;
	delete[] temp_bool;
	delete[] temp_2;
	delete[] len_row;
	delete[] value_row;
}
