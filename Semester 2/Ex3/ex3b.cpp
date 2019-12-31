/*
 * Displays the shallowest leaf in the tree
 * =============================================================
 * Written by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program receives from user numbers until eof.
 * Then the program insert values into the tree.
 * Then the program search the shallowest leaf in the tree
 * and print it.
 *
 * input:
 *  a. Numbers until eof.
 *
 * output:
 *  a. The shallowest leaf in the tree.
 */

//------------------------------Include---------------------------------------
#include <iostream>
#include <cstdlib>
#include <climits>
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
const struct Node *min_depth_leaf(const Node *root);
const Node *find_min_leaf(const Node *root, const Node *&temp_root,
                         int value, int &shallow, int curr_depth);
void free_alloc(struct Node *root);


//---------------------------------Main----------------------------------------
int main()
{
    struct Node *root = NULL;

    build_tree(root);

    min_depth_leaf(root);

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

    while(cin.eof())
    //while(value != -1)
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

//min_depth_leaf--------------------------------------------------------------
//Function to find the shallowest leaf in the tree
const Node *min_depth_leaf(const Node *root)
{
    const Node *temp_root;

    int shallow = INT_MAX, curr_depth = 0,
        value = root ->_data,
        min_leaf;

    find_min_leaf(root, temp_root, value, shallow, curr_depth);

    min_leaf = temp_root ->_data;

    cout << min_leaf;
}

//find_min_leaf---------------------------------------------------------------
//function that return a pointer to the shallowest leaf in the tree
const Node *find_min_leaf(const Node *root, const Node *&temp_root,
                          int value, int &shallow, int curr_depth)
{
    if (root != NULL)
    {
    	find_min_leaf(root->_left, temp_root, value, shallow, curr_depth+1);

		if(root ->_data == value)

			curr_depth = 0;

    	if(root->_right == NULL && root->_left == NULL)

			if(curr_depth < shallow)
			{
				temp_root = root;
				shallow = curr_depth;
				return temp_root;
			}

    	find_min_leaf(root ->_right, temp_root, value, shallow, curr_depth+1);

		if(root ->_data == value)

			curr_depth = 0;
    }

    return root;
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
