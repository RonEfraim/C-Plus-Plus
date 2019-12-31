/*
 * Calculate the greatest common divisor
 * =============================================================
 * Written by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program receive from the user pairs of numbers until he press 0.
 * The program then calculate the greatest common divisor for a pair of numbers each time.
 *
 *
 * input:
 *  a. Pairs of numbers.
 * output:
 *  a. Print the greatest common divisor for a pair of numbers.
 */


//--------------Include------------
#include <iostream>

//--------------Using------------
using std::cin;
using std::cout;
using std::endl;

//---------------Main------------
int main()
{
    unsigned int num1, num2,                    //Natural variables
                div=0, rest_div=0, temp=0;


    while(num1!=0 || num2!=0)                   //main loop, as long as, the inputs are not 0, the program run
    {
        cin>>num1;                              //input first number

        if(num1==0)                             //if the first input is equal to 0, stop the program
            break;

        cin>>num2;                              //input second number

        if(num2==0)                             //if the second input is equal to 0, stop the program
            break;

        if(num2>num1)                           //if the second input bigger than the first input,
        {                                       //switch values between first and second inputs
            temp=num1;
            num1=num2;
            num2=temp;
        }

        if(num1%num2!=0)                        //if the inputs are not divide,
        {                                       //put the rest of divide in variable rest_div
            rest_div=num1%num2;                 //put second input in variable div

            div=num2;

            while(div%rest_div!=0)              //as long as div and rest_div are not divide
            {                                   //put the rest of divide in a temporary variable
                temp=div%rest_div;              //then switch values between temp and rest_div
                div=rest_div;
                rest_div=temp;
            }

            if(div%rest_div==0)                 //if div and rest_div are divide
                cout<<rest_div<<endl;
        }
        else                                    //if the inputs are divide
            cout<<num2<<endl;
    }

    return 0;
}
