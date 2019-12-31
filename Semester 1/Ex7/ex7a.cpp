/*
 * Strings
 * =============================================================
 * Writen by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program receives from user characters
 * Part A
 * The program checks if there is characters in lowercase and changes
 * them to uppercase. if there is digits or punctuation remove them
 * Part B
 * The program checks if there is similar characters or signs,
 * if exists the program remove them.
 *
 * input:
 *  a. Characters and signs.
 * output:
 *  a. String that show only upper cases.
 *  b. String of characters and signs.
 */


//----------------Include-----------------
#include <iomanip>
#include <iostream>
#include <cstring>
#include <cstdlib>

//----------------Using-----------------
using std::cin;
using std::cout;
using std::endl;
using std::setw;

//----------------Constant-----------------
const int MAX_STR_LEN=100;

//----------------Prototypes-----------------
void input_func(char first_str[MAX_STR_LEN],
                char second_str[MAX_STR_LEN],
                char copy_first[MAX_STR_LEN]);
void upper_letters(char first_str[MAX_STR_LEN]);
void compare_strings(char copy_first[MAX_STR_LEN],
                     char second_str[MAX_STR_LEN]);

//------------------Main----------------------
int main()
{
    char first_str[MAX_STR_LEN],        //Strings
         second_str[MAX_STR_LEN],
         copy_first[MAX_STR_LEN];

    input_func(first_str, second_str, copy_first);  //summon input function

    upper_letters(first_str);       //summon "upper_letters" function

    compare_strings(copy_first, second_str);//summon "compare_strings"function


    return EXIT_SUCCESS;
}

//input function---------------------------------------
//function that receive characters from user
void input_func(char first_str[MAX_STR_LEN],
                char second_str[MAX_STR_LEN],
                char copy_first[MAX_STR_LEN])
{
    cin >> setw(MAX_STR_LEN) >> first_str;

    cin >> setw(MAX_STR_LEN) >> second_str;

    strcpy(copy_first, first_str);  //copy the values from "first_str"
}                                   //to "copy_first"

//upper_letters function----------------------------------
//function that print a string with uppercase letters only
void upper_letters(char first_str[MAX_STR_LEN])
{
    for(int index=0; first_str[index] != '\0'; index++) //run over "first_str"
    {
        if(isdigit(first_str[index]))   //check if there is digit in
        {                               //"first_str", if so, "eat" the digit
            for(int temp=index; first_str[temp] != '\0'; temp++)

                first_str[temp] = first_str[temp + 1];

            index--;
        }

        else if(ispunct(first_str[index]))//check if there is punctuation
        {                                 //in "first_str", if so, "eat" them
            for(int temp=index; first_str[temp] != '\0'; temp++)

                first_str[temp] = first_str[temp + 1];

            index--;
        }

        if(islower(first_str[index]))//check if there is lowercase letters
                                     //if so, change them to uppercase
            first_str[index] = first_str[index] - 32;
    }

    cout << first_str << endl;  //print the string with uppercase only
}

//compare_strings function----------------------------------
//function that compare two strings
void compare_strings(char copy_first[MAX_STR_LEN],
                     char second_str[MAX_STR_LEN])
{
    //run over "second_str"
    for(int ind_2=0; second_str[ind_2] != '\0'; ind_2++)

        //run over "copy_first"
        for(int ind_1=0; copy_first[ind_1] != '\0'; ind_1++)

            //check if the values of strings are equal
            if(second_str[ind_2] == copy_first[ind_1])

                for(int ind_3=ind_1; copy_first[ind_3] != '\0'; ind_3++)
            //if there is equal values, take the next value of "copy_string"
            //and put it instead the equal value
                    copy_first[ind_3] = copy_first[ind_3 + 1];

    cout << copy_first; //print the string without equal values
}
