#include <iostream>

using namespace std;


// int ** m = new int *[a];
// for (size_t i = 0; i != a; ++i)
// m[i] = new int[b]; return m;

// 𝑟𝑜𝑤𝑠×𝑐𝑜𝑙𝑠
// 𝑐𝑜𝑙𝑠xrows

int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    unsigned row_n;
    unsigned col_n;
    unsigned i = 0;
    unsigned j = 0;

    int		**res;

    res = new int *[cols];
    for (i=0; i < cols; ++i)
    {
    	res[i] = new int[rows];
    }

    for(i = 0; i < cols; ++i)
    {
    	for (j = 0; j < rows; ++j)
    	{
    		res[i][j] = m[j][i];
    		//res[i][j] = j;
    		//printf("%d ", res[i][j]);
    	}
    	//printf("\n");
    }
    return res;
    /* ... */
}

void swap_min(int *m[], unsigned rows, unsigned cols)
{
	int min;
	unsigned i, j = 0;
	unsigned x = 0;
	int * tmp;

	min = m[i][j];
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			if (m[i][j] < min)
			{
				min = m[i][j];
				x = i;
			}
		}
	}
	printf("x => %d\n", x);
	tmp = m[0];
	m[0] = m[x];
	m[x] = tmp;

    /* ... */
}


int main ()
{
	unsigned rows = 5;
	unsigned cols = 4;
unsigned i = 0;
int a = 0;
	// int ** m = new int * [5];
	// m[0] = new int[5 * 4];
	// for (size_t i = 1; i != 5; ++i)
	// 	m[i] = m[i - 1] + 4;
	int **m = new int *[rows];

	for (i=0; i < rows; ++i)
    {
    	m[i] = new int[cols];
    }
    a = 0;

	for(int i=0; i<rows; ++i) 
	{
		
		for(int j=0; j<cols; ++j)
		{
			m[i][j] = a;
			a++;
		}
		a = -1;
	}

	for(int i=0; i<rows; ++i)
	{
		for(int j=0; j<cols; ++j)
		{
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
	swap_min(m, rows, cols);
	for(int i=0; i<rows; ++i)
	{
		for(int j=0; j<cols; ++j)
		{
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}	
	//transpose(m, rows, cols);

}

