#include <iostream>
#include "main.hpp"

void test1()
{
	std::cout << "--- test 1 ---\n";
	int array[3] = {5, 6, 7};
	
	iter(array, 3, minus<int>);
	iter(array, 3, printElement<int>);
}

void test2()
{
	std::cout << "--- test 2 ---\n";
	double array[] = {2.1, 2.2, 2.3};
	int size = sizeof(array) / sizeof(array[0]);

	iter(array, size, minus<double>);
	iter(array, size, printElement<double>);
    iter(array, size, power<double>);
    iter(array, size, printElement<double>);    
}

void test3()
{
	std::cout << "--- test 3 ---\n";
	char array[] = {'a', 'b', 'c'};
	int size = sizeof(array) / sizeof(array[0]);
	iter(array, size, minus<char>);
	iter(array, size, printElement<char>);
}

void test4()
{
	std::cout << "--- test 4 ---\n";
	std::string array[] = {"hello", "world"};
	int size = sizeof(array) / sizeof(array[0]);
	iter(array, size, power<std::string>);
    iter(array, size, minus<std::string>);
	iter(array, size, printElement<std::string>);
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	return 0;
}