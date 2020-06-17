/*5.Реализовать чтение форматов
b.ZIP: Local File Header
.*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

void readZipHeader(string fname){
    ifstream f;

    f.open(fname);
    if (!f.is_open()) {
        cout << "Error open: " << fname << endl;
        f.close();
        return;
    }

    //    #pragma pack(push, 1)  // упаковка памяти, иначе структура будет занимать 16 байт, а не 14, как положено
    struct ZIPLOCALFILEHEADER {
        unsigned int sign;
        short int version;
        short int flag;
        short int comp;
        short int lastTime;
        short int lastDate;
        unsigned int crc;
        unsigned int sizec;
        unsigned int sized;
        short int lenName;
        short int lenEf;
        //        char * fName;
        //        char * ef;
    };
    //    #pragma pack(pop)

    ZIPLOCALFILEHEADER lfh;

    cout << "----------------- Read ZIP ----------------- \n";
    f.read((char*) &lfh, sizeof(ZIPLOCALFILEHEADER));
    f.close();

    unsigned short int ud = lfh.lastDate;
    unsigned short int ut = lfh.lastTime;

    cout << fname << endl;
    cout << "Local File Header: " << endl << dec
         << "sign     " << (unsigned int) lfh.sign << endl //<< dec
         << "version  " << (short int) lfh.version << endl
         << "flag     " << (short int) lfh.flag << endl
         << "comp     " << (unsigned short int) lfh.comp << endl
         << "lastTime " << (unsigned short int) lfh.lastTime
         << " (" << ((ut&0xF800) >> 11) << ":"
         << ((((ut)&0x7E0) >> 6)) << ":"
         << 2*(ut&0x1f)<< ")"  << endl
         << "lastDate " << (unsigned short int) lfh.lastDate
         << " (" << (ud&0b11111) << "/"
         << ((((ud)&0x1E0)/0x20)) << "/"
         << (((ud&0x0FE00)/0x0200)+1980) << ")" << endl
         << "crc      " << (unsigned int) lfh.crc << endl
         << "sizec    " << (unsigned int) lfh.sizec << endl
         << "sized    " << (unsigned int) lfh.sized << endl
         << "lenName  " << (short int) lfh.lenName << endl
         << "lenEf    " << (short int) lfh.lenEf << endl;

    cout << endl;
}

int main()
{
    readZipHeader("./data_samples/ezyzip.zip");
    readZipHeader("./data_samples/files.zip");
    readZipHeader("./data_samples/tennis.zip");
    cin.get();
    cin.get();
    return 0;
}

/* **********************************ВЫВОД**********************************************
----------------- Read ZIP -----------------
./data_samples/ezyzip.zip
Local File Header:
sign     67324752
version  20
flag     2056
comp     8
lastTime 44112 (21:17:32)
lastDate 20645 (5/5/2020)
crc      0
sizec    0
sized    655360
lenName  0
lenEf    25972

----------------- Read ZIP -----------------
./data_samples/files.zip
Local File Header:
sign     67324752
version  788
flag     0
comp     8
lastTime 38529 (18:26:2)
lastDate 20645 (5/5/2020)
crc      253610118
sizec    633208832
sized    786432
lenName  0
lenEf    28530

----------------- Read ZIP -----------------
./data_samples/tennis.zip
Local File Header:
sign     67324752
version  788
flag     0
comp     8
lastTime 39765 (19:13:42)
lastDate 20645 (5/5/2020)
crc      46463149
sizec    280887296
sized    655360
lenName  0
lenEf    25972
*/



