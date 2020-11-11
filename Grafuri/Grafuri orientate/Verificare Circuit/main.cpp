#include <iostream>
#include <fstream>

using namespace std;

int a[100][100], n, k, v[50];

void citire()
{
    ifstream fin("matrice.in");
    fin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            fin>>a[i][j];
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

void citireCircuit()
{
    cin>>k;
    for(int i=1; i<=k; i++)
        cin>>v[i];
}

void verificareCircuit()
{
    bool ok1=1, ok2=1;
    for(int i=1; i<=k-1; i++)
    {
        if(a[v[i]][v[i+1]]==0)
            ok1=0;
    }
    if(v[1]!=v[k])
        ok2=0;
    if(ok1==1 && ok2==1)
        cout<<"Este Circuit";
    else
        cout<<"Nu este Circuit";
}

int main()
{
    citire();
    afisare();
    citireCircuit();
    verificareCircuit();
    return 0;
}
