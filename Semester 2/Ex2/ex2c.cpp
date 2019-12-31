/*
 * Linked list
 * =============================================================
 * Written by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program receives from user numbers until eof.
 * Then the program checks for each input its prime number.
 * The prime number enters to the first structure in line and the
 * left linked structures contains the user's values that divide by the
 * prime number.
 * The structures linked from the smallest to the biggest.
 * Each value exist only one time in the list.
 * Finally, the program summon a function that print the list.
 *
 * input:
 *  a. Numbers until eof.
 *
 * output:
 *  a. The linked list line by line.
 */

//------------------------------Include---------------------------------------
#include <iostream>
#include <cstdlib>

//--------------------------------Using---------------------------------------
using std::cin;
using std::cout;
using std::nothrow;
using std::endl;
using std::cerr;

//------------------------------Structure-------------------------------------
struct Node
{
   int _data ;
   struct Node *_next ;
};

struct Node2
{
   int _data ;
   struct Node *_left;
   struct Node2 *_down ;
};

//------------------------------Prototype-------------------------------------
void read_values(struct Node2 *&head);
void print_list(struct Node2 *head);
bool prime(const int value);
int prime_div(int value);
void insert_first_value(struct Node2 **pointer, int first_num, int value);
void insert_next_value(struct Node *&head, int value);
bool exist(struct Node *head, int value);
void print(struct Node2 *head);
void free_alloc(struct Node2 *head);


//--------------------------------Main----------------------------------------
int main()
{
    struct Node2 *head = NULL;

    read_values(head);

    print(head);

    free_alloc(head);

    return EXIT_SUCCESS;
}

//read_values-----------------------------------------------------------------
//Function that receive values and summon another functions to check where
//to put the values
void read_values(struct Node2 *&head)
{
    struct Node2 *temp = head;

    int value, first_num;

    cin >> value;

    while(!cin.eof())
    {
        first_num = prime_div(value);

        if(temp != NULL && first_num > temp ->_data)
        {
            temp = temp ->_down;
            continue;
        }

        if(temp == NULL && first_num != temp ->_data)
        {
            insert_first_value(&head, first_num, value);
            temp = head;
        }

        else
        {
            if(!exist(temp ->_left, value))

                insert_next_value(temp ->_left, value);

            temp = head;
        }

        cin >> value;
    }
}

//prime-----------------------------------------------------------------------
//Function that check if the value is a prime number.
bool prime(const int value)
{
    int isPrime = true;

    for(int i = 2; i <= value / 2; i++)
    {
        if(i % 2 == 0)
        {
            isPrime = false;
            break;
        }
    }

    return isPrime;
}

//prime_div-------------------------------------------------------------------
//Function that check what is the first prime number that divide the input
int prime_div(int value)
{
    for(int i = 2; i <= value / 2; i++)

        if(value % i == 0)

            if(prime(i))

                return i;

    return value;
}

//insert_first_value----------------------------------------------------------
//Function that get a pointer to head, the prime number and the input.
//The function allocate new structures for each input and prime number.
void insert_first_value(struct Node2 **pointer,
                        int first_num, int value)
{
    struct Node *temp;

    if(*pointer == NULL)
    {
        *pointer = new(nothrow) struct Node2;

        if(pointer == NULL)
        {
            cerr << "can not allocate memory";

            exit(EXIT_FAILURE);
        }
        (*pointer) ->_data = first_num;

        temp = new(nothrow) struct Node;

        if(temp == NULL)
        {
            cerr << "can not allocate memory";

            exit(EXIT_FAILURE);
        }

        temp ->_data = value;
        temp ->_next = NULL;

        (*pointer) ->_down = NULL;
        (*pointer) ->_left = NULL;

        return;
    }
}

//insert_next_value-----------------------------------------------------------
//Function that allocate a new left structure to put a new input.
void insert_next_value(struct Node *&head, int value)
{
    struct Node *temp;

    temp = new(nothrow) struct Node;

    if(temp == NULL)
    {
        cerr << "can not allocate memory";

        exit(EXIT_FAILURE);
    }

    temp ->_data = value;

    temp ->_next = head;

    head = temp;
}

//exist-----------------------------------------------------------------------
//Function that check if the numbers exist in the list
bool exist(struct Node *head, int value)
{
    while(head != NULL)
    {
        if(value != head ->_data)

            return false;

        head = head ->_next;
    }
    return true;
}

//print-----------------------------------------------------------------------
//Function that print the list
void print(struct Node2 *head)
{
	struct Node *temp;

	while(head != NULL)
	{
		cout << head ->_data << " ";

		temp = head ->_left;

		while(temp != NULL)
		{
			cout << temp ->_data;

			if(temp ->_next != NULL)

				cout << " ";

			temp = temp->_next;
		}

	    cout << endl;
	    head = head ->_down;
    }
}

//free_alloc------------------------------------------------------------------
//Function that free the allocated memory
void free_alloc(struct Node2 *head)
{
    struct Node *temp_head = head ->_left;
	struct Node2 *temp;

	while (head != NULL)
    {
        temp = head;
		temp_head = temp_head ->_next;
		delete temp;

		temp = head;
		head = head ->_down;
		delete temp;
	}
}
