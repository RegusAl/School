#include <iostream>
#include <fstream>

using namespace std;

int a[100][100], n;



void citire()
{
    ifstream f("matrice.in");
    f>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            f>>a[i][j];
    f.close();
}

void afisare()
{
    cout<<"Matricea de adiacenta este: "<<endl;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

//parcurgerea in adancime/inaltime
int Viz[50]= {0};
void DF(int x)
{
    Viz[x]=1;
    cout<<x<<" ";
    for(int i=1; i<=n; i++)
    {
        if(a[x][i]==1 && Viz[i]==0)
            DF(i);
    }
}

//parcurgerea in latime
void BF(int x)
{
    int C[50]= {0}, Viz[50]= {0}, ps, pi;
    ps=1;
    pi=1;
    C[pi]=x;
    Viz[x]=1;
    while(ps<=pi)
    {
        x=C[ps];
        for(int i=1; i<=n; i++)
            if(a[x][i]==1 && Viz[i]==0)
            {
                pi++;
                C[pi]=i;
                Viz[i]=1;
            }
        ps++;
    }
    for(int i=1; i<=n; i++)
        cout<<C[i]<<" ";
}

int main()
{
    citire();
    afisare();
    cout<<endl;
    int k;
    cout<<"Dati varful pentru care vreti sa aflati parcurgerile: ";
    cin>>k;
    cout<<endl;
    cout<<"DF("<<k<<") = ";
    DF(k);
    cout<<endl;
    cout<<"BF("<<k<<") = ";
    BF(k);

    return 0;
}
