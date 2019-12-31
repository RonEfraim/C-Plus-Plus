/*
 * Guess a number
 * =============================================================
 * Written by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program will receive from the user a number as ranges.
 * then randomize a number between 0 to this input, ask the user to guess the number.
 * The user input a guess and the program will tell the user if his
 * guess is bigger or smaller than the randomized number, the user repeat the process
 * until the numbers match.
 * When the user guessed correctly, the program will print the number of times it
 * took him to guess the number and how many times it would take to a rational but
 * an unlucky player.
 * Near the end the program also gives the user a grade based on his result.
 * At the end the program ask the user if he wants to play again.
 *
 *
 * Input:
 *  a. Receive a number to build a range.
 *  b. Receive a guessing numbers.
 *  c. Receive a number to play or not to play another game.
 *
 * Output:
 *  a. Print if the guesses are too big or too small.
 *  b. Print quantity of user and unlucky user guesses.
 *  c. Print grade.
 *  d. Ask the user if he wants to play again.
 */



//----------------Include---------------
#include <iostream>
#include <cstdlib>

//----------------Using---------------
using std::cin;
using std::cout;
using std::endl;

//----------------Main---------------
int main()
{
    unsigned int x, num, guess,                                 //Natural variables
                user_counter=0, unlucky_counter=0, unlucky=0,
                temp, grade=0, again=1;


    while(again==1)                        //main loop, as long as, again=1, the program run
    {
        cin>>x;                            //input a range for guessing

        srand(1);                          //turn the machine on

        num=rand() % x;                    //program pick a number, and saves it to num variable

        user_counter=0;                    //counter of user guesses

        unlucky_counter=1;                 //counter of rational unlucky user

        cin>>guess;                        //user guesses input

        user_counter++;
//------------------Guessing loop---------------
        while(guess!=num)
        {
            if(guess<num)                  //if the user guess is smaller
                cout<<"too small"<<endl;

            else                           //if the user guess is bigger
                cout<<"too big"<<endl;

            cin>>guess;                    //another guess input

            user_counter++;                //counter of user guesses increase by 1

        }
//------------------Unlucky player loop---------------
        if(x % 2 == 0)						//if range is even
            unlucky = x / 2;				//put half of range in rational

        else								//else (range is odd)
            unlucky = (x / 2) + 1;

        if(unlucky % 2 == 0)				//if rational is even
           temp = unlucky / 2;

        else								//else (rational is odd)
            temp = (unlucky / 2) + 1;

        while(unlucky != num)				//while rational is not equals to num
        {
            unlucky_counter++;				//counter of rational unlucky user increase by 1

            if(unlucky > num)				//if rational is bigger than num,
                unlucky -= temp;			//subtract temp from rational

            else if(unlucky < num)			//if rational is smaller than num,
                unlucky += temp;			//add temp to rational

            if(temp % 2 == 0)				// if temp is even,
                temp /= 2;

            else							// else (temp is odd)
                temp = (temp / 2) + 1;
        }
//------------------Grade and Outputs---------------

        grade = ((double)unlucky_counter/user_counter)*100;

        cout<<user_counter<<" "<<unlucky_counter<<endl;         //output the quantity of guessing

        if(grade >= 100)                    //if grade is bigger than 100

            cout<<"100"<<endl;

        else                                //if grade is not bigger than 100
            cout<<grade<<endl;


        cout<<"again? 1:yes"<<endl;         //if the user wants another game

        cin>>again;


    }

    return EXIT_SUCCESS;
}
