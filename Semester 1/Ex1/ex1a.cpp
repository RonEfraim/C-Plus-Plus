/*
 * Differences between numbers
 * =============================================================
 * Writen by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program calculates the differences between numbers.
 * The user selects 3 numbers and the program will print the differences
 *
 * input:
 *  a. 3 numbers.
 * output:
 *  a. The differences between the numbers.
 */

//--------------Include--------------------
#include <iostream>

//---------------Using--------------------
using std::cout;
using std::endl;
using std::cin;

//----------------Main---------------------
int main()
{
    int num1, num2, num3;

    cin>>num1>>num2>>num3;

    cout<< num1-num1<<" "<< num1-num2<<" "<<num1-num3<<endl;
    cout<< num2-num1<<" "<< num2-num2<<" "<< num2-num3 <<endl;
    cout<< num3-num1<<" "<< num3-num2<< " "<< num3-num3 <<endl;

    return 0;

}
