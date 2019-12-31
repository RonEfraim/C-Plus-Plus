/*
 * Input and Output
 * =============================================================
 * Written by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program receives a input file.
 * Then the reading line by line and change the line according to the
 * following categories
    - if there is a letter print 'a'
    - if there is a number print '0'
    - if the string are mixed (letters, numbers and other) symbols print 'x'.
    - if there are similar strings print only one.
 *
 * In the end,the program prints the characters in the output file.
 *
 * input:
 *  a. File with characters.
 *
 * output:
 *  a. According to the above instructions.
 */

//----------------Include------------------------
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

//------------------Using------------------------
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::setw;
using std::ifstream;
using std::ofstream;

//----------------Constant-----------------------
const int MAX_STR_LEN = 100;

//----------------Prototype----------------------
void check(ifstream &inp_fd, ofstream &out_fd);
void print_func(ofstream &out_fd, int str_size, char replacement);

//--------------------Main-----------------------
int main()
{
    char input[MAX_STR_LEN],
         output[MAX_STR_LEN];

    //open files
    ifstream inp_fd;

    ofstream out_fd;

    cin >> setw(MAX_STR_LEN) >> input;

    inp_fd.open(input);

    cin >> setw(MAX_STR_LEN) >> output;

    out_fd.open(output);

    //if the files did not open correctly
    if(!inp_fd.is_open() || !out_fd.is_open())
    {
        cerr << "can not open input file";

        exit(EXIT_FAILURE);
    }

    check(inp_fd, out_fd);


    return EXIT_SUCCESS;
}

//Check------------------------------------------
//function that receive the input and the output files
//the function change any characters
void check(ifstream &inp_fd,
           ofstream &out_fd)
{
    char prev_str[MAX_STR_LEN] = "\0",
         curr_str[MAX_STR_LEN];

    int num_count = 0, alpha_count = 0,
        other_count = 0;

    //run until end of file
    while(!inp_fd.eof())
    {
        int space_count = 0, str_size = 0;

        bool num = true,
             alpha = true;

        while(inp_fd.peek() == ' ')
        {
            inp_fd.get();
            space_count++;
        }

        if(inp_fd.peek() == '\n')
        {
            inp_fd.get();
            out_fd << '\n';
            continue;
        }

        inp_fd >> setw(MAX_STR_LEN) >> curr_str;

        //if the strings are not the same
        if(strcmp(curr_str, prev_str) != 0)
        {
            print_func(out_fd, space_count, ' ');

            str_size = strlen(curr_str);

            for(int index = 0; index < str_size; index++)
            {
                if(!isalpha(curr_str[index]))

                    alpha = false;

                if(!isdigit(curr_str[index]))

                    num = false;
            }
            //if the string is mixed
            if(!alpha && !num)
            {
                other_count++;

                print_func(out_fd, str_size, 'x');
            }
            //if the string is numbers
            else if(num)
            {
                num_count++;

                print_func(out_fd, str_size, '0');
            }
            //if the string is letters
            else
            {
                alpha_count++;

                print_func(out_fd, str_size, 'a');
            }
        }

        strcpy(prev_str, curr_str);
    }

    cout << alpha_count << " "
         << num_count << " "
         << other_count << endl;
}

//Print------------------------------------------
//function that receive the output file, the size of the string
//and the character to replacement.
void print_func(ofstream &out_fd,
                int str_size,
                char replacement)
{
    for(int index = 0; index < str_size; index++)

        out_fd << replacement;
}


