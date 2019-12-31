/*
 * Pointer to the next even or odd in the list
 * =============================================================
 * Written by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program receives from user numbers until eof.
 * Then the program checks for each cell in the list if it is odd or even.
 * The program connects with a pointer between the evens
 * and the same action for the odd.
 * Finally, the program summon a function that print the list.
 *
 * input:
 *  a. Numbers until eof.
 *
 * output:
 *  a. The first node in list and then next odd or even.
 */


//------------------------------Include---------------------------------------
#include <iostream>
#include <cstdlib>
#include <new>

//--------------------------------Using--------------------------------------
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::nothrow;

//------------------------------Struct----------------------------------------
struct Node
{
    int _data;
    struct Node *_next,
                *_next_oe;
};

//------------------------------Prototype-------------------------------------
void insert_values(struct Node *&head);
void set_next_oe(struct Node *head);
void print(struct Node *head);
void free_alloc(struct Node *head);

//--------------------------------Main----------------------------------------
int main()
{
    struct Node *head = NULL;

    insert_values(head);

    set_next_oe(head);

    free_alloc(head);

    return EXIT_SUCCESS;
}

//insert_values---------------------------------------------------------------
//Function that allocate structure for each input number.
//The function get reference parameter to the head of list.
void insert_values(struct Node *&head)
{
    struct Node *temp;

    int num;

    cin >> num;

    while(!cin.eof())
    {
        temp = new(nothrow) struct Node;

        if(temp == NULL)
        {
            cout << "can not allocate memory \n";
            exit(EXIT_FAILURE);
        }

        temp ->_data = num;

        temp ->_next = head;

        temp ->_next_oe = NULL;

        head = temp;

        cin >> num;
    }
}

//set_next_oe-----------------------------------------------------------------
//Function that connect between the even numbers, and the odd numbers
void set_next_oe(struct Node *head)
{
	struct Node *temp,
                *even = NULL,
                *odd = NULL;

	temp = head;

	while(temp != NULL)
	{
	    if(temp ->_data % 2 != 0)
        {
            if(odd == NULL)

                odd = temp;

            else
            {
                odd ->_next_oe = temp;
                odd = temp;
            }

        }

        else
        {
            if(even ==  NULL)

                even = temp;

            else
            {
                even ->_next_oe = temp;
                even = temp;
            }
        }

		temp = temp ->_next;
	}

    print(head);

}

//print-----------------------------------------------------------------------
//Function that print the list after linking items
void print(struct Node *head)
{
    while(head != NULL)
	{
		cout << head ->_data << " " ;

		if(head ->_next_oe == NULL)

            cout << "- " ;
		else

			cout << head ->_next_oe ->_data << " " ;

		head = head ->_next;
	}

	cout << endl;
}

//free_alloc------------------------------------------------------------------
//Function that free the allocated memory
void free_alloc(struct Node *head)
{
    struct Node *temp;

    while(head != NULL)
    {
        temp = head;
        head = head -> _next;
        delete temp;
    }
}
