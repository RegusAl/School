#include <iostream>
#include <fstream>

using namespace std;

int a[100][100], n, m, v[100], i, j, x, y, nrC;

void citire()
{

    ifstream fin("matrice.in");
    fin >> n;
    while(fin >> i >> j)
    {
        a[i][j] = a[j][i] = 1;
    }
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

void DF(int x, int val)
{
    v[x] = val;
    cout<<x<<" ";
    for(int i = 1 ; i <= n ; i++)
        if(v[i]!=1 && a[x][i] == 1)
        {
            DF(i, val);
            v[i] = val;
        }
}

void ComponenteConexe()
{
    for(int i = 1 ; i <= n ; i++)
        if(v[i] == 0)
        {
            cout<<"DF("<<i<<")= ";
            DF(i, nrC + 1);
            cout<<endl;
            nrC++;
        }
    cout<<"Numarul de componente conexe este: ";
    cout << nrC <<" ";
}

int main()
{
    citire();
    cout<<"Matricea de adiacenta este: "<<endl;
    cout<<"\n";
    afisare();
    cout<<"\n";
    ComponenteConexe();

    return 0;
}
