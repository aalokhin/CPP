#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

// struct String {

//     /* Реализуйте этот конструктор */
// 	String(const char *str = "")
//     {

//         this->size = strlen(str);
//         this->str = new char[this->size + 1];
//         strcpy(this->str, str);        
//     }

// 	size_t size;
// 	char *str;
// };

struct String {

    /* Реализуйте этот конструктор */
	String(size_t n, char c)
    {
        this->str = new char[n + 1];
        
        for (size_t i = 0; i < n; i++)
            this->str[i] = c;
        this->str[n] = '\0';
        this->size = n;
        
    }

    /* и деструктор */
	~String()
    {
        delete []this->str;
    }


	size_t size;
	char *str;
};