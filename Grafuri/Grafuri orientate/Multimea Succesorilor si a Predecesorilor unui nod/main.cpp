#include <iostream>

using namespace std;

int a[100][100], n, m;

//citirea grafului in functie de arce
void citire()
{
    int i, j;
    cout<<"Numarul de noduri: ";
    cin>>n;
    cout<<"Numarul de arce: ";
    cin>>m;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            a[i][j]=0;
        }
    for(int k=1; k<=m; k++)
    {
        cout<<"Arcul "<<k<<" este: ";
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

void succesori(int x)
{
   for(int j=1;j<=n;j++)
   {
       if(a[x][j]==1)
        cout<<j<<" ";

   }
}

void predecesori(int x)
{
    for(int i=1;i<=n;i++)
    {
        if(a[i][x]==1)
            cout<<i<<" ";
    }
}

int main()
{
    int x;
    citire();
    cout<<endl;
    cout<<"Matricea de adiacenta este: ";
    cout<<endl;
    afisare();
    cout<<endl;
    cout<<"Nodul pentru care vreti sa aflati multimile succesorilor si a predecesorilor este: ";
    cin>>x;
    cout<<endl;
    cout<<"Multimea succesorilor nodului "<<x<<" este: ";
    succesori(x);
    cout<<endl;
    cout<<"Multimea predecesorilor nodului "<<x<<" este: ";
    predecesori(x);
    return 0;
}
