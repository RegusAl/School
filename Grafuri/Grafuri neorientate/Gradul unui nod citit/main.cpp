#include <iostream>
#include <fstream>

using namespace std;

ifstream f("matrice.in");

int a[100][100], n;

void citire()
{
    f>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        f>>a[i][j];
}

void grad()
{
    int x, g=0;
    cout<<"Dati nodul: ";
    cin>>x;

    for(int j=1;j<=n;j++)
        {g=g+a[x][j];}
        cout<<g;

}

int main()
{
    citire();
    grad();
    return 0;
}
