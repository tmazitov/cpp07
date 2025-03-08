#include "Array.hpp"

#define MAX_VAL 25

void testWrongIndex(Array<int>& numbers)
{
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << "2. ✅ Wrong minimum handled : " << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << "3. ✅ Wrong maximum handled : " << e.what() << '\n';
    }
}

void testEquality(Array<int>& numbers, int* mirror)
{

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cout << "1. ❌ Custom and default arrays are not equal!" << std::endl;
            return;
        }
    }

    std::cout << "1. ✅ Custom and default arrays are equal!" << std::endl;
}

void testCreateCopy(Array<int>& numbers)
{
    Array<int> copyNumbers(numbers);
    Array<int> anotherCopyNumbers;
    anotherCopyNumbers = copyNumbers;

    copyNumbers[5] = rand();
    anotherCopyNumbers[6] = rand();
    
    if (copyNumbers[5] != numbers[5])
    {
        std::cout << "4. ✅ Copy and original custom arrays have different memory !" << std::endl;
    }
    else
    {
        std::cout << "4. ❌ Copy and original custom arrays have the same memory !" << std::endl;
    }

    std::cout << "origin : " << numbers[5] << " copy : " << copyNumbers[5] << std::endl;
    
    if (anotherCopyNumbers[6] != numbers[6])
    {
        std::cout << "5. ✅ Another copy and copy custom arrays have different memory !" << std::endl;
    }
    else
    {
        std::cout << "5. ❌ Another copy and copy custom arrays have the same memory !" << std::endl;
    }

    std::cout << "copy : " << copyNumbers[6] << " another copy : " << anotherCopyNumbers[6] << std::endl;
}

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    testEquality(numbers, mirror);
    testWrongIndex(numbers);
    testCreateCopy(numbers);

    delete [] mirror;
    return 0;
}