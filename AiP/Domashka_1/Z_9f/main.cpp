#include <iostream>

using namespace std;

int main(){

    double a, b;
    int dir;  // 1: Bar->Pascal
              // 2: Bar->F/m
              // 3: Pascal->Bar
              // 4: Pascal->F/m
              // 5: F/m->Pascal
              // 6: F/m->Bar

    std::cout << " Select an operation: " << endl;
    std::cout << " 1: Bar->Pascal " << endl;
    std::cout << " 2: Bar->F/m " << endl;
    std::cout << " 3: Pascal->Bar " << endl;
    std::cout << " 4: Pascal->F/m " << endl;
    std::cout << " 5: F/m->Pascal " << endl;
    std::cout << " 6: F/m->Bar " << endl;

    std::cin >> dir;
    std::cin >> a;

    switch(dir){
        case 1: b=a*100000;
            break;
        case 2: b=a*14.5;
            break;
        case 3: b=a/100000;
            break;
        case 4: b=a*0.000142;
            break;
        case 5: b=a*6894.76;
            break;
        case 6: b=a*0.069;
            break;
    }

    std::cout << b << endl;

    return 0;
}
