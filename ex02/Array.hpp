#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

template <typename T>
class Array
{
	private:
		T* arr;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();
	
		unsigned int size() const;
		T& operator[](unsigned int index) const;
		T* getArr() const;
		
};

// Include the template definitions in the header file
#include "Array.tpp"

#endif // !ARRAY_HPP