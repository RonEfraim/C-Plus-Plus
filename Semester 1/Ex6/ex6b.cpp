/*
 * Containing row
 * =============================================================
 * Written by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program receives from the user 20 numbers.
 * Then the program checks if there is a row that contain all the values.
 * In the end, the program checks if there is a row that contain the same
 * quantity of values.
 *
 *
 * input:
 *  a. 20 numbers to a matrix, 4 rows and 5 columns.
 *
 * output:
 *  a. Print the row containing all values in the matrix.
 *  b. Print the row contain the same quantity of values.
 *  c. if there is no containing row the output is "-1".
 */


//----------Include--------------------
#include <iostream>
#include <cstdlib>

//----------Using--------------------
using std::cin;
using std::cout;
using std::endl;

//----------Constant--------------------
const int ROWS=4,
          COLS=5;

//----------Prototypes------------------
void input_func(int locate[][COLS]);
void contain_func(const int locate[][COLS]);
bool check_row(const int locate[][COLS], int out_row);
bool check_col(const int locate[][COLS], int out_row, int in_row);
void contain_quantity(const int locate[][COLS]);
bool row_quantity(const int locate[][COLS], int out_r);
bool check_quantity(const int locate[][COLS], int out_r, int in_r);

//-------------Main--------------------
int main()
{
    int locate[ROWS][COLS];         //Array of 2D

    input_func(locate);             //summon functions to Main function
    contain_func(locate);
    contain_quantity(locate);

    return EXIT_SUCCESS;
}

//-------------Input Function--------------------
//receive numbers into matrix

void input_func(int locate[][COLS])
{
    for(int ind_row=0; ind_row<ROWS; ind_row++)

        for(int ind_col=0; ind_col<COLS; ind_col++)

            cin>>locate[ind_row][ind_col];
}
//Part A-------------------------------------------
//-------------Contain function--------------------
//check if there is a containing row in the matrix
//the function receive the matrix

void contain_func(const int locate[][COLS])
{
    int out_row=0;          //variable
    bool found=false;       //boolean variable

    for(out_row=0; out_row<ROWS; out_row++)  //run over the containing row
    {
        if(check_row(locate, out_row))  //summon "check_row" boolean function
        {                               //if the function returns "true", puts
            found = true;        //"true" in "found", and then break the loop.
            break;
        }                               //if the function returns "false",
        else                            //puts "false" in "found", and
            found = false;              //keep looking for containing row.
    }
    if(found)                   //checks if "found" is true
        cout<<out_row<<endl;    //if so, print the containing row.

    else                   //if "found" is false
        cout<<"-1"<<endl;  //print "-1", it means, there is no containing row
}

//-------------Check row--------------------
//check if there is a contained row in the matrix
//the function receive the matrix, and the containing row

bool check_row(const int locate[][COLS], int out_row)
{
    int in_row=0;           //variable
    bool same = false;      //boolean variable

    for(in_row=0; in_row<ROWS; in_row++)    //run over the contained row
    {                           //check if the contained row ("in_row")
        if(in_row != out_row)   //is not equal to containing row ("out_row")
        {                       //if they are not equal,
            if(check_col(locate, out_row, in_row))  //summon "check_col"
            {                                       //boolean function
                same = true;  //if the function returns "true", puts
                continue;     //"true" in "same", and then continue the loop.
            }
            else              //if the function returns "false",
                same = false; //puts "false" in "same", and
        }                     //keep looking for contained row.
    }
    if(!same)           //checks if "same" is false, if so, return to
        return false;   //"contain_func" the value false.
    else                //if "same" is true, return to
        return true;    //"contain_func" the value true.
}

//-------------Check column--------------------
//check if there is a contained row in the matrix
//the function receive the matrix, the containing row, and the contained row

