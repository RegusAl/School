#include <iostream>

using namespace std;

int n, m, i, j, a[10][10], k;

void citire()
{
    cout<<"Numarul de varfuri: ";
    cin>>n;
    cout<<"Numarul de muchii: ";
    cin>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        a[i][j]=0;
    for(k=1;k<=m;k++)
    {
        cout<<"Muchia "<<k<<" este: ";
        cin>>i>>j;
        a[i][j]=1;
        a[j][i]=1;
    }
}

void afisare()
{
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    citire();
    cout<<endl;
    cout<<"Matricea de adiacenta este: "<<endl;
    afisare();
    return 0;
}
