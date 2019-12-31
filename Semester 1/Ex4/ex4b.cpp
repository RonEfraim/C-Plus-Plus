/*
 * Find the Common number
 * =============================================================
 * Written by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program receives from the user 10 numbers.
 * Then the program prints the common number (numbers).
 *
 *
 * input:
 *  a. 10 numbers.
 *
 * output:
 *  a. Print the common number (numbers).
 */

//---------------Include---------------
#include <iostream>

//----------------Using----------------
using std::cin;
using std::cout;
using std::endl;

//---------------Constant---------------
const int NUM=10;

//-----------------Main-----------------
int main()
{
    int common[NUM], t_arr[NUM],                         //variables
        index, t_index, counter, temp=0, max_v=0, occupy=1;

//------------Input loop----------------
    for(index=0; index<NUM; index++)                     //a loop that receive
                                                         //numbers to array
        cin>>common[index];

//------------Find common loop---------------
    for(index=0; index<NUM; index++)                     //a loop that runs over the series
    {
        temp = common[index];         //Puts a number from the array in a temporary variable
        counter=1;

        for(t_index = index+1; t_index<NUM; t_index++)   //a loop that checks for
        {                                                //a common number
            if(temp == common[t_index])                  //if there is, count it.

                counter++;
        }

        if(counter > max_v)             //checks if "counter" is bigger then "max_value"
        {                               //if so, puts the value of "counter" in "max_v"
            max_v = counter;            //finally, puts the value of "temp" in first
            t_arr[0] = temp;            //cell of the temporary array
        }

        else if(counter == max_v)       //if "counter" is equal to "max_v"
        {                               //puts the value of "temp" in temporary array.
            t_arr[occupy]= temp;
            occupy++;
        }
    }

//---------------Output loop---------------
    for(index=0; index<occupy; index++)

        cout<<t_arr[index]<<endl;

    return 0;
}
