#include <iostream>

using namespace std;

int n, a[10][10];

void citire()
{
    cout<<"Dati numarul de varfuri: ";
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
    {
    cout<<"Exista muchia ("<<i<<","<<j<<") ? ";
    cin>>a[i][j];
    a[j][i]=a[i][j];
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
    cout<<endl;
    cout<<"Matricea de adiacenta este: "<<endl;
    afisare();
    cout<<endl;
    return 0;
}
