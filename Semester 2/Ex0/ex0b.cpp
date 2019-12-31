/*
 * Delete Documentation
 * =============================================================
 * Written by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program receives a program code or group of words.
 * Then the program delete all documentation.
 * In the end,the program prints the code or the words without documentation.
 *
 * input:
 *  a. program code or group of words.
 *
 * output:
 *  a. print without documentation.
 */

//----------------Include------------------------
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

//------------------Using------------------------
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::setw;
using std::getline;

//----------------Constant-----------------------
const int MAX_LINE_LEN = 200;

//----------------Prototype----------------------
void input(char str[], int &counter);
void del_documentation(char str[], int &counter);

//--------------------Main-----------------------
int main()
{
    char str[MAX_LINE_LEN];
    int counter = 0;

    input(str, counter);

    return EXIT_SUCCESS;
}

//Input------------------------------------------
//function that receive a line from text and summon delete function
void input(char str[], int &counter)
{
    cin.getline(str, MAX_LINE_LEN);

    while(!cin.eof())

        del_documentation(str, counter);

    if(counter != 0)

        cerr<< "Error in input. Program ended in a comment. depth = "
            << endl ;

    exit(EXIT_SUCCESS);
}

//Del_documentation------------------------------
//function that receive a line and check if there are any documentation
//the function also counting how many long documentation (/*) exist.
void del_documentation(char str[], int &counter)
{
    bool still_open = false;

    if(str[0] == '\0' && !still_open)

        cout << endl;

    for(int index = 0; index < strlen(str); index++)
    {
        if(str[index] == '/')
        {
            if(str[index+1] == '/')

                input(str, counter);

            else if(str[index+1] == '*')
            {
                still_open = true;
                counter++;
                index++;
            }

            continue;
        }

        else if(str[index] == '*')
        {
            if(str[index+1] == '/')
            {
                counter--;

                if(counter == 0)
                {
                    still_open = false;
                    cout<<endl;
                }
            }

            else if(str[index+1] == '*')
            {
                still_open = true;
            }
        }

        else if(!still_open && counter == 0)

            cout << str[index];

        //if the line is empty and there is no open documentation
        if(str[index+1] == '\0' && !still_open)

        	if(counter == 0)

        		cout << endl;

        //if there is an unnecessary sign (*/)
        if(counter < 0 && !still_open)

            exit(EXIT_FAILURE);
    }

    input(str, counter);
}
