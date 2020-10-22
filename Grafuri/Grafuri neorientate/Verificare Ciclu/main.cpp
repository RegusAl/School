#include <iostream>
#include <fstream>

using namespace std;

ifstream f("matrice.in");

int v[100], a[100][100], k, n;

void citire()
{
    f>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        f>>a[i][j];
}

void citireCiclu()
{
    f>>k;
    for(int i=1;i<=k;i++)
        f>>v[i];
}

int verificareCiclu()
{
    int ok=1;
    for(int i=1;i<=k-1;i++)
    {
        if(a[v[i]][v[i+1]]==0)
            ok=0;
    }

    if(v[1]!=v[k])
    {
        ok=0;
    }
    return ok;
}

int main()
{
    citire();
    citireCiclu();
    if(verificareCiclu()==1)
        cout<<"Este ciclu";
    else
        cout<<"Nu este ciclu";
    return 0;
}
