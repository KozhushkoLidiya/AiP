#include <iostream>
#include <fstream>
using namespace std;

int main(){
ofstream file;
file.open("Acer(C:)\\Qt\\Projects\\AiP\\Domashka_3\\example.txt");
int a;
int sum = 0;
const int n = 50;
std::cout << "number range from 0 to (a-1): a = ";
std::cin >> a;
int arr[n];
    for(int i=0; i<n; i++){
       arr[i] = rand() % a;
       std::cout << i << " - " << arr[i] << ", " << std::endl;
       if (arr[i]<15) {
           sum = sum + arr[i];
       }
    }
       std::cout << n << " - " << arr[n-1] << endl;
       std::cout << " Sum elements < 15 = " << sum;
file.close();
return 0;
}