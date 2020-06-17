/*4.Считать ID3v1 из MP3 файлов.*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

void readMp3Header(string fname){
    ifstream f;

    f.open(fname);
    if (!f.is_open()) {
        cout << "Error open: " << fname << endl;
        f.close();
        return;
    }

    unsigned char b2[2];
    unsigned char b3;
    unsigned char b4;

    cout << "----------------- Read First MP3 Header in file without ID3v2----------------- \n";
    f.read((char*)b2, sizeof(b2));
    f.read((char*)&b3, sizeof(char));
    f.read((char*)&b4, sizeof(char));
    f.close();

    cout << fname << endl << "Signature: " << hex << showbase << endl
         << (int) b2[0] << endl
         << (int) b2[1] << endl
         << (int) b3 << endl
         << (int) b4 << endl;

    cout << endl;
}

void readMp3Id3v1(string fname){
    ifstream f;

    f.open(fname);
    if (!f.is_open()) {
        cout << "Error open: " << fname << endl;
        f.close();
        return;
    }


    cout << "----------------- Read First MP3 Header in file without ID3v2----------------- \n";

    f.close();

    cout << endl;
}

int main()
{

    readMp3Header("./data_samples/1.mp3");
    readMp3Header("./data_samples/2.mp3");
    readMp3Header("./data_samples/3.mp3");

    readMp3Id3v1("./data_samples/1.mp3");

    cin.get();
    cin.get();
    return 0;
}

/* *******************ВЫВОД*****************************************
---------------- Read First MP3 Header in file without ID3v2-----------------
./data_samples/1.mp3
Signature:
0xff
0xfb
0x50
0xc4

----------------- Read First MP3 Header in file without ID3v2-----------------
./data_samples/2.mp3
Signature:
0xff
0xfb
0x10
0xc4

----------------- Read First MP3 Header in file without ID3v2-----------------
./data_samples/3.mp3
Signature:
0xff
0xf3
0x24
0xc4

----------------- Read First MP3 Header in file without ID3v2----------------- */
