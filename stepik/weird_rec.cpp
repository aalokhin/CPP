#include <iostream>

using namespace std;

void f_rec(int i)
{
    int j = 0;

    std::cin >> j;


    if (j == 0)
    {
        //std::cout << i << std::endl;
        return ;
    }
    //return (j);
    
    f_rec(i);
    std::cout << j << " ";
    
}

int main()
{
    int i;
    char d;

    std::cin >> i;
    if (i != 0)
       f_rec(i);
   std::cout << i << std::endl;

    return (0);
    
}

// 3 39 20 03 16278 0