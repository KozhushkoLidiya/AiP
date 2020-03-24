#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;

int main(){
ofstream file;
file.open("C:\\Qt\\Projects\\AiP\\Domashka_2\\example.txt");
float x, y=x;
int num, i;
std::cout<< "Enter num: ";
std::cin>>num;
std::cout<< "Enter x: ";
std::cin>>x;

    for (i=2; i<=num; i++) {
        if (i%2==1){
            y=y+(x*x*x)/i;
        }
        else {
            y=y-(x*x*x)/i;
        }
    }

    std::cout<<"y = "<<y<<endl;
    file.close();
    return 0;
}
