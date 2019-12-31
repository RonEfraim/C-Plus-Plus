//--------------Include--------------
#include <iostream>
#include <cstdlib>

//--------------Using--------------
using std::cin;
using std::cout;
using std::endl;

//--------------Prototypes--------------
int num_of_ops(unsigned int n1, unsigned int n2);

int main()
{
	unsigned int n1, n2, counter;

	cin >> n1 >> n2;

    counter = num_of_ops(n1, n2);

    cout << counter;

	return EXIT_SUCCESS;
}

int num_of_ops(unsigned int n1, unsigned int n2)
{
    unsigned int add, multiply;

	if(n1 == n2)
    {
		return 0;
    }

    if(n1 > n2)
    {
        return -1;
    }

    add = num_of_ops(n1 + 1, n2);

    multiply = num_of_ops(n1 * 2, n2);

    if(add < multiply)
    {
        return add + 1;
    }

    if(add > multiply)
    {
        return multiply + 1;
    }

    return 0;
}
