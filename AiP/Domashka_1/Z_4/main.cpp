#include <iostream>

int main()
{
    int a;
    int b;
    int c;

       std::cout << "Enter number 1: ";
       std::cin >>  a;

       std::cout << "Enter number 2: ";
       std::cin >>  b;

       c=a;
       a=b;
       b=c;

       std::cout << "obmen:  " << a << " " << b;

    return 0;
}
