#include <iostream>

using namespace std;

int n, m, a[100][100], i, j, g[200], k;

void citire()
{
    cout<<"Numarul de varfuri: ";
    cin>>n;
    cout<<"Numarul de muchii: ";
    cin>>m;

    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            a[i][j]=0;
    for( k=1; k<=m; k++)
    {
        g[k]=0;
    }
    for(k=1; k<=m; k++)
    {
        cout<<"Muchia "<<k<<" este: ";
        cin>>i>>j;
        a[i][j]=1;
        a[j][i]=1;
        g[i]++;
        g[j]++;
    }
}

void afisare()
{
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

//afisarea gradului fiecarui varf
void grad()
{
    for(i=1; i<=n; i++)
    {
        cout<<"Gradul varfului "<<i<<" este: ";
        cout<<g[i];
        cout<<endl;
    }
}

int main()
{
    citire();
    cout<<endl;
    cout<<"Matricea de adiacenta este: "<<endl;
    afisare();
    cout<<endl;
    grad();
    return 0;
}