bool check_col(const int locate[][COLS], int out_row, int in_row)
{
    bool same=false;    //boolean variable

    //run over the contained column
    for(int in_col=0; in_col<COLS; in_col++)
    {
        //run over the containing column
        for(int out_col=0; out_col<COLS; out_col++)
        {
            //check if the values are equal, if they are,
            //change the boolean variable, "same" to true,
            // and then break the loop.
            if(locate[out_row][out_col] == locate[in_row][in_col])
            {
                same = true;
                break;
            }

            else            //if the values are not equal, change the boolean
                same = false;   //variable "same" to false.
        }
        if(!same)   //check if "same" is false. if so, break the loop
            break;
    }
    if(!same)   //check if "same" is false, if so, return to "check_row"
        return false;   //the value false.

    else        //if "same" is true, return to "check_row"
        return true;    //the value true.
}


//Part B------------------------------------------
//-------------Row containing all values--------------------
//check if there is a row containing all values in the matrix
//the function receive the matrix

void contain_quantity(const int locate[][COLS])
{
    int out_r=0;        //variable
    bool found=false;   //boolean variable

    for(out_r=0; out_r<ROWS; out_r++)   //run over the containing row
    {
        if(row_quantity(locate, out_r)) //summon "row_quantity" boolean
        {                           //function if the function returns "true",
            found = true;           //puts "true" in "found", and then
            break;                  //break the loop.
        }
        else                        //if the function returns "false",
            found = false;          //puts "false" in "found", and
    }                               //keep looking for containing row.
    if(!found)        //checks if "found" is false
        cout<<"-1";   //print "-1" , it means, there is no containing row
    else              //checks if "found" is true
        cout<<out_r;  //if so, print the containing row.
}

//-------------Check row--------------------
//check if there is a row contained the values in containing row
//the function receive the matrix, and the containing row

bool row_quantity(const int locate[][COLS], int out_r)
{
    bool same=false;    //boolean variable

    for(int in_r=0; in_r<ROWS; in_r++) //run over the contained row
    {                       //check if the contained row ("in_row")
        if(out_r != in_r)   //is not equal to containing row ("out_row")
        {                   //if they are not equal,
            if(check_quantity(locate, out_r, in_r)) //summon "check_quantity"
            {                                       //boolean function
                same = true;    //if the function returns "true", puts
                return true;    //"true" in "same", and then return true.
            }
            else                //if the function returns "false",
                same = false;   //puts "false" in "same", and
        }                       //keep looking for contained row.
        else            //if the rows are equal
            continue;   //continue the loop.

        if(!same)           //if "same" is false
            return false;   //return false.
    }
}

//-------------Check column--------------------
//check if there is a contained row in the matrix
//the function receive the matrix, the containing row, and the contained row

bool check_quantity(const int locate[][COLS], int out_r, int in_r)
{
    int count_out=0, count_in=0;    //variable
    bool same=false;                //boolean variable

    //run over the containing row
    for(int in_c=0; in_c<COLS; in_c++)
    {
        count_in=1;     //put "1" in "count_in"

        //run over the contained row, and check if there is
        //equal values, if so, count how many times
        for(int ind_in=in_c+1; ind_in<COLS; ind_in++)

            if(locate[in_r][in_c] == locate[in_r][ind_in])

                count_in++;

        //run over the containing column
        for(int out_c=0; out_c<COLS; out_c++ && out_r != in_r)
        {
            //check if the values are not equal to zero
            if(locate[out_r][out_c] != 0 && locate[in_r][in_c] != 0)
            {
                //check if the value of the containing row is
                //equal to the value of the contained row.
                if(locate[out_r][out_c] == locate[in_r][in_c])
                {
                    count_out=1;    //put "1" in "count_out"

                    //run over the containing row, and check if there is
                    //equal values, if so, count how many times
                    for(int ind_out=out_c+1; ind_out<COLS; ind_out++)
                    {
                        if(locate[out_r][out_c] == locate[out_r][ind_out])

                            count_out++;
                    }
                    //check if the quantity of the values in
                    //containing row are greater or equal to the quantity
                    //in contained row
                    //if so, change the boolean variable "same" to true and
                    //break the loop.
                    if(count_out >= count_in)
                    {
                        same = true;
                        break;
                    }
                }
                else
                    same=false;
            }
        }
        if(!same)       //check if "same" is false. if so, break the loop
            break;
    }
    if(same)            //check if "same" is true.
        return true;    //if so, return true to "row_quantity" function
    else                //if "same" is false
        return false;   //return false to "row_quantity" function
}








