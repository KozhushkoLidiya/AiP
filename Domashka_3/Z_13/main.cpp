#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(){
ofstream file;
file.open("Acer(C:)\\Qt\\Projects\\AiP\\Domashka_3\\example.txt");
int min;
int max;
const unsigned int n = 20;
int arr[n];
std::cout << " Enter [min; max] " << endl;
std::cin >> min ;
std::cin >> max ;

    for(unsigned int i=0; i<n; i++){
       arr[i] = rand() % (max-min+1)+min;
       std::cout << i+1 << " : " << arr[i] << ", " << std::endl;
       if (arr[i]>0) {
           arr[i]=arr[i]-1;
           std::cout << i+1 << " : " << arr[i]+1 << "-1 = " << arr[i] << ", " << std::endl;
       }
       else {
           arr[i]=arr[i]+5;
           std::cout << i+1 << " : " << arr[i]-5 << "+5 = " << arr[i] << ", " << std::endl;
       }
    }
file.close();
return 0;
}
