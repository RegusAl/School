#include <iostream>

using namespace std;

int a[100][100], n, m, k;

//citirea grafului in functie de arce
void citire()
{
    int i, j;
    cout<<"Numarul de noduri: ";
    cin>>n;
    cout<<"Numarul de muchii: ";
    cin>>m;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            a[i][j]=0;
    for(k=1; k<=m; k++)
    {
        cout<<"Muchia "<<k<<" este: ";
        cin>>i>>j;
        a[i][j]=1;
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

int grad_exterior(int x)
{
    int nr=0;
    for(int j=1; j<=n; j++)
        if(a[x][j]==1)
        {
            nr++;
        }
    return nr;
}

int grad_interior(int x)
{
    int nr=0;
    for(int i=1; i<=n; i++)
        if(a[i][x]==1)
        {
            nr++;
        }
    return nr;
}

int main()
{
    int x;
    citire();
    cout<<endl;
    cout<<"Matricea de adiacenta este: "<<endl;
    cout<<"\n";
    afisare();
    cout<<endl;
    cout<<"Dati nodul pentru care vreti sa aflat gradul: ";
    cin>>x;
    cout<<endl;
    //grad exterior
    cout<<"Gradul exterior al nodului "<<x<<" este: ";
    cout<<grad_exterior(x);
    cout<<endl;
    //grad interior
    cout<<"Gradul interior al nodului "<<x<<" este: ";
    cout<<grad_interior(x);

    return 0;
}
