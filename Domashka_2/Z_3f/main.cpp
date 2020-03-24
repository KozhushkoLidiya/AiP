#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;

int main(){
ofstream file;
file.open("C:\\Qt\\Projects\\AiP\\Domashka_2\\example.txt");
int x, y=0, num, i;
std::cout<< "Enter num: ";
std::cin>>num;
std::cout<< "Enter x: ";
std::cin>>x;

    for (i=1; i<=num; i++) {
        if (i%2==1){
            y=y+i*x;
        }
        else {
            y=y-i*x;
        }
    }

    std::cout<<"y = "<<y<<endl;
    file.close();
    return 0;
}
