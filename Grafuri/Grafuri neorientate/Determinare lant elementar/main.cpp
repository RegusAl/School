#include <iostream>
#include <fstream>

using namespace std;

ifstream f("matrice.in");

int v[200], a[100][100], n, k;

void citire()
{
    f>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            f>>a[i][j];
}

void citireLant()
{
    f>>k;
    for(int i=1; i<=k; i++)
        f>>v[i];
}

int verificareLant()
{
    int ok=1;
    f>>k;
    for(int i=1; i<=k-1; i++)
    {
        if(a[v[i]][v[i+1]]==0)
            ok=0;
    }
    return ok;
}

int verificareLantElementar()
{
    int ok2=1;
    for(int i=1; i<=k-1; i++)
        for(int j=i+1; j<=k; j++)
            if(v[i]==v[j])
                ok2=0;
    return ok2;


}

int main()
{
    citire();
    citireLant();
    if(verificareLant()==1)
    {
        cout<<"Este lant"<<endl;
        if(verificareLantElementar()==1)
            cout<<"Este lant elementar"<<endl;
        else
            cout<<"Nu este lant elementar"<<endl;
    }
    else
        cout<<"Nu este lant";
    return 0;
}
