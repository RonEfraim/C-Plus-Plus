/*
 * Variance Calculation
 * =============================================================
 * Written by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program receives from the user 7 numbers.
 * Then the program calculates the sum and the average of array.
 * In the end, the program shows the average and the variance of array.
 *
 *
 * input:
 *  a. 7 numbers.
 *
 * output:
 *  a. Print the average.
 *  b. Print the variance.
 */


//-----------Include--------------
#include <iostream>

//------------Using---------------
using std::cin;
using std::cout;

//-----------Constant--------------
const int SIZE=7;

//-------------Main----------------
int main()
{
    double arr[SIZE], average=0, sum=0, variance=0;     //variables
    int index;

    for(index=0; index<SIZE; index++)                   //a loop that receive numbers
    {                                                   //to an array and calculate
        cin>>arr[index];                                //the sum of series.

        sum+=arr[index];
    }

    average = sum / SIZE;                               //calculate the average of series.

    for(index=0; index<SIZE; index++)                   //a loop that calculates the variance.

        variance += (arr[index]-average)*(arr[index]-average) / SIZE;

    cout<<average<<" "<<variance;                       //print the average and the variance.

    return 0;
}
