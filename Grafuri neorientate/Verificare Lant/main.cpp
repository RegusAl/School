#include <iostream>
#include <fstream>

using namespace std;

ifstream f("matrice.in");
int v[200], a[100][100], k, n;

void citire()
{
    f>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        f>>a[i][j];
}

void citireLant()
{
    f>>k;
    for(int i=1;i<=k;i++)
        f>>v[i];
}

int verificareLant()
{
    bool ok=1;
    for(int i=1;i<=k-1;i++)
    {
        if(a[v[i]][v[i+1]]==0)
            ok=false;
    }
    return ok;
}


int main()
{
    citire();
    citireLant();
    if(verificareLant()==1)
        cout<<"Este lant";
    else
        cout<<"Nu este lant";
    return 0;
}
