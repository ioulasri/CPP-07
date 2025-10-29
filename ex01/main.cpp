#include "iter.hpp"
#include <iostream>
#include <string>

// Function templates to apply to array elements
template <typename T>
void printElement(T &element)
{
    std::cout << element << " ";
}

template <typename T>
void incrementElement(T &element)
{
    element++;
}

template <typename T>
void printConstElement(const T &element)
{
    std::cout << element << " ";
}

// Function for custom class demonstration
class TestClass
{
public:
    TestClass( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, TestClass const & rhs ) { o << rhs.get(); return o; }

int main()
{
    // Test with integers
    int intArr[] = {1, 2, 3, 4, 5};
    size_t intArrLen = sizeof(intArr) / sizeof(int);

    std::cout << "Int array before: ";
    iter(intArr, intArrLen, printElement<int>);
    std::cout << std::endl;

    iter(intArr, intArrLen, incrementElement<int>);
    
    std::cout << "Int array after increment: ";
    iter(intArr, intArrLen, printElement<int>);
    std::cout << std::endl;

    // Test with strings
    std::string strArr[] = {"Hello", "42", "World", "Templates", "CPP07"};
    size_t strArrLen = sizeof(strArr) / sizeof(std::string);
    
    std::cout << "String array: ";
    iter(strArr, strArrLen, printElement<std::string>);
    std::cout << std::endl;

    // Test with const array
    const float floatArr[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    size_t floatArrLen = sizeof(floatArr) / sizeof(float);
    
    std::cout << "Const float array: ";
    iter(floatArr, floatArrLen, printConstElement<float>);
    std::cout << std::endl;

    // Test with custom class
    TestClass TestClassArr[5];
    std::cout << "Custom class array: ";
    iter(TestClassArr, 5, printElement<TestClass>);
    std::cout << std::endl;

    return 0;
}