#include <iostream>
#include <fstream>
using namespace std;

int main(){
int a;
std::cout << "Enter a: ";
std::cin >> a;
ofstream file;
file.open("Acer(C:)\\Qt\\Projects\\AiP\\Domashka_2\\example.txt");
    for (int i=1;i<=a;i++) {
        for (int j=1;j<=i;j++) {
            std::cout << 0;
            file << "0";
        }
        std::cout << endl;
        file << endl;
    }
file.close();
getchar();
getchar();
return 0;
}
