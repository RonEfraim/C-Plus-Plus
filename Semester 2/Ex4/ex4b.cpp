/*
 * Compare between rectangle area to circle area
 * =============================================================
 * Written by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program receives from user coordinates to
 * Circle:
 *        The center point of the circle (X and Y)
 *        and the radius.
 *        The input series will end with a center point 0 0.
 * Rectangle:
 *           The top left corner of rectangle (X and Y)
 *           The bottom right (X and Y)
 *           The input series will end with the coordinates 0 0 0 0.
 *
 * Then the program insert the coordinates of circle to a tree and the same
 * action for rectangle's coordinates.
 * Then the program search the the largest circle area in the tree, and the
 * same for rectangle.
 *
 *
 * input:
 *  a. Coordinates.
 *
 * output:
 *  a. The largest circle area in the tree.
 *  b. the largest rectangle area in the tree.
 */


//------------------------------Include---------------------------------------
#include <iostream>
#include <cstdlib>
#include <new>
#include <cmath>

//-------------------------------Using----------------------------------------
using std::cin;
using std::cout;
using std::endl;
using std::nothrow;
using std::cerr;

//-------------------------------Constant-------------------------------------
const int N = 5;

//------------------------------Structure-------------------------------------
struct Point
{
   double _x, _y ;
};

struct Circle
{
   struct Point _center ;
   double _r ;
};

struct Rectangle
{
   struct Point _top_left, _bot_right;
};

struct Node
{
   void *_data ;
   struct Node *_left, *_right ;
};

struct Gen_arr
{
   void *arr[N] ;
   int used ;
};

//------------------------------Prototype-------------------------------------
void *build_sorted_list(struct Node *&root, void *allocate(),
                        bool (*read_item)(void*&, void* allocate()),
                        bool cmp_func(void*, void*));
void insert_item(struct Node *&root, void *new_item,
                 bool cmp_func(void*, void*));
struct Gen_arr *alloc_gen();
void *allocate_circle();
bool read_circle(void *&temp, void *allocate_circle());
void insert_into_tree(Node *&root, Node *new_node,
                      bool cmp_func(void*, void*));
bool cmp_circle(void *p1, void *p2);
void *allocate_rectangle();
bool read_rectangle(void *&temp, void *allocate_rectangle());
bool cmp_rectangle(void *p1, void *p2);
double circle_area(void *root);
double rectangle_area(void *root);
void find_max_area(Node *root, double (*area)(void *),
                   double &max_area, Gen_arr *&point);
void print_arr(Gen_arr *point, void (*tree)(void*));
void print_circle(void *p_arr);
void print_rectangle(void *p_arr);
void delete_tree(struct Node *root, void delete_item(void *));
void delete_circle(void *p);
void delete_rectangle(void *p);
void delete_arrays(struct Gen_arr *arr_c, struct Gen_arr *arr_r);

//---------------------------------Main----------------------------------------
int main()
{
    struct Node *root_rectangle= NULL,
                *root_circle= NULL;

    struct Gen_arr *circle_arr = alloc_gen(),
                   *rectangle_arr = alloc_gen();

    double max_circle = 0, max_rectangle = 0;


    build_sorted_list(root_circle, allocate_circle,
                      read_circle, cmp_circle);

    build_sorted_list(root_rectangle, allocate_rectangle,
                      read_rectangle, cmp_rectangle);

    find_max_area(root_circle, circle_area, max_circle, circle_arr);

    find_max_area(root_rectangle, rectangle_area,
                  max_rectangle, rectangle_arr);

    print_arr(circle_arr, print_circle);

    cout << endl;

    print_arr(rectangle_arr, print_rectangle);

    delete_tree(root_circle, delete_circle);

    delete_tree(root_rectangle, delete_rectangle);

    delete_arrays(circle_arr, rectangle_arr);

    return EXIT_SUCCESS;
}

//build_sorted_list-----------------------------------------------------------
//Generic function that build a tree
void *build_sorted_list(struct Node *&root,
                        void *allocate(),
                        bool (*read_item)(void*&, void* allocate()),
                        bool cmp_func(void*, void*))
{
    bool zero = false;

    void* new_item = allocate();

    while(!zero)
    {
        zero = read_item(new_item, allocate);

        if(!zero)

            insert_item(root, new_item, cmp_func);
    }

    return root;
}

//insert_item-----------------------------------------------------------------
//Generic function that insert values to tree
void insert_item(struct Node *&root,
                 void *new_item,
                 bool cmp_func(void*, void*))
{
    struct Node *new_node = new (nothrow) Node;

    if(new_node == NULL)
    {
        cout << "can not allocate memory \n";
        exit(EXIT_FAILURE);
    }

    new_node ->_data = new_item;
    new_node ->_left = new_node ->_right = NULL;
    insert_into_tree(root, new_node, cmp_func);
}

//alloc_gen-------------------------------------------------------------------
//function that allocate a Gen_arr structure
struct Gen_arr *alloc_gen()
{
    struct Gen_arr *temp = new (nothrow) Gen_arr;

    if(temp == NULL)
    {
        cout << "can not allocate memory \n";
        exit(EXIT_FAILURE);
    }

    return temp;
}

//allocate_circle-------------------------------------------------------------
//function that allocate a Circle structure
void *allocate_circle()
{
    struct Circle *root_circle = new (nothrow) Circle;

    if(root_circle == NULL)
    {
        cout << "can not allocate memory \n";
        exit(EXIT_FAILURE);
    }

    return root_circle;
}

