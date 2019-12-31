/*
 * Calculate average and count negative and positive numbers
 * =============================================================
 * Written by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program receive numbers from the user until he press 0.
 * Then the program checks the average of numbers and count negative and positive numbers.
 *
 *
 * input:
 *  a. Numbers until the user press 0.
 * output:
 *  a. Print quantity of inputs.
 *  b. Print average of the numbers.
 *  c. Print quantity of positive and negative numbers.
 */


//------------Include-----------
#include <iostream>

//------------Using-----------
using std::cin;
using std::cout;

//------------Main-----------
int main()
{
    int num1,
        quantity=0, positive=0, negative=0,
        sum=0, average=0;

    do                              //the loop checks if the input is positive or negative or zero
    {                               //then calculate the average of inputs
        cin>>num1;                  //after that the loop checks the condition

        if(num1!=0)
            quantity++;             //if the input is equal to zero quantity increase by 1

        if(num1>0)
            positive++;             //if the input is positive, increase by 1

        else if(num1<0)
            negative++;             // if the input is negative, increase by 1

        sum+=num1;                  //sum the inputs

        average=sum/quantity;       //calculate the average of inputs
    }

    while (num1!=0);                //if the condition passed successfully,
    {                               //output quantity, average, positive, negative
        cout<<quantity<<" "<<average<<" "<<positive<<" "<<negative;
    }


    return 0;
}
