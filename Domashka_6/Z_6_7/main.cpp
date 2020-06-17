/*Реализовать вычисление матричных норм из списка.
 * 6,1
*/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <string.h>
using namespace std;

void   Item_6()
{
    const int n = 4;
    const int m = 4;
    int z=0;
    int mat1[n][m]{};
    srand(time(NULL));
    cout<<"Matrix:"<<endl;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            mat1[i][j] = rand()%15;

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
            cout << mat1[i][j] << " ";
        cout << endl;
    }
    cout<<' ' <<endl;
    int q;
    int sum_max=0;
    //реализация сложения
    cout<<"Resolt:"<<endl;
    cout<<"||A||={";
    for(int i = 0; i<n; i++)
    {
        q=0;
        for(int j = 0; j<m; j++)
        {
            z=mat1[i][j];
            q+=z*z;
        }
        cout<<q<<"+";

        sum_max+=q;

    }
    cout<<"}";
    cout<<"= "<<sum_max<<endl;
    cout<<"*********************************"<<endl;
}

void   Item_1()
{
    const int n = 4;
    const int m = 4;
    int z=0;
    int mat1[n][m]{};
    srand(time(NULL));
    cout<<"Matrix:"<<endl;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
           mat1[i][j] =8+rand()%7-11;

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
            cout << mat1[i][j] << " ";
        cout << endl;
    }
    cout<<' ' <<endl;
    int q;
    int max=mat1[0][0];
    //реализация сложения

    cout<<"Resolt:"<<endl;
    cout<<"||A||={";
    for(int j = 0; j<n; j++)
    {
        q=0;
        for(int i = 0; i<m; i++)
        {
            if(mat1[i][j]>0)
            q+=mat1[i][j];
        }
        cout<<q<<", ";
        if(q>max)
        {
            max=q;
        }
    }
    cout<<"}";
    cout<<"= "<<max<<endl;
    cout<<"*********************************"<<endl;
}


int main()
{
    Item_6();
    Item_1();
}
/****************************************ВЫВОД************************************
Matrix:
7 3 8 7
6 0 2 10
2 8 12 11
6 1 4 10

Resolt:
||A||={171+140+333+153+}= 797
*********************************
Matrix:
-1 0 -2 2
0 0 -2 -1
-3 1 0 -1
2 -1 -2 -2

Resolt:
||A||={2, 1, 0, 2, }= 2
*********************************
*/


