#include <iostream>
#include <cmath>
using namespace std;

int main(){

    float a = 0.1;
    float b = 0.2;
    float x = 1;

    std::cout << "Resultat = " << sqrt(x*x+b)-(b*b*(sin(x+a)*sin(x+a)*sin(x+a))/x) << std::endl;

    return 0;
}
