#include "Array.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#define MAX_VAL 750

int main()
{
    std::cout << "Testing default constructor:" << std::endl;
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;
    
    std::cout << "\nTesting parameterized constructor:" << std::endl;
    Array<int> numbers(5);
    std::cout << "Array size: " << numbers.size() << std::endl;
    
    for (unsigned int i = 0; i < numbers.size(); i++)
    {
        numbers[i] = i * 10;
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }
    
    std::cout << "\nTesting copy constructor:" << std::endl;
    Array<int> copy(numbers);
    std::cout << "Copy array size: " << copy.size() << std::endl;
    
    for (unsigned int i = 0; i < copy.size(); i++)
    {
        std::cout << "copy[" << i << "] = " << copy[i] << std::endl;
    }
    
    std::cout << "\nModifying copy and checking both arrays:" << std::endl;
    copy[2] = 999;
    std::cout << "numbers[2] = " << numbers[2] << ", copy[2] = " << copy[2] << std::endl;
    
    std::cout << "\nTesting assignment operator:" << std::endl;
    Array<int> assigned;
    assigned = numbers;
    std::cout << "Assigned array size: " << assigned.size() << std::endl;
    
    for (unsigned int i = 0; i < assigned.size(); i++)
    {
        std::cout << "assigned[" << i << "] = " << assigned[i] << std::endl;
    }
    
    std::cout << "\nTesting out of bounds access:" << std::endl;
    try
    {
        std::cout << "Trying to access numbers[10] (out of bounds)..." << std::endl;
        std::cout << numbers[10] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\nTesting with string type:" << std::endl;
    Array<std::string> strings(3);
    strings[0] = "Hello";
    strings[1] = "42";
    strings[2] = "World";
    
    for (unsigned int i = 0; i < strings.size(); i++)
    {
        std::cout << "strings[" << i << "] = " << strings[i] << std::endl;
    }
    
    std::cout << "\nRunning provided test cases:" << std::endl;
    Array<int> numbers2(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers2[i] = value;
        mirror[i] = value;
    }
    
    {
        Array<int> tmp = numbers2;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers2[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    
    try
    {
        numbers2[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        numbers2[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers2[i] = rand();
    }
    
    delete [] mirror;
    
    std::cout << "All tests completed successfully!" << std::endl;
    return 0;
}