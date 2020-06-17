/*3.Посмотреть примеры и проверить работу функций для чтения PDF и BMP файлов.*/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
#include <string>
using namespace std;

void readPdfHeader(const string fname){
    ifstream f;
    char c[10];
    f.open(fname.c_str());
    if (!f.is_open()) {
        cout << "Error open: " << fname << " with "<< strerror(errno) << endl;
        f.close();
        return;
    }
    f >> c;
    f.close();

    cout << "----------------- PDF file header reader ----------------- \n";
    cout << "Size of char type is " << sizeof(char) << " byte." << endl;
    cout << "PDF header is 8 bytes." << endl;
    cout << "PDF header of \"" << fname << "\" file is: " << c << endl;

    cout << endl;
}


typedef short int WORD;
typedef unsigned int DWORD;
typedef int LONG;

#pragma pack(push, 1)
struct BITMAPFILEHEADER {
    WORD    bfType;
    DWORD   bfSize;
    WORD    bfReserved1;
    WORD    bfReserved2;
    DWORD   bfOffBits;
};
#pragma pack(pop)

struct BITMAPINFOHEADER {
    DWORD  biSize;
    LONG   biWidth;
    LONG   biHeight;
    WORD   biPlanes;
    WORD   biBitCount;
    DWORD  biCompression;
    DWORD  biSizeImage;
    LONG   biXPelsPerMeter;
    LONG   biYPelsPerMeter;
    DWORD  biClrUsed;
    DWORD  biClrImportant;
};

void readBmpHeader(string fname){
    ifstream f;
    BITMAPFILEHEADER fHead;
    BITMAPINFOHEADER imHead;

    f.open(fname);
    if (!f.is_open()) {
        cout << "Error open: " << fname << endl;
        f.close();
        return;
    }
    f.read((char*)&fHead, sizeof(fHead));
    f.read((char*)&imHead, sizeof(imHead));
    f.close();

    cout << "----------------- BMP file header reader ----------------- \n";
    cout << fname << endl;
    cout << "Size of types are (in bytes, / must be):" << endl;
    cout << "WORD  " << sizeof(WORD) << " /2" << endl;
    cout << "DWORD " << sizeof(DWORD) << " /4" << endl;
    cout << "LONG  " << sizeof(LONG) << " /4" << endl;
    cout << "BITMAPFILEHEADER " << sizeof(BITMAPFILEHEADER) << " /14"  << endl;
    cout << "BITMAPINFOHEADER " << sizeof(BITMAPINFOHEADER) << endl;

    cout << endl;

    cout << "File info: ["
         << fHead.bfType << " == 19778, "
         << fHead.bfSize << " bytes, "
         << fHead.bfReserved1 << ", "
         << fHead.bfReserved2 << ", "
         << fHead.bfOffBits << "] " << endl;

    cout << "Image info: ["
         << imHead.biSize << " bytes, ("
         << imHead.biWidth << "x"
         << imHead.biHeight << ") px, "
         << imHead.biBitCount<< " bits] "<< endl;

    cout << endl;
}

void readBmpImageHeader(string fname){
    ifstream f;
    BITMAPINFOHEADER imHead;

    f.open(fname);
    if (!f.is_open()) {
        cout << "Error open: " << fname << endl;
        f.close();
        return;
    }

    cout << "----------------- BMP file Image header reader via seek----------------- \n";
    cout << fname << endl;
    cout << "BITMAPFILEHEADER size is 14 bytes"  << endl;
    cout << "BITMAPINFOHEADER " << sizeof(BITMAPINFOHEADER) << endl;

    cout << "Current position in file " << f.tellg() << endl;
    cout << "Seek 14 bytes" << endl;
    f.seekg(14);  // смещаемся на 14 байт вперёд
    cout << "Current position in file " << f.tellg() << endl;

    f.read((char*)&imHead, sizeof(imHead));
    f.close();

    cout << endl;

    cout << "Image info: ["
         << imHead.biSize << " bytes, ("
         << imHead.biWidth << "x"
         << imHead.biHeight << ") px, "
         << imHead.biBitCount<< " bits] "<< endl;

    cout << endl;
}

void seekOverFile(string fname){
    ifstream f;
    BITMAPINFOHEADER imHead;

    f.open(fname);
    if (!f.is_open()) {
        cout << "Error open: " << fname << endl;
        f.close();
        return;
    }

    cout << "----------------- Seek file example ----------------- \n";
    cout << fname << endl;
    cout << "Current position in file " << f.tellg() << endl;
    f.seekg(14);
    cout << "Current position in file " << f.tellg() << endl;

    // Как узнать размер файла
    f.seekg (0, f.end);  // двигаемся в конец
    int length = f.tellg();  // где мы?
    cout << "Current position in file " << f.tellg() << endl;
    cout << "File size is " << length << " bytes" << endl;

    f.seekg (34, f.beg);  // возврат в начало
    cout << "Current position in file " << f.tellg() << endl;

    DWORD biSizeImage;
    f.read((char*)&biSizeImage, sizeof(DWORD));
    cout << "biSizeImage (This is the size of the raw bitmap data: HxWx3 ) = " << biSizeImage << endl;

    f.read((char*)&imHead, sizeof(imHead));
    f.close();

    cout << endl;
}



int main()
{
    /* Unix-style пути к файлу: слеши / и \ */
    readPdfHeader("./data_samples/file.pdf");

    readBmpHeader("./data_samples/microsoft.bmp");
    readBmpImageHeader("./data_samples/microsoft.bmp");
    seekOverFile("./data_samples/microsoft.bmp");


    cin.get();
    cin.get();
    return 0;
}

//*********************************ВЫВОД**********************************
//                ----------------- PDF file header reader -----------------
//                        Size of char type is 1 byte.
//                        PDF header is 8 bytes.
//                        PDF header of "./data_samples/file.pdf" file is: %PDF-1.4

//                ----------------- BMP file header reader -----------------
//                        ./data_samples/microsoft.bmp
//                        Size of types are (in bytes, / must be):
//                        WORD  2 /2
//                        DWORD 4 /4
//                        LONG  4 /4
//                        BITMAPFILEHEADER 14 /14
//                        BITMAPINFOHEADER 40

//                        File info: [19778 == 19778, 79854 bytes, 0, 0, 54]
//                        Image info: [40 bytes, (200x133) px, 24 bits]

//                ----------------- BMP file Image header reader via seek-----------------
//                        ./data_samples/microsoft.bmp
//                        BITMAPFILEHEADER size is 14 bytes
//                        BITMAPINFOHEADER 40
//                        Current position in file 0
//                        Seek 14 bytes
//                        Current position in file 14

//                        Image info: [40 bytes, (200x133) px, 24 bits]

//                ----------------- Seek file example -----------------
//                        ./data_samples/microsoft.bmp
//                        Current position in file 0
//                        Current position in file 14
//                        Current position in file 79854
//                        File size is 79854 bytes
//                        Current position in file 34
//                        biSizeImage (This is the size of the raw bitmap data: HxWx3 ) = 79800



