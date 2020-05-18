/* Вариант 6
   1.Сгенерировать массив со случайными числами в диапазоне:[-30,20]
   2.Составить программу, которая будет считать количество действий перестановки элементов.
     Исследовать зависимость количества перестановок от количества элементов в массиве
     (рассмотреть не менее 5-ти значений длины, например, для 100, 1000, 5000, 10000, 100000).
     В результате исследования должна получится сравнительная таблица для нескольких методов:
     b) Сортировка вставками;
     с) Сортировка пузырьками; */


#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void insertionSort(float arr[], int len);
void bubbleSort(float arr[], int len);

int main(){
ofstream file;
file.open("example.txt");
int min = -30;
int max = 20;
const unsigned int n = 100000;
float arr[n];

    for( unsigned int i=0; i<n; i++){
         arr[i] = rand() % (max-min+1)+min;
         std::cout << arr[i] << " ";
    }

std::cout << endl << "    " << endl;
std::cout << endl << " ********************  " << endl;
std::cout << endl << "    " << endl;

//insertionSort(arr,n);
bubbleSort(arr,n);

    for( unsigned int i=0; i<n; i++){
         std::cout << arr[i] << " ";
    }

file.close();
return 0;
}

/*void insertionSort(float arr[], int len) {
    float key = 0;
    int j = 0;
    int nper = 0;
    // проход по массиву
    for(int i = 1; i<len; i++){
        key = arr[i];  // ключевой/текущий элемент
        j = i - 1;
        // перестановка элемента на нужное место
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j-1;
            arr[j+1] = key;
            nper = nper + 1;
        }
    }
    std::cout << " kolichestvo perestanovok = " << nper << endl;
}*/

void bubbleSort(float arr[], int len) {
    int nper = 0;
    float tmp = 0;
    // идём по массиву
    for(int i = 0; i<len; i++){
        // делаем проверки в оставшейся части массива
        for(int j = len-1; j >= i+1; j--){
            if(arr[j] < arr[j-1]){  // сравниваем соседние элементы
                // делаем перестановку
                tmp = arr[j];
                arr[j] =arr[j-1];
                arr[j-1] = tmp;
                nper = nper + 1;
            }
        }
    }
    std::cout << " kolichestvo perestanovok = " << nper << endl;
}


/*
   сортировка           длина массива               количество перестановок
*****************************************************************************
   ВСТАВКАМИ                100                               2563
                            500                               61567
                            1000                              242948
                            10000                             24330505
                            100000                            1841763394
*****************************************************************************
   ПУЗЫРЬКАМИ               100                               2563
                            500                               61567
                            1000                              242948
                            10000                             24330505
                            100000                            1841763394
*/
