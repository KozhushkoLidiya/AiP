#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(){
ofstream file;
file.open("Acer(C:)\\Qt\\Projects\\AiP\\Domashka_3\\example.txt");
int min;
int max;
float elem = 0;
int a = 0;
const unsigned int n = 30;
int arr[n];
std::cout << " Enter [min; max] " << endl;
std::cin >> min ;
std::cin >> max ;

    for(unsigned int i=0; i<n; i++){
       arr[i] = rand() % (max-min+1)+min;
       std::cout << i+1 << " : " << arr[i] << ", " << std::endl;
       if (i%2 == 1 && arr[i]<elem) {
                elem = arr[i];
                a=i;
       }
    }
std::cout << "Elements: [ " << a+1 << " ] = " << elem << endl;
file.close();
return 0;
}
