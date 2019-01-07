#include <iostream>

using namespace std;



void swap (int * a, int * b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


// void shift_arr_elem(int * arr, int arrSize, int shift)


void rotate(int a[], int size, int shift)
{
    int to_move;
    int i;
    int j;
    int tmp;

    to_move = 0;
	i = 0;
	j = 0;
	tmp = 0;
    if (shift > size)
        to_move = shift%size;
    else if (shift <= size)
        to_move = shift;


 	while(i < to_move)
 	{
 		tmp = a[0];
 		j = 0;
 		while(j < size-1)
 		{
 			a[j] = a[j+1];
 			j++;
 		}
 		a[size-1] = tmp;

 		i++;
 	}
}



int main()
{
	unsigned b = 0;
	unsigned size = 5;

	int i[5] = {1, 2, 3, 4, 5};
	rotate (i, size, 2);
	while (b < 5)
	{
		std::cout << i[b] << " ";
		b++;

	}
	std::cout << std::endl;
	return (0);
	
}

// 3 39 20 03 16278 0