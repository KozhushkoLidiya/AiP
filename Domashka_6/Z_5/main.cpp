/*
Реализовать сложение, вычитание, умножение, транспонирование матриц (разрешается
фиксированный размер матриц).
*/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <string>
using namespace std;


void   SummMatrix()
{
    const int n = 4;
    const int m = 4;
    const int r = 4;
    const int k = 4;
    const int d = 4;
    const int y = 4;
    int mat1[n][m]{};
    int mat2[r][k]{};
    int summ[d][y]{};
    srand(time(NULL));
    cout<<"*************************************"<<endl;
    cout<<"Fitst matrix:"<<endl;
    for(int i = 0; i<n; i++)//заполняем матрицу
        for(int j = 0; j<m; j++)
            mat1[i][j] = rand()%15;

    for(int i = 0; i<n; i++)    //выводими матрицу
    {
        for(int j = 0; j<m; j++)
            cout << mat1[i][j] << " ";
        cout << endl;
    }
    cout<<' ' <<endl;

    cout<<"Second matrix:"<<endl;
    for(int r = 0; r<n; r++)//заполняем матрицу
        for(int k = 0; k<m; k++)
            mat2[r][k] = rand()%15;

    for(int r = 0; r<n; r++)    //выводими матрицу
    {
        for(int k = 0; k<m; k++)
            cout << mat2[r][k] << " ";
        cout << endl;
    }

    cout<<' ' <<endl;
    //реализация сложения
    cout<<"Summ:"<<endl;
    for(int d = 0; d<n; d++)
    {
        for(int y = 0; y<m; y++)
        {
            summ[d][y]=mat1[d][y]+mat2[d][y];
            cout << summ[d][y] << " ";
        }
    cout << endl;
    }
    cout<<"*************************************"<<endl;
}

void   SubtractionMatrix()
{
    const int n = 4;
    const int m = 4;
    const int r = 4;
    const int k = 4;
    const int d = 4;
    const int y = 4;
    int mat1[n][m]{};
    int mat2[r][k]{};
    int sub[d][y]{};
    srand(time(NULL));
    cout<<"*************************************"<<endl;
    cout<<"Fitst matrix:"<<endl;
    for(int i = 0; i<n; i++)//заполняем матрицу
        for(int j = 0; j<m; j++)
            mat1[i][j] = rand()%15;

    for(int i = 0; i<n; i++)    //выводими матрицу
    {
        for(int j = 0; j<m; j++)
            cout << mat1[i][j] << " ";
        cout << endl;
    }
    cout<<' ' <<endl;

    cout<<"Second matrix:"<<endl;
    for(int r = 0; r<n; r++)//заполняем матрицу
        for(int k = 0; k<m; k++)
            mat2[r][k] = rand()%15;

    for(int r = 0; r<n; r++)    //выводими матрицу
    {
        for(int k = 0; k<m; k++)
            cout << mat2[r][k] << " ";
        cout << endl;
    }

    cout<<' ' <<endl;
    //реализация сложения
    cout<<"Subtraction:"<<endl;
    for(int d = 0; d<n; d++)
    {
        for(int y = 0; y<m; y++)
        {
            sub[d][y]=mat1[d][y]-mat2[d][y];
            cout << sub[d][y] << " ";
        }
    cout << endl;
    }

    cout<<endl;
    cout<<"*************************************"<<endl;
}

void   MultiplicationMatrix()
{
    const int n = 4;
    const int m = 4;
    const int r = 4;
    const int k = 4;
    const int d = 4;
    const int y = 4;
    int mat1[n][m]{};
    int mat2[r][k]{};
    int mult[d][y]{};
    srand(time(NULL));
    cout<<"*************************************"<<endl;
    cout<<"Fitst matrix:"<<endl;
    for(int i = 0; i<n; i++)//заполняем матрицу
        for(int j = 0; j<m; j++)
            mat1[i][j] = rand()%15;

    for(int i = 0; i<n; i++)    //выводими матрицу
    {
        for(int j = 0; j<m; j++)
            cout << mat1[i][j] << " ";
        cout << endl;
    }
    cout<<' ' <<endl;

    cout<<"Second matrix:"<<endl;
    for(int r = 0; r<n; r++)//заполняем матрицу
        for(int k = 0; k<m; k++)
            mat2[r][k] = rand()%15;

    for(int r = 0; r<n; r++)    //выводими матрицу
    {
        for(int k = 0; k<m; k++)
            cout << mat2[r][k] << " ";
        cout << endl;
    }

    cout<<' ' <<endl;
    //реализация сложения
    cout<<"Multiplication:"<<endl;
    for(int d = 0; d<n; d++)
    {
        for(int y = 0; y<m; y++)
        {
            mult[d][y]=mat1[d][y]*mat2[d][y];
            cout << mult[d][y] << " ";
        }
    cout << endl;
    }
    cout<<"*************************************"<<endl;
}

void   TranspositionMatrix()
{
    const int n = 4;
    const int m = 4;
    const int d = 4;
    const int y = 4;
    int mat1[n][m]{};
    int tran[d][y]{};
    srand(time(NULL));
    cout<<"*************************************"<<endl;
    cout<<"Fitst matrix:"<<endl;
    for(int i = 0; i<n; i++)//заполняем матрицу
        for(int j = 0; j<m; j++)
            mat1[i][j] = rand()%15;

    for(int i = 0; i<n; i++)    //выводими матрицу
    {
        for(int j = 0; j<m; j++)
            cout << mat1[i][j] << " ";
        cout << endl;
    }

    cout<<' ' <<endl;
    //реализация сложения
    cout<<"Transposition:"<<endl;
    for(int d = 0; d<n; d++)
    {
        for(int y = 0; y<m; y++)
        {
            tran[d][y]=mat1[y][d];
            cout << tran[d][y] << " ";
        }
    cout << endl;
    }
    cout<<"*************************************"<<endl;
}

int main()
{
    SummMatrix();
    SubtractionMatrix();
    MultiplicationMatrix();
    TranspositionMatrix();
}
