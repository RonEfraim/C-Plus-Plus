/*
 * Display the minimum and leaves
 * =============================================================
 * Written by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program receives from user numbers until number 0.
 * Then the program insert values into the tree.
 * Then the program search the lowest value in the tree
 * and print it.
 *
 * input:
 *  a. Numbers until 0.
 *
 * output:
 *  a. The lowest value in the tree.
 */

//------------------------------Include---------------------------------------
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <iomanip>

//-------------------------------Using----------------------------------------
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::nothrow;

//------------------------------Structure-------------------------------------
struct Node
{
    int _data;
    struct Node *_left,
                *_right ;
};

//------------------------------Prototype-------------------------------------
void build_tree(struct Node *&root);
void insert_into_tree(struct Node *&root, struct Node *new_node);
int find_min(const struct Node *root);
void print(const struct Node *root);
void free_alloc(struct Node *root);

//---------------------------------Main----------------------------------------
int main()
{
    struct Node *root = NULL;

    build_tree(root);

    cout << find_min(root) << endl;

    print(root);

    free_alloc(root);

    return EXIT_SUCCESS;
}

//build_tree------------------------------------------------------------------
//Function that receive a pointer to tree and summon another functions
//to insert values to the tree
void build_tree(struct Node *&root)
{
    struct Node *new_node;

    int value;

    cin >> value;

    if(value == 0)

        exit(EXIT_FAILURE);

    while (value != 0)
    {
        new_node = new (nothrow) struct Node;

        if (new_node == NULL)
        {
            cerr << "Cannot allocate memory\n";
            exit(EXIT_FAILURE);
        }

        new_node ->_data = value;
        new_node ->_left = new_node ->_right = NULL;
        insert_into_tree(root, new_node);

        cin >> value;
    }
}

//insert_into_tree------------------------------------------------------------
//Function that insert values to the tree, leaf by leaf
void insert_into_tree(struct Node *&root, struct Node *new_node)
{
    if (root == NULL)

        root = new_node;

    else if (root ->_data >= new_node ->_data)

        insert_into_tree(root ->_left, new_node);

    else

        insert_into_tree(root ->_right, new_node);
}
//find_min--------------------------------------------------------------------
//Function to find the lowest value in the tree
int find_min(const struct Node *root)
{
    int min_value;

    if(root ->_left == NULL)
    {
        min_value = root ->_data;

        return min_value;
    }

    else

        find_min(root ->_left);
}


//print-----------------------------------------------------------------------
//function that print the tree
void print(const struct Node *root)
{
    if (root != NULL)
    {
        print(root ->_left);

        if(root ->_left == NULL && root ->_right == NULL)

            cout << root ->_data << " ";

        print(root ->_right);
    }
}
//free_alloc------------------------------------------------------------------
//Function that free the allocated memory
void free_alloc(struct Node *root)
{
    if (root != NULL)
    {
        free_alloc(root ->_left);
        free_alloc(root ->_right);
        delete root;
    }
}
