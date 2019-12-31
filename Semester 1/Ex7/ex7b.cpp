/*
 * Locating text in dictionary
 * =============================================================
 * Written by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program receives characters from the user to 2 strings.
 * Then the program checks if "text" (string) is exists in dictionary,
 * In the end the program prints the longest sub string and where it's start
 *
 * input:
 *  a. Characters to 2 strings.
 * output:
 *  a. where the sub string is start
 *  b. the longest sub string
 */


//--------------------Include-----------------------
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include <cstring>

//--------------------Using-------------------------
using std::cout;
using std::cin;
using std::endl;
using std::setw;

//-------------------Constant-----------------------
const int MAX_STRS = 10;
const int MAX_STR_LEN = 8;
const int MAX_TEXT_LEN = 100;

//------------------Prototypes----------------------
void input_dict(char dict[][MAX_STR_LEN]);
void input_text(char text[]);
int check_words(char text[],
                      char dict[][MAX_STR_LEN],
                      int &len);
bool exist_in_dict(char dict[][MAX_STR_LEN],
                   char curr_str[]);
int start_and_count(int locate_array[],
                        int &len);

//--------------------Main--------------------------
int main()
{
    char dict[MAX_STRS][MAX_STR_LEN];
    char text[MAX_TEXT_LEN];
    int length;

    //summon input functions
    input_dict(dict);

    input_text(text);

    //summon "
    cout<<check_words(text,dict,length)<<"  ";
    cout<<length;

    return EXIT_SUCCESS;
}

//input dict----------------------------------------
//Function that read characters and input them in string.
void input_dict(char dict[][MAX_STR_LEN])
{
    int ind;

    for(ind=0; ind<MAX_STRS; ind++)
    {
        //peek until '.'
        if (cin.peek() == '.')
        {
            //when find '.' eat
            cin.get();
            break;
        }

        cin.getline(dict[ind],MAX_STR_LEN,' ');
    }
}

//input text----------------------------------------
//Function that read line from input.
void input_text(char text[])
{
    //when find \n eat.
    cin.get();
    //input to text
    cin.getline(text, MAX_TEXT_LEN);
}

//check words---------------------------------------
//Function that receive "text" and send every word to check if it exists
//in the dictionary
int check_words(char text[],
                char dict[][MAX_STR_LEN],
                int &len)
{
    int ind_text = 0, ind_curr = 0, temp;   //variables
    int locate_array[MAX_TEXT_LEN]={0};     //array of zero
    char curr_str[MAX_TEXT_LEN];            //temporary string

    //Run over "text" string until null terminated
    while(text[ind_text]!= '\0')
    {
        //keep running until character is not space and null terminated
        while(text[ind_text] != ' ' && text[ind_text] != '\0')
        {                                       //copy the characters from
            curr_str[ind_curr] = text[ind_text];//"text" to "curr_str"
            ind_text++;
            ind_curr++;     //increase the indexes of each string by 1
        }

        if(ind_curr>0)   //check if the index of "curr_str" is greater than 0
        {                //if so, put null terminated in "curr_str"
            curr_str[ind_curr] = '\0';

            if(exist_in_dict(dict,curr_str))//summon boolean function, if the
            {                  //function return true put 1 in "locate_array"
                for(temp = ind_text - ind_curr; temp<ind_text; temp++)
                {
                    locate_array[temp] = 1;
                }
            }
            else      //if the function return false put -1 in "locate_array"
            {
                for(temp = ind_text-ind_curr; temp<ind_text; temp++)
                {
                    locate_array[temp] = -1;
                }
            }
        }


        ind_text++; //text index increase by 1
        ind_curr=0; //put 0 in the index of "curr_str"
    }
    //summon "start_and_count" function and return the value (len) to main
    return(start_and_count(locate_array,len));
}

//exist in dictionary-------------------------------
//function that check if the text exists in dictionary
bool exist_in_dict(char dict[][MAX_STR_LEN],
                   char curr_str[])
{
    int index1, index2;     //variables

    //run until "index1" is no longer smaller than "MAX_STRS"
    for(index1=0; index1<MAX_STRS; index1++)
    {
        //run until "index2" is no longer smaller than "MAX_STRS"
        //and "dict", "text" are not reach to null terminated
        for(index2=0; index2<MAX_STR_LEN && dict[index1][index2] != '\0'
                          && curr_str[index2] != '\0'; index2++)
        {
            //if the value in "dict" and "text" are not equal
            //break the loop
            if(dict[index1][index2] != curr_str[index2])

                break;
        }

        //if the value in "dict" and "text" reach to null terminated
        //return true to "check_words" function
        if(dict[index1][index2] == '\0' && curr_str[index2] == '\0')

            return true;
    }

    return false;   //if the word is not exist in "dict" return false
}                   //to "check_words" function

//start and count---------------------------------------
//Function that count max length of sub string and
//return where it's start
int start_and_count(int locate_array[],
                    int &len)
{
    int start_index = 0, counter = 1;

    len=0;

    //run until "index1" is no longer smaller than "MAX_TEXT_LEN"
    for(int index1=0; index1 < MAX_TEXT_LEN; index1++)
    {
        //check if the value in "locate_array" is equal to 1
        if(locate_array[index1] == 1)
        {
            //run until "index1" is no longer smaller than "MAX_TEXT_LEN"
            //and the next value of "locate_array" is not equal to -1
            while(index1 < MAX_TEXT_LEN && locate_array[index1++]!= -1)
            {
                counter++;  //increase "counter" by 1
            }

            while(index1 > -1 && locate_array[index1--]!= 1)
            {
                counter--;
            }

            index1 += 2;    //increase "index1" by 2

            counter++;      //increase "counter" by 1

            if(len < counter)   //check if "counter" is greater than "len"
            {                   //if so, put the value of "counter" in "len"
                len = counter;
                start_index = index1 - counter;
            }

            counter = 1;
        }
    }
    return start_index; //return the value of "start_index"
                        //to "check_words" function
}
