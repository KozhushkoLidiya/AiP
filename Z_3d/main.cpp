#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>


using namespace std;


struct Fruit{
    string color;
    int size;
    bool sweet;
};


void randString(string &str){
    static const char alphabet[] =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    str = "     ";


    for(int i=0; i < str.length(); i++){
        int r = rand() % (sizeof(alphabet)-1);
        str[i] = alphabet[r];
    }
    str[str.length()] = 0;
}


void showFruit(const Fruit s){
    cout << s.color<< "\t"
         << s.size << "\t"
         << s.sweet << endl;
}

int findFruitsSize(const Fruit s[], const int l, const float key){
    int count = 0;
    for(int i=0; i<l; i++){
        if(s[i].size > key){
            showFruit(s[i]);
            count++;
        }
    }
    return count;
}


void bubbleSort(Fruit data[], int len) {
    Fruit tmp;
    for(int i = 0; i<len; i++){
        for(int j = len-1; j >= i+1; j--){
            if(data[j].size < data[j-1].size){
                tmp = data[j];
                data[j] = data[j-1];
                data[j-1] = tmp;
            }
        }
    }
}


void write2File(const Fruit s[], const int l){
    ofstream f;
    f.open("Example.txt");


    for(int i = 0; i < l; i++)
        f << s[i].color << "\t"
          << s[i].size << "\t"
          << s[i].sweet << endl;
    f.close();
}


int main(){
    const int n = 20;
    Fruit fruits[n];


    for(int i=0; i<n; i++){
        fruits[i].size = rand() % 30;
            if  (fruits[i].size > 5 && fruits[i].size < 20){
                fruits[i].sweet = false;
            }
            else {
                fruits[i].sweet = true;
            }
        randString(fruits[i].color);
        showFruit(fruits[i]);
    }


    int size = 5.0;
    cout << endl << "Find all books more than " << size << endl;
    int findCount = findFruitsSize(fruits, n, size);
    cout << "Total " << findCount << " elements" << endl;


    cout << endl << "Sorted " << endl;
    bubbleSort(fruits, n);


    for(int i=0; i<n; i++)
        showFruit(fruits[i]);


    write2File(fruits, n);


    return 0;
}
