#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(){
ofstream file;
file.open("Acer(C:)\\Qt\\Projects\\AiP\\Domashka_3\\example.txt");
float srall;
float srpol;
float srotr;
int npol = 0;
int notr = 0;
int min;
int max;
float sumall = 0;
float sumpol = 0;
float sumotr = 0;
const unsigned int n = 20;
int arr[n];
std::cout << " Enter [min; max] " << endl;
std::cin >> min ;
std::cin >> max ;

    for(unsigned int i=0; i<n; i++){
       arr[i] = rand() % (max-min+1)+min;
       std::cout << i << " : " << arr[i] << ", " << std::endl;
       sumall = sumall+arr[i];
       if (arr[i]>0) {
           sumpol=sumpol+arr[i];
           npol=npol+1;
       }
       else {
           sumotr=sumotr+arr[i];
           notr=notr+1;
       }
    }
srall=sumall/n;
srpol=sumpol/npol;
srotr=sumotr/notr;
std::cout << " The arithmetic mean all = " << srall <<endl;
std::cout << " The arithmetic mean pol = " << srpol <<endl;
std::cout << " The arithmetic mean otr = " << srotr;
file.close();
return 0;
}
