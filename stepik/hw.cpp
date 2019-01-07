#include <iostream>

using namespace std;
#define BUF 12




// void    remalloc_str(char **str, int *size)
// {
// 	char    *new_str;

// 	new_str = new char [*size + 11];
// 	for (int i = 0; i <= *size; i++)
// 		new_str[i] = (*str)[i];
// 	delete [](*str);
// 	*size += 10;
// 	*str = new_str;
// }



void 			f_resize(char **str, int *size)
{

	 char *n_str = new char[*size + 11];
	int i = 0;
	int k = 0;
	
   
	for(i = 0; i <= *size; i++)
		n_str[i] = (*str)[i];
	delete[] (*str);
	*size += 10;
 
	*str = n_str;
}


// char *getline()
// {
// 	char    *str;
// 	int     i = 0;
// 	int     size = 100;

// 	str = new char [size + 1];
// 	while (1)
// 	{
// 	    while (i < size && std::cin.get(str[i]) && str[i] != '\n')
//             i++;
//         if (i < size)
// 		{
// 			str[i] = '\0';
// 			break ;
// 		}
// 		else
//             remalloc_str(&str, &size);
// 	}
//     return (str);
// }

char * getline()
{
	char *new_str;
	int buf = 64;
	int i = 0;

	new_str = new char[buf + 1];

	while (1)
	{
		while (i < buf && std::cin.get(new_str[i]) && new_str[i] != '\n')
			i++;
		if ( i < buf)
		{
			new_str[i] = '\0';
			break ;
		}
		else
		{
			f_resize(&new_str, &buf);

		}
	}


	return new_str;
}

int main(void)
{
	char *example = getline();
	printf("==>%s\n", example);

	//system("pause");
	return 0;
}


#include <iostream>
