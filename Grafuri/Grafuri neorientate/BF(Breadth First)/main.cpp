#include <iostream>

using namespace std;

int a[100][100], n;

void citire()
{
    cout<<"Dati numarul de noduri: ";
    cin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin>>a[i][j];
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

void BF(int x)
{
    int Viz[50]= {0}, C[50]= {0}, k=0, pi, ps;
    pi=1;
    ps=1;
    C[pi]=x;
    Viz[x]=1;
    while(ps<=pi)
    {
        k=C[ps];
        for(int i=1; i<=n; i++)
            if(a[k][i]==1 && Viz[i]==0)
            {
                pi++;
                C[pi]=i;
                Viz[i]=1;
            }
        ps++;
    }
    for(int i=1; i<=pi; i++)
        cout<<C[i]<<" ";
}


int main()
{
    citire();
    cout<<"Matricea de adiacenta este: "<<endl;
    cout<<"\n";
    afisare();
    int x;
    cout<<"Dati nodul pentru care vreti sa aflati parcurgerea in latime: ";
    cin>>x;
    cout<<endl;
    cout<<"BF("<<x<<") = ";
    BF(x);
    return 0;
}
