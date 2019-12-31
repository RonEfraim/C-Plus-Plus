/*
 * Gold Bars
 * =============================================================
 * Written by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program receives from user numbers to array.
 * The program divides gold bars equally between the goldsmiths.
 * The program tries, first of all, to assign each bar to the first goldsmith,
 * If it fails, it assigns the bar to the other goldsmith.
 * In the end, the program prints the piece of each goldsmith.
 *
 * input:
 *  a. 5 numbers, which describe the weight of the gold bars
 *
 * output:
 *  a. print the share of each goldsmith.
 */

//-------------- Include -------------------
#include <iostream>
#include <cstdlib>

//---------------- Using -------------------
using std::cin;
using std::cout;
using std::endl;

//-------------- Constant ------------------
const int N = 5;

//-------------- Prototypes ----------------
void input(int arr[]);
bool sum(const int arr[], int &sum_2);
void gold_bar(const int arr[], bool checked[],
              int temp, int &sum_g1,
              int index);
void output(const int g1[], const int g2[],
            int occupy_1, int occupy_2);

//-------------- Main ----------------------
int main()
{
	int arr[N];
	bool checked[N] = {false};  //boolean array
	int sum_g1=0;
	int index=0, sum_div=0;

	input(arr);

	if(sum(arr, sum_div))

		gold_bar(arr, checked, sum_div, sum_g1, index);

	return EXIT_SUCCESS;
}

//Input-------------------------------------
//Function that receive inputs from user
void input(int arr[])
{
	for(int index = 0; index < N; index++)

		cin>>arr[index];
}

//Input-------------------------------------
//Function that calculate the sum of array
//and then divide it by 2.
//The function receive the array and reference parameter
bool sum(const int arr[], int &sum_div)
{
	int temp_sum=0;

	for(int index = 0; index < N; index++)

		temp_sum += arr[index];

	if(temp_sum % 2 == 0)
	{
		sum_div = temp_sum / 2;
		return true;
	}

	return false;
}

//Gold_bar-------------------------------------
//The function receive the array, the boolean array, the sum of division array,
//reference parameter (for calculate the piece of the first goldsmith), and
//index to run over the arrays.
//the function checks for which cells the first goldsmith get equal piece
void gold_bar(const int arr[], bool checked[],
		int sum_div,
		int &sum_g1,
		int index)
{
	if(index == 5)
		return;

	if(sum_g1 == sum_div)           //if the piece of the first gold smith
	{                               //is equal to "sum_div"
		int g1[N], g2[N],
		occupy_1=0, occupy_2=0;

		for(int ind = 0; ind < N; ind++)
		{
			if(checked[ind] == true)
			{
				g1[occupy_1] = arr[ind];
				occupy_1++;
			}

			else
			{
				g2[occupy_2] = arr[ind];
				occupy_2++;
			}
		}

		output(g1, g2, occupy_1, occupy_2);
		return;
	}

	else if(sum_g1 < sum_div)         //if the piece of the first goldsmith
	{                                 //is smaller than "sum_div"
		if(checked[index] == false)
		{
			checked[index] = true;

			sum_g1 += arr[index];
            //recursive
			gold_bar(arr, checked, sum_div, sum_g1, index + 1);
		}
	}

	else        //if the piece of the first goldsmith
                //is larger than "sum_div"
		return;


	if(checked[index] == true)
	{
		checked[index] = false;

		sum_g1 -= arr[index];
	}
    //recursive
	gold_bar(arr, checked, sum_div, sum_g1, index + 1);
}

//Gold_bar-------------------------------------
//The function receive from "gold_bar" two array that containing the piece
//of each goldsmith, and two indexes to check how many values exists in
//array.
void output(const int g1[], const int g2[],
		int occupy_1, int occupy_2)
{
	for(int i = 0; i < occupy_1; i++)

		cout << g1[i] << " ";

	cout<<endl;

	for(int j = 0; j < occupy_2; j++)

		cout << g2[j] << " ";
}
