#include <iostream>
#include <fstream>
using namespace std;

ifstream f("matrice.in");
int a[100][100],s[50],n;

void citire()
{
    int i,j;
    f>>n;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            f>>a[i][j];
        }
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

void generare_drum()
{
    int i,j,k,poz,gata,L;
    if(a[1][2]==1)
    {
        s[1]=1;
        s[2]=2;
    }
    else
    {
        s[1]=2;
        s[2]=1;
    }
    L=2;
    for(k=3; k<=n; k++)
    {
        if(a[k][s[1]]==1)
        {
            poz=1;
            i=1;
        }
        else
        {
            i=1; gata=0;
            while(i<L && !gata)
            {
                if(a[s[i]][k]==1 && a[k][s[i+1]])
                    gata=1;
                else
                    i++;

            }
            poz=i+1;
        }
        for(j=L; j>=poz; j--)

            s[j+1]=s[j];
            s[poz]=k;
            L++;
    }
}

void afisare_vector()
{
    cout<<endl;
    for(int i=1; i<=n; i++)
        cout<<s[i]<<" ";
}

int main()
{
    citire();
    afisare();
    generare_drum();
    afisare_vector();
    return 0;
}
