#include <iostream>
#include <fstream>

using namespace std;

int a[100][100], n;

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

int grad_OUT(int x)
{
    int nr=0;
    for(int j=1; j<=n; j++)
    {
        if(a[x][j]==1)
            nr++;
    }
    return nr;
}

int grad_IN(int x)
{
    int nr=0;
    for(int i=1; i<=n; i++)
    {
        if(a[i][x]==1)
            nr++;
    }
    return nr;
}

void arce_OUT(int x)
{
    for(int j=1; j<=n; j++)
    {
        if(a[x][j]==1)
            cout<<"("<<x<<","<<j<<")"<<" ";
    }
}

void arce_IN(int x)
{
    for(int i=1; i<=n; i++)
    {
        if(a[i][x]==1)
            cout<<"("<<i<<","<<x<<")"<<" ";
    }
}

void succesori(int x)
{
    for(int j=1; j<=n; j++)
    {
        if(a[x][j]==1)
            cout<<j<<" ";
    }
}

void predecesori(int x)
{
    for(int i=1; i<=n; i++)
    {
        if(a[i][x]==1)
            cout<<i<<" ";
    }
}

int main()
{
    citire();
    cout<<"Matricea de adiacenta este: "<<endl;
    cout<<"\n";
    afisare();
    cout<<endl;
    for(int x=1; x<=n; x++)
    {
        cout<<"Gradul exterior al nodului "<<x<<" este: ";
        cout<<grad_OUT(x);
        cout<<endl;
        cout<<"Gradul interior al nodului "<<x<<" este: ";
        cout<<grad_IN(x);
        cout<<endl;
        cout<<"Multimea arcelor ce ies din "<<x<<" este: ";
        arce_OUT(x);
        cout<<endl;
        cout<<"Multimea arcelor ce intra in "<<x<<" este: ";
        arce_IN(x);
        cout<<endl;
        cout<<"Multimea succesorilor nodului "<<x<<" este: ";
        succesori(x);
        cout<<endl;
        cout<<"Multimea predecesorilor nodului "<<x<<" este: ";
        predecesori(x);
        cout<<endl;
        cout<<"\n";
    }
    return 0;
}
