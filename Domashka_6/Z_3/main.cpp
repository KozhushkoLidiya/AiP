/*
В квадратной матрице для каждой строки найти минимальный элемент и переставить его с элементом,
 стоящим в этой строке на главной диагонали.
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

void   MinDiagonal()
{
    const int n = 4;
    const int m = 4;
    int mat[n][m];

    srand(time(NULL));
    for(int i = 0; i<n; i++)//заполняем матрицу
        for(int j = 0; j<m; j++)
            mat[i][j] = rand()%15;

    for(int i = 0; i<n; i++)    //выводими матрицу
    {
        for(int j = 0; j<m; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    cout<<' ' <<endl;
    for(int i = 0; i<n; i++)
    {
        int min=mat[i][0];
        int z=0;
        for(int j = 0; j<m; j++)
        {
            if(mat[i][j] < min)
            {
                min = mat[i][j];
                z=j;
            }
        }

        int d = mat[i][i];
        mat[i][i] = min;
        mat[i][z] = d;
    }

    for(int i = 0; i<n; i++)    //выводими матрицу
    {
        for(int j = 0; j<m; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    cout<<endl;
}

int main()
{
    MinDiagonal();
}

