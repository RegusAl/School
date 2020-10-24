#include <iostream>

using namespace std;

int a[100][100], n, m, k;

void citire()
{
    int i, j;
    cout<<"Numarul de noduri este: "<<endl;
    cin>>n;
    cout<<"Numarul de arce este: "<<endl;
    cin>>m;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            a[i][j]=0;
        }
    for(k=1; k<=m; k++)
    {
        cout<<"Muchia "<<k<<" este: ";
        cin>>i>>j;
        a[i][j]=1;
    }
}

void afisare()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    citire();
    afisare();
    return 0;
}
