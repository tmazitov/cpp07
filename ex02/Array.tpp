#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	std::cout << "Default constructor called\n";
	arr = new T;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	std::cout << "Param constructor called\n";
	arr = new T[n];
	_size = n;
}

template <typename T>
Array<T>::Array(const Array& other)
{
	//use deep copy
	std::cout << "Copy constructor called\n";
	// delete[] arr;
    arr = new T[other._size];
    for (unsigned int i = 0; i < other._size; i++)
        arr[i] = other.arr[i];
    _size = other._size;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	//use deep copy
	std::cout << "Copy assignment operator called\n";
    if (this != &other)
    {
        delete[] arr;
        arr = new T[other._size];
        for (unsigned int i = 0; i < other._size; i++)
            arr[i] = other.arr[i];
        _size = other._size;
    }
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Destructor called\n";
	delete[] arr;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}

template <typename T>
T* Array<T>::getArr() const
{
	return (this->arr);
}

template <typename T>
T& Array<T>::operator[](unsigned int index) const
{
	if (index >= this->size())
		throw(std::out_of_range("array error : index is out of range"));
	return (arr[index]);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& obj)
{
	T* arr = obj.getArr();
	for (unsigned int i = 0; i < obj.size(); i++)
		os << i << ": " << arr[i] << std::endl;
	return (os);
}