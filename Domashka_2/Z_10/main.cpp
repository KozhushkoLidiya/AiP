#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;

int main(){
ofstream file;
file.open("C:\\Qt\\Projects\\AiP\\Domashka_2\\example.txt");
for (int i=0; i<=185/16; i++)
    for (int j=0; j<=185/17; j++)
        for (int k=0; k<=185/21; k++)
            if (16*i+17*j+21*k==185)
            cout <<"16*"<<i<<" + 17*"<<j<<" + 21*"<<k<<"=185\n";
file.close();
    return 0;
}
