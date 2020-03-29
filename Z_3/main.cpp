#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(){
ofstream file;
file.open("Acer(C:)\\Qt\\Projects\\AiP\\Domashka_3\\example.txt");
int rrand (int range_min, int range_max);
int a;
int b;
int sumnech = 0;
int sumch = 0;
const unsigned int n = 50;
int arr[n];
std::cout << " Enter [0; b] " << endl;
std::cin >> b ;

    for(unsigned int i=0; i<n; i++){
       arr[i] = rand() % b+1;
       std::cout << i << " - " << arr[i] << ", " << std::endl;
       if (arr[i]%2 == 1) {
           sumnech = sumnech + arr[i];
       }
       else {
           sumch = sumch + arr[i];
       }
    }
       std::cout << n << " - " << arr[n-1] << endl;
       std::cout << " Sum nechetniy elements = " << sumnech <<endl;
       std::cout << " Sum chetniy elements = " << sumch;
file.close();
return 0;
}
