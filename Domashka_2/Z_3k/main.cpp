#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;

int main(){
ofstream file;
file.open("C:\\Qt\\Projects\\AiP\\Domashka_2\\example2.txt");
double step,leftscope,rightscope;
cout<<"Enter leftscope(leftscope>-2): ";
cin>>leftscope;
cout<<"Enter rightscope: ";
cin>>rightscope;
cout<<"Enter step: ";
cin>>step;
cout<<"\tx\t\ty"<<endl;
cout.precision(5);

    for (double x=leftscope;x<=rightscope;x+=step) {
    double y=sqrt(5+4*x)+13*x+cos(12*x+91);
    cout<<"\t"<<x<<"\t\t"<<y<<endl;
    file<<"\tx\t\ty"<<endl;
    file<<"\t"<<x<<"\t\t"<<y<<endl;
    }

file.close();

return 0;
}