//read_circle-----------------------------------------------------------------
//function that get coordinates for circle
bool read_circle(void *&temp, void *allocate_circle())
{
    temp = allocate_circle();

    double temp_input_1, temp_input_2;

    cin >> temp_input_1 >> temp_input_2;

    if(temp_input_1 != 0 && temp_input_2 !=0)
    {
        (*(struct Circle *) temp)._center._x = temp_input_1;
        (*(struct Circle *) temp)._center._y = temp_input_2;

        cin >> (*(struct Circle *) temp)._r;

        return false;
    }

    return true;
}

//insert_into_tree------------------------------------------------------------
//Generic function that sort the coordinates
void insert_into_tree(Node *&root, Node *new_node,
                      bool cmp_func(void*, void*))
{
    if(root == NULL)

        root = new_node;

    else if (cmp_func(root ->_data, new_node ->_data))

        insert_into_tree(root ->_left, new_node, cmp_func);

    else

        insert_into_tree(root ->_right, new_node, cmp_func);
}

//cmp_circle------------------------------------------------------------------
//function that compare the points of circle by X
bool cmp_circle(void *p1, void *p2)
{
    return (*(Circle *)p1)._center._x < (*(Circle *)p2)._center._x;
}

//allocate_rectangle----------------------------------------------------------
//function that allocate a Rectangle structure
void *allocate_rectangle()
{
    struct Rectangle *temp = new (nothrow) Rectangle;

    if(temp == NULL)
    {
        cout << "can not allocate memory \n";
        exit(EXIT_FAILURE);
    }

    return temp;
}

//read_rectangle--------------------------------------------------------------
//function that get coordinates for circle
bool read_rectangle(void *&temp, void *allocate_rectangle())
{
    temp = allocate_rectangle();

    double temp_input_1, temp_input_2,
           temp_input_3, temp_input_4;

    cin >> temp_input_1 >> temp_input_2
        >> temp_input_3 >> temp_input_4;

    if(temp_input_1 != 0 && temp_input_2 != 0 &&
       temp_input_3 != 0 && temp_input_4 != 0)
    {
        (*(struct Rectangle *) temp)._top_left._x = temp_input_1;
        (*(struct Rectangle *) temp)._top_left._y = temp_input_2;
        (*(struct Rectangle *) temp)._bot_right._x = temp_input_3;
        (*(struct Rectangle *) temp)._bot_right._y = temp_input_4;

        return false;
    }

    return true;
}

//cmp_rectangle---------------------------------------------------------------
//function that compare the points of rectangle by X
bool cmp_rectangle(void *p1, void *p2)
{
    return (*(Rectangle *)p1)._top_left._x < (*(Rectangle *)p2)._top_left._x;
}

//circle_area-----------------------------------------------------------------
//function that calculate the circle area
double circle_area(void *root)
{
    double radius = (*(Circle *) root)._r * (*(Circle *) root)._r;

    return radius * M_PI;
}

//rectangle_area-----------------------------------------------------------------
//function that calculate the rectangle area
double rectangle_area(void *root)
{
    double d1 = (*(Rectangle *) root)._bot_right._x -
                (*(Rectangle *) root)._top_left._x;

    double d2 = (*(Rectangle *) root)._top_left._y -
                (*(Rectangle *) root)._bot_right._y;

    return d1 * d2;
}

//find_max_area---------------------------------------------------------------
//Generic function that run over the trees and search the largest area
void find_max_area(Node *root,
                   double (*area)(void *),
                   double &max_area,
                   Gen_arr *&point)
{
	if (root != NULL)
    {
		find_max_area(root->_left, area, max_area, point);

		double curr_area = area(root->_data);

		if (curr_area > max_area)
        {
			point -> used = 1;
			point -> arr[0] = root->_data;
			max_area = curr_area;
		}
		else if (curr_area == max_area)
        {
			point -> arr[point -> used] = root ->_data;
			point -> used++;
		}


		find_max_area(root->_right, area, max_area, point);
	}
}

//print-----------------------------------------------------------------------
//Generic function that print the point that has the largest area
void print_arr(Gen_arr *point,
               void (*tree)(void*))
{
    for(int index = 0; index < point -> used; index++)

        tree(point -> arr[index]);
}

void print_circle(void *p_arr)
{
    cout << (*(struct Circle *) p_arr)._center._x << " "
         << (*(struct Circle *) p_arr)._center._y << " "
         << (*(struct Circle *) p_arr)._r << " ";
}

void print_rectangle(void *p_arr)
{
    cout << (*(struct Rectangle *) p_arr)._top_left._x << " "
         << (*(struct Rectangle *) p_arr)._top_left._y << " "
         << (*(struct Rectangle *) p_arr)._bot_right._x << " "
         << (*(struct Rectangle *) p_arr)._bot_right._y << " ";
}

//delete----------------------------------------------------------------------
// functions to delete allocated memories
void delete_tree(struct Node *root, void delete_item(void *))
{
    if (root != NULL)
    {
    	delete_tree(root->_left, delete_item);
    	delete_tree(root->_right, delete_item);
    	delete_item(root->_data);
        delete root;
    }
}

void delete_circle(void *p)
{
	delete ((struct Circle *)p);
}

void delete_rectangle(void *p)
{
	delete ((struct Rectangle *)p);
}

void delete_arrays(struct Gen_arr *arr_c, struct Gen_arr *arr_r)
{
	delete[] arr_c;
	delete[] arr_r;
}


