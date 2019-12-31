/*
 * Tree to List
 * =============================================================
 * Written by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program receives from user numbers until eof.
 * Then the program insert values into the tree.
 * Then the program copy all the leaves to linked list.
 * The program start to copy from the leaf that contain the
 * lowest value.
 * Finally, the program summon a function that print the list.
 *
 * input:
 *  a. Numbers until eof.
 *
 * output:
 *  a. The linked list.
 */

//------------------------------Include---------------------------------------
#include <iostream>
#include <cstdlib>
#include <iomanip>

//-------------------------------Using----------------------------------------
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::nothrow;

//------------------------------Structure-------------------------------------
struct Tree_node
{
   int _data;
   struct Tree_node * _left, * _right ;
};

struct List_node
{
   int _data ;
   struct List_node * _next;
};


//------------------------------Prototype-------------------------------------
void build_tree(Tree_node *&root);
void insert_into_tree(Tree_node *&root, Tree_node *new_node);
void tree_to_list(const Tree_node *root, List_node *&head,
                                         List_node *&curr_leaf);
void print(const List_node *head);
void free_alloc_list(struct List_node *head);
void free_alloc_tree(struct Tree_node *root);


//---------------------------------Main----------------------------------------
int main()
{
    struct Tree_node *root = NULL;

    struct List_node *head = NULL,
                     *curr_leaf = NULL;

    build_tree(root);

    tree_to_list(root, head, curr_leaf);

    print(head);

    free_alloc_list(head);

    free_alloc_tree(root);

    return EXIT_SUCCESS;
}

//build_tree------------------------------------------------------------------
//Function that receive a pointer to tree and summon another functions
//to insert values to the tree
void build_tree(Tree_node *&root)
{
    struct Tree_node *new_node;

    int value;

    cin >> value;

    while(cin.eof())
    {
        new_node = new (nothrow) struct Tree_node;

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
void insert_into_tree(Tree_node *&root,
                      Tree_node *new_node)
{
    if (root == NULL)

        root = new_node;

    else if (root ->_data >= new_node ->_data)

        insert_into_tree(root ->_left, new_node);

    else

        insert_into_tree(root ->_right, new_node);
}

//tree_to_list----------------------------------------------------------------
//Recursive function that copy all the values from tree to list
void tree_to_list(const Tree_node *root,
                  List_node *&head,
                  List_node *&curr_leaf)
{
    List_node *temp = NULL;

    if (root == NULL)

        return;

    else
    {
    	tree_to_list(root ->_left, head, curr_leaf);

    	temp = new (nothrow) List_node;

    	if(temp == NULL)
    	{
			cerr << "Cannot allocate memory\n";
			exit(EXIT_FAILURE);
    	}

    	temp ->_data = root ->_data;

    	temp ->_next = NULL;

    	if(head != NULL)
    	{
    		curr_leaf ->_next = temp;
    		curr_leaf = temp;
    	}

    	else

    		curr_leaf = head = temp;

    	tree_to_list(root ->_right, head, curr_leaf);
    }
}

//print-----------------------------------------------------------------------
//Function that print the list
void print(const List_node *head)
{
    while(head != NULL)
    {
        cout << head ->_data << " ";

        head = head ->_next;
    }
}

//free_alloc_list------------------------------------------------------------------
//Function that free the allocated memory
void free_alloc_list(struct List_node *head)
{
    struct List_node *temp;

    while(head != NULL)
    {
        temp = head;
        head = head -> _next;
        delete temp;
    }
}

//free_alloc__tree------------------------------------------------------------------
//Function that free the allocated memory
void free_alloc_tree(struct Tree_node *root)
{
    if (root != NULL)
    {
        free_alloc_tree(root ->_left);
        free_alloc_tree(root ->_right);
        delete root;
    }
}

