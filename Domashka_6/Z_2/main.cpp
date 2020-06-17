/*Дана матрица.  Элементы первой строки — мощность электромотора, второй строки — категория мотора
 * (число от 1 до 3). Найти самый мощный мотор категории 3.
*/

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

void MaxMotorCategory()
{
    const int n = 2;
    const int m = 20;
    int mat[n][m];

    srand(time(NULL));
    for(int i = 0; i<n; i++)//заполняем матрицу
        for(int j = 0; j<m; j++)
        {
            mat[0][j] = rand()%99;
            mat[1][j]= rand()%4;
        }

    for(int i = 0; i<n; i++)    //выводими матрицу
    {
        for(int j = 0; j<m; j++)
        {
             cout << mat[i][j] << "  ";
        }
        cout << endl;
    }

    cout<<endl;

    int max=95;
    for(int j = 0; j<m; j++)
    {
        if(mat[1][j]==3)  //отбор по 3 категории мотора
        {
            for(int j = 0; j<m; j++) //поиск max значения и вывод на экран
            {
                if(mat[0][j]>max)
                {
                    max=mat[0][j];
                    cout<<max<<" ";
                }
            }
        }
    }
    cout << endl;
    cout<<' ' <<endl;
    cout<<endl;
}

int main()
{
    MaxMotorCategory();
}
