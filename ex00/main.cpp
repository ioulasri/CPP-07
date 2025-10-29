#include "whatever.hpp"
#include <iostream>
#include <string>

int main()
{
    // Test with integers
    int a = 2;
    int b = 3;

    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    // Test with strings
    std::string c = "string1";
    std::string d = "string2";

    std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "After swap: c = " << c << ", d = " << d << std::endl;

    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

    // Test with double
    double e = 42.42;
    double f = 21.21;

    std::cout << "Before swap: e = " << e << ", f = " << f << std::endl;
    ::swap(e, f);
    std::cout << "After swap: e = " << e << ", f = " << f << std::endl;

    std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
    std::cout << "max(e, f) = " << ::max(e, f) << std::endl;

    // Test case from subject
    int i = 2;
    int j = 3;
    ::swap(i, j);
    std::cout << "i = " << i << ", j = " << j << std::endl;
    std::cout << "min(i, j) = " << ::min(i, j) << std::endl;
    std::cout << "max(i, j) = " << ::max(i, j) << std::endl;

    std::string s1 = "chaine1";
    std::string s2 = "chaine2";
    ::swap(s1, s2);
    std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
    std::cout << "min(s1, s2) = " << ::min(s1, s2) << std::endl;
    std::cout << "max(s1, s2) = " << ::max(s1, s2) << std::endl;

    return 0;
}