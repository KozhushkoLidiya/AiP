#include <iostream>
#include <fstream>
using namespace std;

//задача 1F

int main(){
ofstream file;
file.open("Acer(C:)\\Qt\\Projects\\AiP\\Domashka_3\\example.txt");
const int n = 50;
int arr[n];
    for(int i=0; i<n; i++){
       arr[i] = rand() % 21;
       std::cout << i << " - " << arr[i] << ", " << std::endl;
    }
       std::cout << n << " - " << arr[n-1];
file.close();
return 0;
}
