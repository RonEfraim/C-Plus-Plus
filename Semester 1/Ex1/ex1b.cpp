/*
 * Calculate area and perimeter of  triangle
 * =============================================================
 * Writen by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program receives from user 3 numbers and then
 * calculates the area and the perimeter of triangle.
 *
 * input:
 *  a. 3 numbers.
 * output:
 *  a. The area and perimeter of triangle.
 */

//----------------Include----------------
#include <iostream>
#include <cmath>

//-----------------Using-----------------
using std::cout;
using std::cin;
using std::endl;

//----------------Main-------------------
int main()
{
    double a, b, c, s,
            perimeter, area;

    cin>>a>>b>>c;

    perimeter=a+b+c;    //calculates the perimeter.

    s=perimeter/2;

    area=sqrt(s*(s-a)*(s-b)*(s-c));  //calculates the area with Heron formula.

    cout<<area<<endl;  //print the triangle area.
    cout<<perimeter<<endl;  //print the triangle perimeter.

    return 0;
}

