#include <iostream>
#include <fstream>

using namespace std;

int a[100][100], n;

void citire()
{
    ifstream f("matrice.txt");
    f>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            f>>a[i][j];
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
    cout<<"Matricea de adiacenta este: "<<endl;
    afisare();
    return 0;
}
