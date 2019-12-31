/*
 * String overlap
 * =============================================================
 * Written by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program receives characters from user to 2 strings.
 * Then the program checks if there is overlap between the strings
 * In the end prints the maximum length of overlap string.
 *
 * input:
 *  a. Characters to 2 strings.
 * output:
 *  a. The maximum length of overlap string
 */

//---------------Include---------------------
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

//-----------------Using---------------------
using std::cin;
using std::cout;
using std::endl;
using std::setw;

//---------------Constant---------------------
const int N = 100;

//---------------Prototypes---------------------
void input_strs(char str_1[], char str_2[]);
int max_str(const char str_1[], const char str_2[]);

//----------------Main---------------------
int main()
{
    char str_1[N], str_2[N];        //Strings

    input_strs(str_1, str_2);       //summon input function

    cout << max_str(str_1, str_2);  //summon max_str function
                                    //and print the return value
    return EXIT_SUCCESS;
}

//Input function------------------------------------
//function that receive characters from user
void input_strs(char str_1[], char str_2[])
{
    cin >> setw(N) >> str_1;

    cin >> setw(N) >> str_2;
}

//find sub string------------------------------------
//function that search the max length of sub string
int max_str(const char str_1[], const char str_2[])
{
    int counter =0, max_counter=0,          //variables
        ind_1=0, ind_2=0;

    while(str_1[ind_1] != '\0')           //run over the string until
    {                                     //ind_1= null terminated
        if(str_1[ind_1] == str_2[ind_2])  //if the values in strings are equal
        {                                 //count it, and increase the indexes
            counter++;                    //of each string by 1.
            ind_1++;
            ind_2++;
        }

        else if (counter > 0)   //if the values are not equal, but counter
        {                       //is bigger than 0
            counter=0;          //put 0 in counter
            ind_2=0;            //And start from the beginning of str_2
        }

        else          //if the values are not equal and counter is equal to 0
            ind_1++;  //increase the index of str_1 by 1.

        if(counter > max_counter)   //check if "counter" is bigger than
                                    //"max_counter", if so, put the value
            max_counter = counter;  //of "counter" in "max_counter"

        if(str_1[ind_1] == '\0' && max_counter == 0) //if the index of "str_1"
        {               //is equal to null terminated and "max_counter" is
            ind_1=0;    //equal to 0, put 0 in "ind_1" and increase "ind_2"
            ind_2++;    //by 1
        }

    }

    return max_counter;//return to main function the max length of sub string
}






