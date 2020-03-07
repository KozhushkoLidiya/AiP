#include <iostream>

using namespace std;

int main()
{
    double a, b, c;
    int dir;  // 1: "+"
              // 2: "-"
              // 3: "*"
              // 4: "/"

    std::cout << " Select an operation: " << endl;
    std::cout << " 1: a+b " << endl;
    std::cout << " 2: a-b " << endl;
    std::cout << " 3: b-a " << endl;
    std::cout << " 4: a*b " << endl;
    std::cout << " 5: a/b " << endl;
    std::cout << " 6: b/a " << endl;

    std::cin >> dir;
    std::cout << " Enter a = ";
    std::cin >> a;
    std::cout << " Enter b = ";
    std::cin >> b;

    switch(dir){
        case 1: c=a+b;
            break;
        case 2: c=a-b;
            break;
        case 3: c=b-a;
            break;
        case 4: c=a*b;
            break;
        case 5: c=a/b;
            break;
        case 6: c=b/a;
            break;
    }

    std::cout << " Resultat = " << c << endl;
    return 0;
}
