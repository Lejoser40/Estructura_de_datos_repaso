#include <stdio.h>
#include <iostream>

int main()
{

    int myVal = 13;

    std::cout << "Value of integer 'myVal': %d\n"
              << myVal;
    std::cout << "Size of integer 'myVal': %lu bytes\n"
              << sizeof(myVal); // 4 bytes
    std::cout << "Address to 'myVal': %p\n"
              << &myVal;
    std::cout << "Size of the address to 'myVal': %lu bytes\n"
              << sizeof(&myVal); // 8 bytes

    return 0;
}