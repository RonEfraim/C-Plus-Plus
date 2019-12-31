/*
 * Calender
 * =============================================================
 * Writen by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program asks the user a day, a month and a year in numbers.
 * Then the program switch the numbers to words.
 *
 *
 * input:
 *  a. A day, a month and a year.
 * output:
 *  a. Print the date in words.
 */

//---------------Include-------------------
#include <iostream>

//---------------Using-------------------
using std::cout;
using std::cin;
using std::endl;

//---------------Main-------------------
int main()
{
    int day=1, month=1, year=1;     //3 Variables

    cin>>day>>month>>year;      //Input a day, a month and a year.

    if((day>=1 && day<=31) && (month>=1 && month<=12) && year<=3000)
    {

    //Days
//-------------------------------------------------------------------------------------------------
    //31 Days in month
//-------------------------------------------------------------------------------------------------

        if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
        {
            if(day==1 || day==21 || day==31)    //for days 1,21,31 add "st"
                cout<<day<<"st";
            else if(day==2 || day==22)          //for days 2,22 add "nd"
                cout<<day<<"nd";
            else if(day==3 || day==23)          //for days 3,23 add "rd"
                cout<<day<<"rd";
            else                                //for other days add "th"
                cout<<day<<"th";
        }



    //30 Days in month
//--------------------------------------------------------------------------------------------------

        else if(month==4 || month==6 || month==9 || month==11)
        {
            if(day==1 || day==21)               //for days 1,21,31 add "st"
                cout<<day<<"st";
            else if(day==2 || day==22)          //for days 2,22 add "nd"
                cout<<day<<"nd";
            else if(day==3 || day==23)          //for days 3,23 add "rd"
                cout<<day<<"rd";
            else                                //for other days add "th"
                cout<<day<<"th";
        }



    //29-28 Days in month- leap year
//---------------------------------------------------------------------------------------------------

        else if(month == 2 && year % 4 == 0 && year % 100 != 0 || year % 400 == 0
                && day <= 29 || month == 2 && day <= 28)
        {
            if(day==1 || day==21)				//for days 1,21,31 add "st"
                cout<<day<<"st";
            else if(day==2 || day==22)			//for days 2,22 add "nd"
                cout<<day<<"nd";
            else if(day==3 || day==23)			//for days 3,23 add "rd"
                cout<<day<<"rd";
            else								//for other days add "th"
                cout<<day<<"th";
        }

        else
            return 0;


    //Month
//-----------------------------------------------------------------------------------------------------------

        switch(month)                           //check which month appropriate to the input
        {
            case 1: cout<<" "<<"January";       //if 1- January
                    break;
            case 2: cout<<" "<<"February";      //if 2- February
                    break;
            case 3: cout<<" "<<"March";         //if 3- March
                    break;
            case 4: cout<<" "<<"April";         //if 4- April
                    break;
            case 5: cout<<" "<<"May";           //if 5- May
                    break;
            case 6: cout<<" "<<"June";          //if 6- June
                    break;
            case 7: cout<<" "<<"July";          //if 7- July
                    break;
            case 8: cout<<" "<<"August";        //if 8- August
                    break;
            case 9: cout<<" "<<"September";     //if 9- September
                    break;
            case 10: cout<<" "<<"October";      //if 10- October
                    break;
            case 11: cout<<" "<<"November";     //if 11- November
                    break;
            case 12: cout<<" "<<"December";     //if 12- December
                    break;
    }


    //Year
//-----------------------------------------------------------------------------------------------------------

        cout<<" "<<year;

    return 0;
    }
}
