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
    for(int i=1; i<=k; i++)
        cin>>v[i];
}

void verificareLantElementar()
{
    bool ok1=1, ok2=1;
    for(int i=1; i<=k-1; i++)
    {
        if(a[v[i]][v[i+1]]==0)
            ok1=0;
    }
    for(int i=1; i<=k; i++)
        for(int j=i+1; j<=n-1; j++)
        {
            if(v[i]==v[j])
                ok2=0;
        }
    if(ok1==1 && ok2==1)
        cout<<"Lantul este elementar";
    else if(ok1==1 && ok2==0)
        cout<<"Lantul nu este elementar";
    else
        cout<<"Nu este Lant";
}

int main()
{
    citire();
    afisare();
    citireLant();
    verificareLantElementar();
    return 0;
}
