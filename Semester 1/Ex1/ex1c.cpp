/*
 * Blocked Circle and Blocking Circle
 * =============================================================
 * Writen by: Ron Efraim, id = 204661425, login = ronef
 *
 * This program calculating the radius, the area and the perimeter
 * of the blocked circle and the blocking circle.
 *
 * input:
 *  a. 4 variables from the user
 * output:
 *  a. The radius, area and perimeter of eceh circle.
 */


//-------------------Include--------------------
#include <iostream>
#include <cmath>

//-------------------Using----------------------
using std::cout;
using std::cin;
using std::endl;

//-------------------Main-----------------------
int main()
{
    double x1, x2, y1, y2, //The points of the rectangle
            diameter_1, r1, a1, p1,     //variables for blocked circle
            diameter_2, r2, a2, p2;     //variables for blocking circle


    cin>>x1>>y1>>x2>>y2;


//blocked circle

    diameter_1=y1-y2;

    r1= diameter_1/2;

    a1= r1 * r1 * 3.1415;

    p1= 2 * 3.1415 * r1;

//blocking circle

    diameter_2= sqrt(((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)));

    r2= diameter_2/2;

    a2= r2 * r2 * 3.1415;

    p2= 2 * 3.1415 * r2;


//the output
    cout<<r1<<" "<<a1<<" "<<p1<<endl;
    cout<<r2<<" "<<a2<<" "<<p2<<endl;

    return 0;
}
