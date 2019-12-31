//-------------Include-----------------
#include <iostream>
#include <cstdlib>

//-------------Using-----------------
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

//-------------Constant & enum-----------------
const int N = 10;

enum select_t {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE,
               TEN, ELEVEN, TWELVE, THIRTEEN};

//-------------Prototypes-----------------
int menu(int arr[N]);
int manager(int arr[N], select_t input);
void input_func(int arr[N], int ind);
int search_value(const int arr[N], int ind, int value);
void bubble_sort_a(int arr[N], int ind);
void bubble_sort_b(int arr[N], int ind, int N);
bool is_sort(int arr[N], int ind);
bool binary_search(int arr[N], int value, int lo, int hi);
int f_counter(const int arr[N], int ind, int value, int &count);
void print_up(const int arr[N], int ind, int c);
void print_down(int arr[N], int last_ind);
bool palindrome(const int arr[N], int ind, int last_ind);
int sum(const int arr[N], int ind, int counter, int temp_sum);
bool is_prime(int value, int div);
void prime(int arr[N], int ind);
void one_value(int arr[N], int temp_arr[N], int ind, int ind_2,
               int counter);


//-------------Main-----------------
int main()
{
    int arr[N];

    menu(arr);

    return EXIT_SUCCESS;
}

//Menu-----------------------------------------
//recursive function to receive user's choice
int menu(int arr[N])
{
    int input;

	cin >> input;

	if(input >= 1 && input <= 13)

		switch(input)
		{
				case ONE : manager(arr, ONE);
						    break;

				case TWO : manager(arr, TWO);
						    break;

				case THREE : manager(arr, THREE);
							  break;

				case FOUR : manager(arr, FOUR);
							 break;

				case FIVE : manager(arr, FIVE);
							 break;

				case SIX : manager(arr, SIX);
						    break;

				case SEVEN : manager(arr, SEVEN);
							  break;

				case EIGHT : manager(arr, EIGHT);
							  break;

				case NINE : manager(arr, NINE);
							 break;

				case TEN : manager(arr, TEN);
						    break;

				case ELEVEN : manager(arr, ELEVEN);
							   break;

				case TWELVE : manager(arr, TWELVE);
							   break;

				case THIRTEEN :break;

				default : menu(arr);
		}
	else
		menu(arr);

    return 0;
}

//Manager-----------------------------------------
//recursive function that call to other functions
//it's depends the user choice
int manager(int arr[N], select_t input)
{
    int ind = 0, value=0,               //variables
        lo = 0, hi = N - 1,
        count = 0, result = 0,
        counter_ind = 0, last_ind = N-1,
        counter=0, temp_sum=0,
        ind_2 = 0;

    int temp_arr[N];        //temporary array

        switch(input)
        {
            case ONE: input_func(arr, ind);
                      menu(arr);
                      break;

            case TWO: cin >> value;
                      cout << search_value(arr, ind, value);
                      menu(arr);
                      break;

            case THREE: bubble_sort_a(arr, ind);
                        menu(arr);
                        break;

            case FOUR: if(is_sort(arr, ind))
                       {
                          cin >> value;
                          cout << binary_search(arr, value, lo, hi);
                       }
                       else
                          cerr << "ERROR\n";
                       menu(arr);
                       break;

            case FIVE: cin >> value;
                       result = f_counter(arr, ind, value, count);
                       cout << result;
                       menu(arr);
                       break;

            case SIX: print_up(arr, ind, counter_ind);
                      menu(arr);
                      break;

            case SEVEN: print_down(arr, last_ind);
                        break;

            case EIGHT: cout << is_sort(arr, ind);
                        menu(arr);
                        break;

            case NINE: cout << palindrome(arr, ind, last_ind);
                       break;

            case TEN: cout << sum(arr, ind, counter, temp_sum);
                      menu(arr);
                      break;

            case ELEVEN: one_value(arr, temp_arr, ind, ind_2,
                                           counter_ind);
                         menu(arr);
                         break;

            case TWELVE: prime(arr, ind);
                         menu(arr);
                         break;

            case THIRTEEN: break;

            default: menu(arr);

        }

    return 0;
}

//input function-----------------------------------------
//recursive function that receive numbers from user
void input_func(int arr[N], int ind)
{
    if(ind == N)

        return;

    cin>>arr[ind];

    input_func(arr, ++ind);
}

//search value-----------------------------------------
//recursive function that check if the input exist in array
int search_value(const int arr[N], int ind, int value)
{
    if(ind == N)

        return 0;

    if(value == arr[ind])

        return 1;

    search_value(arr, ++ind, value);
}

