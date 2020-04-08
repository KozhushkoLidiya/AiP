#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(){
ofstream file;
file.open("Acer(C:)\\Qt\\Projects\\AiP\\Domashka_3\\example.txt");
int min;
int max;
int sumnpol = 0;
const unsigned int n = 20;
int arr[n];
std::cout << " Enter [min; max] " << endl;
std::cin >> min ;
std::cin >> max ;

    for(unsigned int i=0; i<n; i++){
       arr[i] = rand() % (max-min+1)+min;
       std::cout << i << " : " << arr[i] << ", " << std::endl;
       if (arr[i]>0) {
           sumnpol = sumnpol + 1;
       }
    }
       std::cout << " Sum elements > 0 = " << sumnpol;
file.close();
return 0;
}
