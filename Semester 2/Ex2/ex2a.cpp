/*
 * Remove even numbers in a linked list
 * =============================================================
 * Written by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program receives from user numbers until eof.
 * Then the program checks for each structure in the list if
 * it is odd or even.
 * The program removes the even numbers from the list
 * Finally, the program summon a function that print the list.
 *
 * input:
 *  a. Numbers until eof.
 *
 * output:
 *  a. The linked list without the even numbers.
 */


//------------------------------Include---------------------------------------
#include <iostream>
#include <cstdlib>
#include <new>
#include <fstream>

//--------------------------------Using---------------------------------------
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::nothrow;

//--------------------------------Struct--------------------------------------
struct Node
{
    int _data;
    struct Node *_next;
};

//------------------------------Prototype-------------------------------------
void sum(const struct Node *index);
void delete_even(struct Node *&head);
void insert_values();
void free_alloc(struct Node *head);

//---------------------------------Main---------------------------------------
int main()
{
    insert_values();

    return EXIT_SUCCESS;
}

//insert_values---------------------------------------------------------------
//Function that allocate structure for each input number.
void insert_values()
{
    struct Node *head = NULL,
                *temp;

    int num;

    cin >> num;

    //while(!cin.eof())
    while(num != 0)
    {
        temp = new(nothrow) struct Node;

        if(temp == NULL)
        {
            cout << "can not allocate memory \n";
            exit(EXIT_FAILURE);
        }

        temp -> _data = num;
        temp -> _next = head;
        head = temp;

        cin>>num;
    }

    sum(head);

    delete_even(head);

    sum(head);

    free_alloc(head);

}

//sum-------------------------------------------------------------------------
//Function that calculate sum of linked list and then print the sum
void sum(const struct Node *index)
{
    int sum = 0;

    while(index != NULL)
    {
        sum += index -> _data;
        index = index -> _next;
    }

    cout << sum << endl;
}

//delete_even-----------------------------------------------------------------
//function that delete even numbers from linked list
void delete_even(struct Node *&head)
{
    struct Node *front,
                *rear,
                *temp;

    if(head == NULL)

        return;

    if(head ->_data % 2 == 0)
    {
        temp = head;
        head = head -> _next;
        delete temp;
    }

    rear = head;
    front = head -> _next;

    while(front != NULL)
    {
        if(front -> _data % 2 == 0)
        {
            rear -> _next = front -> _next;
            delete front;
            front = rear -> _next;
        }

        else
        {
            rear = front;
            front = front -> _next;
        }

    }
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
