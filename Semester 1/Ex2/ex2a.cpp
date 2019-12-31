/*
 * Count even, odd, positive and negative numbers
 * =============================================================
 * Writen by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program asks the user 4 numbers, then the program checks which
 * numbers are even, odd, positive, negative or zero.
 *
 *
 * input:
 *  a. 4 numbers.
 * output:
 *  a. Print quantity of even and odd numbers.
 *  b. Print quantity of positive, zero and negative numbers.
 */


//------------------Include----------------------
#include <iostream>

//------------------Using----------------------
using std::cout;
using std::cin;
using std::endl;

//------------------Main----------------------
int main()
{
    int num1, num2, num3, num4, even=0, odd=0,
        positive=0, negative=0, zero=0;         //Six variables.

    cin>>num1>>num2>>num3>>num4;    //Input 4 numbers of user.

//------------------Even or Odd-----------------------

    if(num1%2==0)       //The program checks if the input variable are even or odd.
        even++;         //If it's even the program will count it.
        else            //If it's odd the program will count it.
         odd++;

    if(num2%2==0)
         even++;
        else
         odd++;

    if(num3%2==0)
        even++;
        else
         odd++;

    if(num4%2==0)
        even++;
        else
         odd++;


    cout<<even<<" "<<odd<<endl;        //Print quantity of even and odd numbers.

//---------------Positive, Negative or zero------------------------------

    if(num1>0)              //The program checks if the inputs variables are positive, negative or zero.
        positive++;         //If it's positive the program will count it.
        else if(num1<0)
        negative++;         //If it's negative the program will count it.
        else
        zero++;             //If it's zero the program will count it.

    if(num2>0)
        positive++;
        else if(num2<0)
        negative++;
        else
        zero++;

    if(num3>0)
        positive++;
        else if(num3<0)
        negative++;
        else
        zero++;

    if(num4>0)
        positive++;
        else if(num4<0)
        negative++;
        else
        zero++;


    cout<<positive<<" "<<zero<<" "<<negative;     //Print quantity of positive, zero and negative numbers.

    return 0;
}
