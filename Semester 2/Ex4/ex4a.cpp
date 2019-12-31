/*
 * Compare between rectangle to point
 * =============================================================
 * Written by: Ron Efraim, id = 204661425, login = ronef
 *
 * The program receives from user:
 * - Type of print: "-" without brackets.
 *                Any other character, with brackets.
 * - How many coordinates the user wants to input:
 *   coordinates to:
 *                Point:
 *                      (X and Y),
 *
 *                Rectangle:
 *                      The top left corner of rectangle (X and Y)
 *                      The bottom right (X and Y)
 * - Type of comparison:
 *                Point: "x"- sort by X
 *                       "y"- sort by Y
 *                       "r"- sort by radius
 *                       "a"- sort by alpha
 *                Rectangle:
 *                       "a"- sort by area
 *                       "c"- sort by circumference
 *                       "d"- sort by diagonal_length
 *
 * Then the program print the sorting arrays according to the user's choice.
 *
 *
 * input:
 *  a. Type of print: "-" without brackets
 *                    any other character, with brackets
 *  b. Coordinates.
 *  c. Type of comparison
 *
 * output:
 *  a. Sorting arrays according to the user's choice.
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

//------------------------------Structure-------------------------------------
struct Point
{
    double _x, _y;
};

struct Rectangle
{
   struct Point _top_left,
                _bottom_right;
};

//------------------------------Prototype-------------------------------------
void alloc_point(struct Point *&arr_p, int quantity_p);
void alloc_rectangle(struct Rectangle *&arr_r, int quantity_r);
void read_arr(void * arr, int quantity, void *(get_p2_cell_func)(void *, int),
              void (*insert_item)(void *));
void *get_p2_point_cell(void *arr, int index);
void insert_point(void *p);
void *get_p2_rectangle_cell(void *arr, int index);
void insert_rectangle(void *p);

double get_x(Point arr_p);
double get_y(Point arr_p);
double radius(Point arr_p);
double alpha(Point arr_p);

double area(double d1, double d2);
double circumference(double d1, double d2);
double diagonal_length(Rectangle arr_r);

void q_sort(void* arr, int from, int to,
            void*(*get_p2_cell_func)(void *p, int index),
            bool (*cmp_func)(void *p1, void *p2),
            void (*swap_func)(void *p1, void *p2));
int partition(void* arr,int from, int to,
              void*(*get_p2_cell_func)(void *p, int index),
              bool (*cmp_func)(void *p1, void *p2),
              void (*swap_func)(void *p1, void *p2));

void choose_point_sort(void* arr, char type, int quantity);
void choose_rectangle_sort(void* arr, char type, int quantity);

bool cmp_x(void* p1, void* p2);
bool cmp_y(void* p1, void* p2);
bool cmp_r(void* p1, void* p2);
bool cmp_alpha(void* p1, void* p2);
bool cmp_a(void* p1, void* p2);
bool cmp_c(void* p1, void* p2);
bool cmp_d(void* p1, void* p2);

void swap_point(void *p1, void *p2);
void swap_rectangle(void *p1, void *p2);

void print(void* arr, int quantity,
           void *(get_p2_cell_func)(void *, int), void (*print)(void*));
void print_p_1(void* arr);
void print_p_2(void* arr);
void print_r_1(void* arr);
void print_r_2(void* arr);


//---------------------------------Main---------------------------------------
int main()
{
    struct Point *arr_p;

    struct Rectangle *arr_r;

    int quantity_p = 0, quantity_r = 0;

    char type_p, type_r, choose_print;

    cin >> choose_print;

    cin >> quantity_p;

    alloc_point(arr_p, quantity_p);

    read_arr(arr_p, quantity_p, get_p2_point_cell, insert_point);

    cin >> quantity_r;

    alloc_rectangle(arr_r, quantity_r);

    read_arr(arr_r, quantity_r, get_p2_rectangle_cell, insert_rectangle);

    cin >> type_p;

    choose_point_sort(arr_p, type_p, quantity_p);

    cin >> type_r;

    choose_rectangle_sort(arr_r, type_r, quantity_r);

    if(choose_print == '-')
    {
        print(arr_p, quantity_p, get_p2_point_cell, print_p_1);
        print(arr_r, quantity_r, get_p2_rectangle_cell, print_r_1);
    }
    else
    {
        print(arr_p, quantity_p, get_p2_point_cell, print_p_2);
        print(arr_r, quantity_r, get_p2_rectangle_cell, print_r_2);
    }

    delete[] arr_p;
	delete[] arr_r;

    return EXIT_SUCCESS;
}

//alloc_point-----------------------------------------------------------------
//function that allocate a Point structure
void alloc_point(struct Point *&arr_p, int quantity_p)
{
    arr_p = new (nothrow) struct Point[quantity_p];

    if(arr_p == NULL)
    {
        cout << "can not allocate memory \n";
        exit(EXIT_FAILURE);
    }
}

//alloc_rectangle-------------------------------------------------------------
//function that allocate a Rectangle structure
void alloc_rectangle(struct Rectangle *&arr_r, int quantity_r)
{
    arr_r = new (nothrow) struct Rectangle[quantity_r];

    if(arr_r == NULL)
    {
        cout << "can not allocate memory \n";
        exit(EXIT_FAILURE);
    }
}


//read_arr--------------------------------------------------------------------
//Generic function that insert the structures to arrays
void read_arr(void * arr,
              int quantity,
              void *(get_p2_cell_func)(void *, int),
              void (*insert_item)(void *))
{
    for (int i = 0; i < quantity; i++)
    {
        void *p = get_p2_cell_func(arr, i);

        insert_item(p);
    }
}

//Point-----------------------------------------------------------------------

//get_p2_point_cell-----------------------------------------------------------
//Function that return a pointer to Point cell
void *get_p2_point_cell(void *arr, int index)
{
    return ((struct Point *)arr) + index;
}

//insert_point----------------------------------------------------------------
//Function that insert coordinates to Point
void insert_point(void *p)
{
    cin >> (*(struct Point *) p)._x >> (*(struct Point *) p)._y;
}

//Rectangle-------------------------------------------------------------------

//get_p2_rectangle_cell-------------------------------------------------------
//Function that return a pointer to Point cell
void *get_p2_rectangle_cell(void *arr, int index)
{
    return ((struct Rectangle *)arr) + index;
}

//insert_rectangle------------------------------------------------------------
//Function that insert coordinates to Rectangle
void insert_rectangle(void *p)
{
    cin >> (*(struct Rectangle *) p)._top_left._x >>
           (*(struct Rectangle *) p)._top_left._y;

    cin >> (*(struct Rectangle *) p)._bottom_right._x
        >> (*(struct Rectangle *) p)._bottom_right._y;
}

//----------------------------------------------------------------------------
//The functions receive a pointer to a memory that contains a
//Point structure and returns an actual value
double get_x(Point arr_p)
{
    return arr_p._x;
}

double get_y(Point arr_p)
{
    return arr_p._y;
}

double radius(Point arr_p)
{
    double d = sqrt ((arr_p._x - 0)*(arr_p._x - 0) +
                     (arr_p._y - 0)*(arr_p._y - 0));

    return d;
}

double alpha(Point arr_p)
{
	double angle;

	if (get_x(arr_p) > 0 && get_y(arr_p) > 0)

		angle = atan(get_y(arr_p) / get_x(arr_p));

    else if (get_x(arr_p) < 0 && get_y(arr_p) < 0)

		angle = M_PI + (atan(get_y(arr_p) / get_x(arr_p)));

	else if (get_x(arr_p) < 0 && get_y(arr_p) > 0)

		angle = M_PI - (atan(get_y(arr_p) / get_x(arr_p)));

	else

		angle = 2 * M_PI - (atan(get_y(arr_p) / get_x(arr_p)));

	return angle;
}

//----------------------------------------------------------------------------
//The functions receive a pointer to a memory that contains a
//Rectangle structure and returns an actual value
double area(Rectangle arr_r)
{
    double d1 = arr_r._bottom_right._x - arr_r._top_left._x;

    double d2 = arr_r._top_left._y - arr_r._bottom_right._y;

    return d1 * d2;
}

double circumference(Rectangle arr_r)
{
    double d1 = arr_r._bottom_right._x - arr_r._top_left._x;

    double d2 = arr_r._top_left._y - arr_r._bottom_right._y;

    return (2*d1) + (2*d2);
}

double diagonal_length(Rectangle arr_r)
{
    double d = sqrt ((arr_r._top_left._x - arr_r._bottom_right._x)*
                     (arr_r._top_left._x - arr_r._bottom_right._x)+
                     (arr_r._top_left._y - arr_r._bottom_right._y)*
                     (arr_r._top_left._y - arr_r._bottom_right._y));
    return d;
}

//sort------------------------------------------------------------------------
//Generic function that sorting the arrays by Quick Sorting System
void q_sort(void* arr,
            int from, int to,
            void*(*get_p2_cell_func)(void *p, int index),
            bool (*cmp_func)(void *p1, void *p2),
            void (*swap_func)(void *p1, void *p2))
{
    int pivot_place = partition(arr, from, to, get_p2_cell_func,
                                cmp_func, swap_func);

    if (from < pivot_place - 1)

        q_sort(arr, from, pivot_place - 1, get_p2_cell_func,
               cmp_func, swap_func);

    if (to > pivot_place + 1)

        q_sort(arr, pivot_place + 1, to, get_p2_cell_func,
               cmp_func, swap_func);
}
//------------------------------------------------
int partition(void* arr,
              int from, int to,
              void*(*get_p2_cell_func)(void *p, int index),
              bool (*cmp_func)(void *p1, void *p2),
              void (*swap_func)(void *p1, void *p2))
{
    int pivot_place = from;

    for (int ind = from + 1; ind <= to; ind++)
    {
        void *p1 = get_p2_cell_func(arr, ind),
             *p2 = get_p2_cell_func(arr, pivot_place);

        if(cmp_func(p1, p2))
        {
            swap_func(p1, get_p2_cell_func(arr, pivot_place + 1));

            swap_func(get_p2_cell_func(arr, pivot_place + 1), p2);

            pivot_place++;
        }
    }

    return pivot_place;
}

//choose_point_sort-----------------------------------------------------------
//Function that switch between the user selection in Point array
void choose_point_sort(void* arr, char type, int quantity)
{
    switch(type)
    {
        case 'x':

            q_sort(arr, 0, quantity - 1, get_p2_point_cell,
                   cmp_x, swap_point);
            break;

        case 'y':

            q_sort(arr, 0, quantity - 1, get_p2_point_cell,
                   cmp_y, swap_point);
            break;

        case 'r':

            q_sort(arr, 0, quantity - 1, get_p2_point_cell,
                   cmp_r, swap_point);
            break;

        case 'a':

            q_sort(arr, 0, quantity - 1, get_p2_point_cell,
                   cmp_alpha, swap_point);
            break;
    }
}

//choose_rectangle_sort-------------------------------------------------------
//Function that switch between the user selection in Rectangle array
void choose_rectangle_sort(void* arr, char type, int quantity)
{
    switch(type)
    {
        case 'a':

            q_sort(arr, 0, quantity - 1, get_p2_rectangle_cell,
                   cmp_a, swap_rectangle);
            break;

        case 'c':

            q_sort(arr, 0, quantity - 1, get_p2_rectangle_cell,
                   cmp_c, swap_rectangle);
            break;

        case 'd':

            q_sort(arr, 0, quantity - 1, get_p2_rectangle_cell,
                   cmp_d, swap_rectangle);
            break;
    }
}

//Comparison function for Point array-----------------------------------------
bool cmp_x(void* p1, void* p2)
{
    return get_x(*(Point *)p1) < get_x(*(Point *)p2);
}

bool cmp_y(void* p1, void* p2)
{
    return get_y(*(Point *)p1) < get_y(*(Point *)p2);
}

bool cmp_r(void* p1, void* p2)
{
    return radius(*(Point *)p1) < radius(*(Point *)p2);
}

bool cmp_alpha(void* p1, void* p2)
{
    return alpha(*(Point *)p1) < alpha(*(Point *)p2);
}



//Comparison function for Rectangle array-------------------------------------
bool cmp_a(void* p1, void* p2)
{
    return area(*(Rectangle *)p1) < area(*(Rectangle *)p2);
}

bool cmp_c(void* p1, void* p2)
{
    return circumference(*(Rectangle *)p1) < circumference(*(Rectangle *)p2);
}

bool cmp_d(void* p1, void* p2)
{
    return diagonal_length(*(Rectangle *)p1) <
                diagonal_length(*(Rectangle *)p2);
}


//Swap functions--------------------------------------------------------------
void swap_point(void *p1, void *p2)
{
    struct Point temp = *((Point *) p1);

    *((Point *)p1) = *((Point *) p2);

    *((Point *)p2) = temp;
}

void swap_rectangle(void *p1, void *p2)
{
    struct Rectangle temp = *((Rectangle *)p1);

    *((Rectangle *)p1) = *((Rectangle *)p2);

    *((Rectangle *)p2) = temp;
}


//Print functions-------------------------------------------------------------
void print(void* arr,
           int quantity,
           void *(get_p2_cell_func)(void *, int),
           void (*print)(void*))
{
    //for(int index = quantity - 1; index > -1; index--)
    for(int index = 0; index < quantity; index++)
    {
        void *p1 = get_p2_cell_func(arr, index);

        print(p1);
    }

    cout << endl;
}

void print_p_1(void* arr)
{
    cout<< get_x(*(struct Point *)arr) << " "
        << get_y(*(struct Point *)arr) << " ";
}

void print_p_2(void* arr)
{
    cout << '(' << get_x(*(struct Point *)arr) << ','
         << " " << get_y(*(struct Point *)arr) << ')'
         << " ";
}

void print_r_1(void* arr)
{
    cout << (*(struct Rectangle *)arr). _top_left._x << " "
         << (*(struct Rectangle *)arr). _top_left._y << " "
         //<< endl
         << (*(struct Rectangle *)arr). _bottom_right._x << " "
         << (*(struct Rectangle *)arr). _bottom_right._y << " ";
}

void print_r_2(void* arr)
{
    cout << '[' << '(' << (*(struct Rectangle *)arr). _top_left._x << ','
         <<" " << (*(struct Rectangle *)arr). _top_left._y << ')'
         << ',' << " "
         << '(' << (*(struct Rectangle *)arr). _bottom_right._x << ','
         <<" " << (*(struct Rectangle *)arr). _bottom_right._y << ')' << ']'
         <<" ";
}



