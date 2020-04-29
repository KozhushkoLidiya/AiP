/* Вариант 6
   2.Составить программу, которая будет считать количество действий перестановки элементов.
     Исследовать зависимость количества перестановок от количества элементов в массиве
     (рассмотреть не менее 5-ти значений длины, например, для 100, 1000, 5000, 10000, 100000).
     a) Сортировка выбором; */


#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void selectionSort(float arr[], int len);

int main(){
ofstream file;
file.open("example.txt");
int min = -30;
int max = 20;
const unsigned int n = 100;
float arr[n];

    for( unsigned int i=0; i<n; i++){
         arr[i] = rand() % (max-min+1)+min;
         std::cout << arr[i] << " ";
    }

std::cout << endl << "    " << endl;
std::cout << endl << " ********************  " << endl;
std::cout << endl << "    " << endl;

selectionSort(arr,n);

    for( unsigned int i=0; i<n; i++){
         std::cout << arr[i] << " ";
    }

file.close();
return 0;
}


void selectionSort(float arr[], int len) {
    int j = 0;
    float tmp = 0;
    int nper = 0;

    for(int i=0; i<len; i++){
        // ищем номер наименьшего элемента среди элементов от i-го до конца
        j = i;


        for(int k = i; k < len; k++){
            if(arr[j] > arr[k]){
                j = k;
            }
        }
        // меняем местами наибольший элемент и текущий
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
        nper = nper + 1;
    }
    std::cout << " kolichestvo perestanovok = " << nper << endl;
}



//при сортировке выбором количество перестановок равно длине массива
