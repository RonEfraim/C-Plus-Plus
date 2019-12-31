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
 * input:
 *  a. 20 numbers to a matrix, 4 rows and 5 columns.
 *
 * output:
 *  a. Print the row containing all values in the matrix.
 *  b. Print the row contain the same quantity of values.
 *  c. if there is no containing row the output is "-1".
 */

//---------------Include----------------
#include <iostream>
#include <cstdlib>

//---------------Using-----------------
using std::cout;
using std::cin;
using std::endl;

//---------------Constant--------------
const int ROWS=4,
          COLS=5;

//----------------Main-----------------
int main()
{
    int locate[ROWS][COLS];         //a matrix of one dimensional arrays
    int out_r, out_c,               //variables
        in_r, in_c,
        count_out=0, count_in=0;

    bool same=true;                 //boolean variable

//-----------------Input loop---------------------
    for(int ind_r=0; ind_r<ROWS; ind_r++)

        for(int ind_c=0; ind_c<COLS; ind_c++)

        cin>>locate[ind_r][ind_c];

//PART A-check if there is a containing row-----------------------

    //run over the containing row
    for(out_r=0; out_r<ROWS; out_r++)
    {
        //run over the contained row
        for(in_r=0; in_r<ROWS; in_r++)
        {
            //run over the contained column
            for(in_c=0; in_c<COLS; in_c++)
            {
                //run over the containing column
                for(out_c=0; out_c<COLS; out_c++)
                {
                    //check if "out_r" is equal to "in_r"
                    //if so, get out from loop.
                    if(out_r != in_r)
                    {
                        //if the rows are not equal, check if the values
                        //are equal, if they are, change the boolean variable
                        //"same" to true, and then break the loop.
                        if(locate[out_r][out_c] == locate[in_r][in_c])
                        {
                            same=true;
                            break;
                        }
                        //if the values are not equal, change the boolean
                        //variable "same" to false.
                        else
                            same=false;
                    }
                }
                if(!same)   //check if "same" is false, if so, break the loop
                    break;
            }
            if(!same)   //check if "same" is false, if so, break the loop
                break;
        }
        if(same)    //check if "same" is true, if so, print the containing row
        {           //and then break the loop
            cout<<out_r<<endl;
            break;
        }
    }           //check if "same" is false, if so, print "-1"
    if(!same)   //it means there is no containing row in matrix
        cout<<"-1"<<endl;

//PART B- check if there is a row containing all values in the matrix-------

    same=true;      //change the boolean variable "same" to true

    //run over the containing row
    for(out_r=0; out_r<ROWS; out_r++)
    {
        //run over the contained row
        for(in_r=0; in_r<ROWS; in_r++)
        {
            //run over the contained column
            for(in_c=0; in_c<COLS; in_c++)
            {
                //check if "out_r" is equal to "in_r", and check if the
                //value in contained row is equal to zero.
                //if so, get out from loop.
                if(out_r != in_r && locate[in_r][in_c] != 0)
                {
                    count_in=1; //put "1" in "count_in"

                    //run over the contained row, and check if there is
                    //equal values, if so, count how many times
                    for(int temp_in=in_c + 1; temp_in<COLS; temp_in++)

                        if(locate[in_r][in_c] == locate[in_r][temp_in])

                            count_in++;
                }

                else
                    break;

                //run over the containing column
                for(out_c=0; out_c<COLS; out_c++)
                {
                    //check if the value is not equal to zero
                    if(locate[out_r][out_c] != 0 )
                    {
                        count_out=1;    //put "1" in "count_out"

                        //run over the containing row, and check if there is
                        //equal values, if so, count how many times
                        for(int temp_out=out_c + 1; temp_out<COLS; temp_out++)

                            if(locate[out_r][out_c] == locate[out_r][temp_out])

                                count_out++;

                        //check if the value of the containing row is
                        //equal to the value of the contained row.
                        if(locate[out_r][out_c] == locate[in_r][in_c])
                        {
                            //check if the quantity of the values in
                            //containing are greater or equal to the quantity
                            //in contained row
                            //if so, change the boolean variable to true and
                            //break the loop.
                            //if it's not change the boolean variable to false
                            if(count_out >= count_in)
                            {
                                same=true;
                                break;
                            }

                        }
                        else
                            same=false;
                    }
                }
                if(!same)  //check if "same" is false. if so, break the loop
                    break;
            }
            if(!same)   //check if "same" is false. if so, break the loop
                break;
        }
        if(same)   //check if "same" is true. if so, print the containing row
        {          //and then break the loop
            cout<<out_r;
            break;
        }
    }
    if(!same)           //check if "same" is false, if so, print "-1"
        cout<< "-1";    //it means there is no containing row in matrix

    return EXIT_SUCCESS;

}
