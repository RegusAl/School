#include <iostream>
#include <fstream>

using namespace std;

void citire1(int a[][100],int &n1, int &m1)
{
    ifstream f("graf.txt");
    f>>n1>>m1;
    for(int i=1; i<=n1; i++)
        for(int j=1; j<=n1; j++)
            f>>a[i][j];
    f.close();
}

void citire2(int b[][100],int &n2, int &m2)
{
    ifstream f("grafprim.txt");
    f>>n2>>m2;
    for(int i=1; i<=n2; i++)
        for(int j=1; j<=n2; j++)
            f>>b[i][j];
    f.close();
}

void afisare1(int a[100][100],int n1, int m1)
{
    for(int i=1; i<=n1; i++)
    {
        for(int j=1; j<=n1; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

void afisare2(int b[100][100],int n2, int m2)
{
    for(int i=1; i<=n2; i++)
    {
        for(int j=1; j<=n2; j++)
            cout<<b[i][j]<<" ";
        cout<<endl;
    }
}

void verificare_Subgraf(int a[][100], int b[][100], int n1, int m1, int n2, int m2)
{
    int ok=0;
    if(n2<n1 && m2<m1)
    {
        for(int i=1; i<=n2; i++)
            for(int j=1;j<=n2;j++)
            if(b[i][i]==0 && b[i][j]==b[j][i])
            {
                ok=1;
            }
            else
                ok=0;
    }
    if(ok=1)
    {
        cout<<"Graful 2 este subgraful Grafului 1"<<endl;
    } else
    cout<<"Graful 2 nu este subgraful Grafului 1"<<endl;
}

int main()
{
    int x[100][100],y[100][100],n1,m1,n2,m2;
    citire1(x,n1,m1);
    citire2(y,n2,m2);
    cout<<"Matricea de adiacenta a primului graf este: "<<endl;
    afisare1(x,n1,m1);
    cout<<endl;
    cout<<"Matricea de adiacenta a grafului al doilea este: "<<endl;
    afisare2(y,n2,m2);
    cout<<endl;
    verificare_Subgraf(x, y, n1, m1, n2, m2);
    return 0;
}
