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
/*В квадратной матрице, найти сумму отрицательных элементов, лежащих на главной диагонали.
*/
void SummMinusNumber()
{
    const int n = 4;
    const int m = 4;
    int mat[n][m];
    int k=0;

    srand(time(NULL));
    for(int i = 0; i<n; i++)//заполняем матрицу
        for(int j = 0; j<m; j++)
            mat[i][j] = rand()%15-13;

    for(int i = 0; i<n; i++)    //выводими матрицу
    {
        for(int j = 0; j<m; j++)
            cout << mat[i][j] << " \t";
        cout << endl;
    }

    cout<<' ' <<endl;

    for(int i = 0; i<n; i++)//находим сумму диагональных элементов
    {

        for(int j = 0; j<m; j++)
        {
            if(i==j)
            {
                k+=mat[i][j];
            }
        }
    }
    cout<<"Summ="<<k;
}

int main()
{
    SummMinusNumber();
}