//bubble sort-----------------------------------------
//recursive functions that sort the array using the bubble sort
void bubble_sort_a(int arr[N], int ind)
{
    if(ind == N)

        return;

    bubble_sort_b(arr, 0, N-1);

    bubble_sort_a(arr, ++ind);
}

void bubble_sort_b(int arr[N], int ind, int N)
{
    int temp=0;

    if(ind == N)

        return;

    if(arr[ind] >= arr[ind + 1])
    {
        temp = arr[ind];
        arr[ind] = arr[ind + 1];
        arr[ind + 1] = temp;
    }

    bubble_sort_b(arr, ++ind, N);
}


//is sort-----------------------------------------
//recursive function that check if the array is sorted down
bool is_sort(int arr[N], int ind)
{
    if(ind == N)

        return true;

    if(arr[ind] > arr[ind + 1])

        return false;

    is_sort(arr, ++ind);
}

//binary search-----------------------------------------
//recursive function that check if the value exist in array
//the function will work only if the array is sorted down
bool binary_search(int arr[N], int value, int lo, int hi)
{
    if(lo > hi)

        return false;

    int mid = (lo + hi) / 2;

    if(value == arr[mid])

        return true;

    if(arr[mid] > value)

        binary_search(arr, value, lo, mid - 1);

    binary_search(arr, value, mid + 1, hi);
}

//counter-----------------------------------------
//recursive function that check how many times the value exist in array
int f_counter(const int arr[N], int ind, int value, int &count)
{
    if(ind == N)

        return count;

    if(arr[ind] == value)

        count++;

    return f_counter(arr, ++ind, value, count);

}

//print up-----------------------------------------
//recursive function that print that array from beginning to end
void print_up(const int arr[N], int ind, int counter_ind)
{
    if(ind == N)

        return;

    cout << arr[ind];

    print_up(arr, ++ind, counter_ind);

}

//print up-----------------------------------------
//recursive function that print that array from end to beginning
void print_down(int arr[N], int last_ind)
{
	if (last_ind == -1)
    {
        cout << endl;
        return;
    }

    cout << arr[last_ind] << " ";

    print_down(arr, --last_ind);
}

//palindrome-----------------------------------------
//recursive function that check if the array is palindrome
//palindrome - symmetrical
bool palindrome(const int arr[N], int ind, int last_ind)
{
    if(arr[0] != arr[N-1])

        return false;

    if(arr[ind] == arr[last_ind] && ind < N/2)
    {
        palindrome(arr, ++ind, --last_ind);

        return true;
    }
}

//sum-------------------------------------------------
//recursive function to check how many values in the array are the sum
//of all of the values before of them
int sum(const int arr[N], int ind, int counter, int temp_sum)
{
    if(ind == N)

        return counter;

    if(temp_sum == arr[ind])

        counter++;

    temp_sum += arr[ind];

    sum(arr, ++ind, counter, temp_sum);
}

//one value------------------------------------------------
//recursive function that check if the value exist one time in array
void one_value(int arr[N], int temp_arr[N], int ind, int ind_2,
              int counter_ind)
{
	if(ind == N-1 && ind_2 == N-2)
	{
		if(arr[ind] != arr[ind_2])
		{
			temp_arr[counter_ind] = arr[ind];
			print_up(temp_arr, 0, counter_ind);
		}

	}
	else if(ind_2 == N-1)
	{
		if(arr[ind] == arr[ind_2])
		{
			one_value(arr, temp_arr, ++ind, 0, counter_ind);
		}
		else
		{
			temp_arr[counter_ind] = arr[ind];
			counter_ind++;
			one_value(arr, temp_arr, ++ind, 0, counter_ind);
		}
	}

	else
		if(ind != ind_2)
		{
			if(arr[ind] == arr[ind_2])
			{
				one_value(arr, temp_arr, ++ind, 0, counter_ind);
			}
			else
				one_value(arr, temp_arr, ind, ++ind_2, counter_ind);
		}
		else
			one_value(arr, temp_arr, ind, ++ind_2, counter_ind);
}

//prime----------------------------------------------
//recursive function that check if array contain primes number
bool is_prime(int value, int div)
{
    if (div*div > value)

        return true;

    if (value % div == 0)

        return false;

    return is_prime (value, ++div);
}

void prime(int arr[N], int ind)
{
	if (ind == N)

		return;

	if (is_prime (arr[ind], 2))

		cout<<arr[ind]<<" ";

	prime(arr, ++ind);
}

