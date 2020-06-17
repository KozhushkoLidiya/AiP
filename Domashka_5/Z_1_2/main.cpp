/*
1.Объявить сущности 1 и 2. Описать их свойства. Включить одну сущность в другую.
    Объявить массив сущностей 1. Заполнить атрибуты числовыми и текстовыми значениями
    (диапазон значений определить самостоятельно).

    самолет, авионика

2.Реализовать чтение и запись данных в
текстовый файл
бинарный файл
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
using namespace std;

const int string_len = 7;

struct Avionics{                  //авионика
    string apparatus;                  //аппарат
    int toggles;                     // Кол-во тумблеров
    int max_voltage;                   // max вольтаж системы
};
struct Computer{                    //самолет
    string firm;                //Фирма
    float spac;                 //Вместительность, чел spaciousness
    float range;                  //Дальность полета, км
    Avionics Avionics;
};

void showComputer(const Computer s){
    cout << s.firm<< "\t"
        << s.spac << "\t"
        << s.range << "\t\t["
        << s.Avionics.apparatus << ","
        << s.Avionics.toggles << ","
        << s.Avionics.max_voltage << "]" << endl;
}

void showComputers(const Computer sts[], const int len){
    cout << " firm \t"
        << "spac \t"
        << "range \t["
        << "apparatus,"
        << "toggles,"
        << "max_voltage]" << endl;

    for(int i=0; i<len; i++)
    {
        showComputer(sts[i]);
    }
    cout << endl;
}

void randString(string &str, const int len){
    static const char alphabet[] =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // очищаем и заносим данные
    str.clear();
    str.append(len, ' ');

    for(int i=0; i < str.length(); i++){
        int r = rand() % (sizeof(alphabet)-1);
        str[i] = alphabet[r];
    }
    str[str.length()] = 0;  // последний символ сообщает о том, что строка закончилась
}

void initComputers(Computer sts[], const int len){
    for(int i=0; i<len; i++)
    {
        // Computer
        sts[i].spac = rand() % 250;
        sts[i].range = 7000.0* (float) rand()/ RAND_MAX+1;
        randString(sts[i].firm, string_len);

        // Avionics
        randString(sts[i].Avionics.apparatus, string_len);
        sts[i].Avionics.toggles = rand() % 120;
        sts[i].Avionics.max_voltage = rand() % 10;
    }
}

void writeTextFile(const Computer sts[], const int l){
    ofstream f;

    f.open("data.txt",ios::trunc|ios::out);
    for(int i = 0; i < l; i++)
        f << sts[i].firm<< " "
        << sts[i].spac << " "
        << sts[i].range << " "
        << sts[i].Avionics.apparatus << " "
        << sts[i].Avionics.toggles << " "
        << sts[i].Avionics.max_voltage << endl;
    f.close();
}

void openTextFile(Computer sts[], const int l){
    ifstream f;

    f.open("data.txt",ios::trunc| ios::in);
    for(int i = 0; i < l; i++)
        f >> sts[i].firm
        >> sts[i].spac
        >> sts[i].range
        >> sts[i].Avionics.apparatus
        >> sts[i].Avionics.toggles
        >> sts[i].Avionics.max_voltage;
    f.close();
}

void writeBinFile(Computer sts[], const int l){
    // in-function WRITE code
    fstream f;
    f.open("data.bin", ios::trunc|ios::out | ios::binary);
    f.write((char*)sts, sizeof(Computer)*l);
    f.close();
}

void openBinFile(Computer sts[], const int l){
    fstream f;
    f.open("data.bin",ios::trunc| ios::in | ios::binary);
    f.read((char*)sts, sizeof(Computer)*l);
    f.close();
}


int main()
{
    cout.precision(5);
    srand(10);

    const int len = 20;
    Computer Computers[len];

    cout << "************Begin array:***********\n";
    initComputers(Computers, len);
    writeTextFile(Computers, len);
    showComputers(Computers, 5);

    cout << "************New array:***********\n";
    initComputers(Computers, len);
    showComputers(Computers, 5);

    cout << "************Read array:**********\n";
    openTextFile(Computers, len);
    showComputers(Computers, 5);

    cout << "************Binary file.**********\n";
    writeBinFile(Computers, len);

    cout << "************New array:***********\n";
    initComputers(Computers, len);
    showComputers(Computers, 5);

    cout << "************Read array:**********\n";
    openBinFile(Computers,len);
    showComputers(Computers, 5);

    return 0;
}



/* *********************************ВЫВОД************************************************
************Begin array:***********
 firm   spac    range   [apparatus,toggles,max_voltage]
WSVSOWA 71      3611.1          [BGTBGFI,101,9]
DGHSXJG 54      4391.1          [LPTHJFK,8,2]
YRXPLZG 151     3922.6          [DDTIBOB,64,3]
WMAQRXR 147     5074.7          [XSIXJIV,74,5]
EMUONSX 199     3262.1          [JSVJKPK,115,3]

************New array:***********
 firm   spac    range   [apparatus,toggles,max_voltage]
JFIJZXX 133     4738.7          [AZZRVDG,83,8]
KFCMISZ 231     4228.9          [USHCKLJ,99,9]
DZCSVHA 180     2716.9          [XSZYQDJ,91,9]
ZNOKBST 66      6951.4          [JIPCSCN,92,7]
YSKPWUF 142     6120            [UMAMCXD,63,3]

************Read array:**********
 firm   spac    range   [apparatus,toggles,max_voltage]
JFIJZXX 133     4738.7          [AZZRVDG,83,8]
KFCMISZ 231     4228.9          [USHCKLJ,99,9]
DZCSVHA 180     2716.9          [XSZYQDJ,91,9]
ZNOKBST 66      6951.4          [JIPCSCN,92,7]
YSKPWUF 142     6120            [UMAMCXD,63,3]

************Binary file.**********
************New array:***********
 firm   spac    range   [apparatus,toggles,max_voltage]
ZOWHSFD 42      6437.2          [VNTXVGS,107,1]
UUQRUQU 214     2246.5          [HNKHBEO,57,1]
EUEVEYM 79      4373.4          [HJTDMRL,109,2]
WAILZII 151     1731.6          [ZEYMXUI,106,0]
ZPLZOIP 48      3461.6          [ETZZLLN,9,3]

************Read array:**********
 firm   spac    range   [apparatus,toggles,max_voltage]
ZOWHSFD 42      6437.2          [VNTXVGS,107,1]
UUQRUQU 214     2246.5          [HNKHBEO,57,1]
EUEVEYM 79      4373.4          [HJTDMRL,109,2]
WAILZII 151     1731.6          [ZEYMXUI,106,0]
*/
