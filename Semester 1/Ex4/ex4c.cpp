/*
 * find loop in the array
 * =============================================================
 * Written by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program receives from the user 10 numbers.
 * Then the program checks if there is a loop in the array
 *
 *
 * input:
 *  a. 10 numbers.
 *
 * output:
 *  a. The numbers of cells that contain the loop.
 */

//------------Include---------------
#include <iostream>

//-------------Using----------------
using std::cout;
using std::cin;
using std::endl;

//------------Constant--------------
const int SIZE=10;

//--------------Main----------------
int main()
{
    int index=0, j=0,               //variable to run over the arrays.
        cell=0, value=0, occupy=0,
        input_arr[SIZE],            //array to receive numbers from user.
        num_of_cells[SIZE]= {0};    //array to save number of cells.

    bool loop=false;                //boolean variable

//--------------Input loop---------------
    for(index=0; index<SIZE; index++)

        cin>>input_arr[index];

//--------------Main loop----------------
    for(index=0; index<SIZE; index++)
    {
        cell = index;                    //puts the value of "index" in "cell"
        value = input_arr[index];        //puts the value from the first cell in array
                                         //in "value"
        while(value < SIZE && !loop)     //as long as "value" is smaller than "SIZE"
        {                                //and "loop" is false enter the loop.
            num_of_cells[occupy] = cell;    //puts the value of "cell" in "num_of_cells" array
            occupy++;
            cell = value;                   //puts the value of "value" in "cell"

            if(input_arr[value] == index)       //checks if the value in the array
            {                                   //is equal to "index"
                num_of_cells[occupy] = cell;  //if so, puts the value of "cell" in "num_of_cells" array,
                loop = true;                  //then switch "loop" to true.
                break;                        //and get out of the loop.
            }

            else                              //if the value in the array is not equal to "index"
                value = input_arr[value];     //puts the value from the "input_arr" in "value"
        }

        if(loop)                             //if "loop" is true
        {                                    //run over the "num_of_cells" array
            for(j=0; j <= occupy; j++)       //and print only the cells with the relevant value
                cout<<num_of_cells[j]<<" ";

            cout<<index;

            break;
        }

        else                  //if "loop" is false
            occupy=0;         //reset the value of "occupy" and return to another round
    }

    return 0;
}
