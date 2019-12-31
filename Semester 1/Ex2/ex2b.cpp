/*
 * The most value from 3 numbers.
 * =============================================================
 * Writen by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program asks the user to enter 3 numbers.
 * Then the program calculates the numbers to get the most valuable result.
 *
 * input:
 *  a. 3 numbers.
 * output:
 *  a. The most valuable result.
 */

//---------------Include-------------------
#include <iostream>

//---------------Using-------------------
using std::cout;
using std::endl;
using std::cin;

//---------------Main-------------------
int main()
{
    int num1, num2, num3,
        sum1, sum2, sum3, sum4, sum5, sum6;

    cin>>num1>>num2>>num3;

    //Option A
//---------------Equal Numbers--------------

    if(num1==0 && num2==0 && num3==0)           //check if the inputs are equal to zero
    {
        cout<<num1<<"*"<<num2<<"+"<<num3<<"="<<num1*num2+num3<<endl;

        return 0;

    }

    else if(num1==num2 && num1==num3)           //check if the inputs are equal to each other
    {
        cout<<"("<<num1<<"+"<<num2<<")"<<"*"<<num3<<"="<<(num1+num2)*num3<<endl;

        return 0;
    }

    //Option B- Different numbers

//-----------------Possible results---------------
    sum1= num1*num2+num3;
    sum2= num2*num3+num1;
    sum3= num1*num3+num2;
    sum4= (num1+num2)*num3;
    sum5= (num2+num3)*num1;
    sum6= (num1+num3)*num2;


    if(sum1>sum2 && sum1>sum3 && sum1>sum4 && sum1>sum5 && sum1>sum6)       //If sum1 is maximum result

        cout<<num1<<"*"<<num2<<"+"<<num3<<"="<<sum1<<endl;

    else if(sum2>sum1 && sum2>sum3 && sum2>sum4 && sum2>sum5 && sum2>sum6)  //If sum2 is maximum result

        cout<<num2<<"*"<<num3<<"+"<<num1<<"="<<sum2<<endl;

    else if(sum3>sum1 && sum3>sum2 && sum3>sum4 && sum3>sum5 && sum3>sum6)  //If sum3 is maximum result

        cout<<num1<<"*"<<num3<<"+"<<num2<<"="<<sum3<<endl;

    else if(sum4>sum1 && sum4>sum2 && sum4>sum3 && sum4>sum5 && sum4>sum6)  //If sum4 is maximum result

        cout<<"("<<num1<<"+"<<num2<<")"<<"*"<<num3<<"="<<sum4<<endl;

    else if(sum5>sum1 && sum5>sum2 && sum5>sum3 && sum5>sum4 && sum5>sum6)  //If sum5 is maximum result

        cout<<"("<<num2<<"+"<<num3<<")"<<"*"<<num1<<"="<<sum5<<endl;

    else                                                                    //If sum6 is maximum result

        cout<<"("<<num1<<"+"<<num3<<")"<<"*"<<num2<<"="<<sum6<<endl;



    return 0;
}
