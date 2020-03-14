#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;

int main(){
ofstream file;
file.open("c:\\Qt\\Projects\\1\\example2.txt");
double leftspan,rightspan,step;
std::cout << "(LEFTSPAN AND RIGHTSPAN)<0" << endl;
std::cout << "Enter leftspan: ";
std::cin >> leftspan;
std::cout << "Enter rightspan: ";
std::cin >> rightspan;
std::cout << "Enter shag: ";
std::cin >> step;
std::cout << "\tx\t\ty" << endl;
std::cout.precision(5);
    for (double x=leftspan; x<=rightspan; x+=step) {
        double y = sqrt(-(1+3*x)*2)+3*x;
        std::cout << "\t" << x << "\t\t" << y << endl;
        file << "\tx\t\ty" << endl;
        file << "\t" << x << "\t\t" << y << endl;
    }
file.close();
return 0;
}
