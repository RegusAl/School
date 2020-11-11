#include <iostream>
#include <fstream>

using namespace std;

int a[100][100], v[50], n, k;

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

void citireLant()
{
    cout<<"Numarul de noduri: ";
    cin>>k;
    cout<<"Elementele lantului: ";
    for(int i=1; i<=k; i++)
        cin>>v[i];
}

int verificareLant()
{
    bool ok=1;
    for(int i=1; i<=k-1; i++)
        if(a[v[i]][v[i+1]]==0)
            ok=0;

    return ok;
}


int main()
{
    citire();
    afisare();
    citireLant();
    if(verificareLant()==1)
        cout<<"Este Lant";
    else
        cout<<"Nu este Lant";
    return 0;
}
