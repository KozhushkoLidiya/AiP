/* 3. Объявить сущность и описать её свойства (характеристики вроде роста, цвета, названия и прочего).
Объявить массивы сущностей. Заполнить атрибуты числовыми и текстовыми значениями
(диапазон значений определить самостоятельно).
f. книга
Для каждого из массивов реализовать поиск по ключу (атрибуту структуры).
Для каждого из массивов реализовать сортировку по одному ключу.
*/


#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>


using namespace std;


struct Book{
    string authe;
    int year;
    int page;
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


void showBook(const Book s){
    cout << s.authe<< "\t"
         << s.year << "\t"
         << s.page << endl;
}

int findBooksPage(const Book s[], const int l, const float key){
    int count = 0;
    for(int i=0; i<l; i++){
        if(s[i].page > key){
            showBook(s[i]);
            count++;
        }
    }
    return count;
}


void bubbleSort(Book data[], int len) {   // сортировка по ключу
    Book tmp;
    for(int i = 0; i<len; i++){
        for(int j = len-1; j >= i+1; j--){
            if(data[j].page < data[j-1].page){
                tmp = data[j];
                data[j] = data[j-1];
                data[j-1] = tmp;
            }
        }
    }
}


void write2File(const Book s[], const int l){
    ofstream f;
    f.open("Example.txt");


    for(int i = 0; i < l; i++)
        f << s[i].authe<< "\t"
          << s[i].year << "\t"
          << s[i].page << endl;
    f.close();
}


int main(){
    const int n = 20;
    Book books[n];


    for(int i=0; i<n; i++){
        books[i].year = rand() % 2020;
        books[i].page = rand() % 1000;
        randString(books[i].authe);
        showBook(books[i]);
    }

 // поиск по ключу
    float page = 210.00;
    cout << endl << "Find all books more than " << page << " pages" << endl;
    int findCount = findBooksPage(books, n, page);
    cout << "Total " << findCount << " elements" << endl;


    cout << endl << "Sorted " << endl;
    bubbleSort(books, n);


    for(int i=0; i<n; i++)
        showBook(books[i]);


    write2File(books, n);


    return 0;
}
