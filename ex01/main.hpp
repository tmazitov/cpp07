#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>


template <typename T>
void minus(T& element) 
{
   element -= 1;
}

template <>
void minus(std::string& value) 
{
	int len = value.length();
	if (len > 0)
		value[len - 1] = '\0';
}

template <typename T>
void power(T& element) 
{
   element += element;
}

template <typename T>
void printElement(T& element) 
{
    std::cout << element << std::endl;
}

template <typename T, size_t N, typename F>
void iter(T (&arr)[N], unsigned int length, F func)
{
	if (N < length)
		return;
	for (unsigned int i = 0; i < length; i++)
    {
		func(arr[i]);
    }
}

#endif // !MAIN_HPP