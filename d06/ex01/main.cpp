#include <string>
#include <iostream>


struct Data
{
	int i;
	std::string str1;
	std::string str2;
};


void * serialize( void )
{
	int i = 0;
	std::string rstr = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWZYZ";

	void * serializedData = operator new (sizeof(char) * 16 + sizeof(int));


	while (i < 8)
	{
		reinterpret_cast<char*>(serializedData)[i] = rstr[rand() % 62];
		i++;
	}

	reinterpret_cast<int*>(serializedData)[8] = rand();
	i = 12;

	while (i < 20)
	{
		reinterpret_cast<char*>(serializedData)[i] = rstr[rand() % 62];
		i++;
	}
	return (serializedData);
}




Data * deserialize( void * raw )
{
	Data *data = new Data;

	int i = 0;


	while (i < 8)
	{
		data->str1.push_back(reinterpret_cast<char*>(raw)[i]);
		i++;
	}
	data->i = reinterpret_cast<int*>(raw)[8];
	i = 12;
	while (i < 20)
	{
		data->str2.push_back(reinterpret_cast<char*>(raw)[i]);
		i++;
	}

	return (data);
}





int main(void)
{
	srand(time(NULL));

	void *raw = serialize();

	Data *data = deserialize(raw);

	std::cout << "str1: " << data->str1 << std::endl;
	std::cout << "i:  " << data->i << std::endl;
	std::cout << "str2: " << data->str2 << std::endl;
	return (0);
}