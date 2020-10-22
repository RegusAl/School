#include <iostream>

using namespace std;

int n, i, j, a[100][100];

void citireMatrice()
{
    cout<<"Numarul de varfuri: ";
    cin>>n;
    cout<<"Citeste matricea de adiacenta: "<<endl;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            cin>>a[i][j];
            a[j][i]=a[i][j];
        }
}

void afisareMatrice()
{
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

void verificareGrafNeorientat()
{
    int ok=1;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            if(a[i][i]==0 && a[i][j]==a[j][i] && (a[i][j]==1 || a[i][j]==0))
                ok=1;
            else
                ok=0;

    if(ok==1)
    {
        cout<<"Matricea este un graf neorietat";
    }
    else
    {
        cout<<"Matricea nu este un graf neorientat";
    }

}

int main()
{
    citireMatrice();
    cout<<endl;
    cout<<"Matricea de adiacenta este: "<<endl;
    afisareMatrice();
    cout<<endl;
    verificareGrafNeorientat();

    return 0;
}
