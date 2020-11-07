#include <iostream>
#include <fstream>

using namespace std;

int a[100][100], n, m;

void citire()
{
    ifstream fin("matrice.in");
    int i, j;
    fin>>n>>m;
    for(int k=1; k<=m; k++)
    {
        fin>>i>>j;
        a[i][j] = 1;
    }
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

void graf_turneu()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(a[i][j]==1 && a[j][i]==1)
                a[j][i]=0;
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
    graf_turneu();
    return 0;
}
