#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;

int main(){
ofstream file;
file.open("c:\\Qt\\Projects\\AiP\\Domashka_2\\example.txt");

double x;
std::cout << " Enter x:" << endl;
std::cin>>x;
cout<<"\tx\t\ty"<<endl;
cout.precision(5);

    if (x>5){
        double y=2*(x*x)+10;
        cout<<"\t"<<x<<"\t\t"<<y<<endl;
    }
    else {
        if (x==0){
            double y=0;
            cout<<"\t"<<x<<"\t\t"<<y<<endl;
        }
        else {
            double y=2*abs(x+6)-(x*x);
            cout<<"\t"<<x<<"\t\t"<<y<<endl;
        }
 }

file.close();

return 0;
}
