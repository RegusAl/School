#include <iostream>
#include <fstream>

using namespace std;

int a[100][100],n;

void citire()
{
    ifstream fin("matrice.in");
    fin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            fin>>a[i][j];
    fin.close();
}

void afisare()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

void RW()
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(a[i][j]==0 && k!=i && k!=j)
                    a[i][j]=a[i][k]*a[k][j];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    citire();
    afisare();
    cout<<endl;
    cout<<"Matricea drumurilor este: "<<endl;
    RW();
    return 0;
}
