#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int n, a[10][10];
char st[10];

void citire()
{
    ifstream f("matrice.txt");
    f>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            f>>a[i][j];
        }
    f.close();
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

void tipar_bkt(int p)
{
  for(int i=1; i<=n; i++)
    cout<<st[i]<<" ";
  cout<<endl;
  /*
  pentru a afisa doar o singura varianta:
  exit(EXIT_SUCCESS);
  */
}

int valid(int p)
{
    for(int i=1;i<p;i++)
    {
      if(st[p]==st[i] && a[i][p]==1)
        return 0;
    }
}

void bkt(int p)
{
  for(char culoare = 'A'; culoare<= 'D'; culoare++)
  {
    st[p]=culoare;
    if(valid(p)!=0)
    {
      if(p==n)
        tipar_bkt(p);
      else
        bkt(p+1);
    }
  }
}

int main()
{
    citire();
    cout<<"Matricea de adiacenta este: "<<endl;
    afisare();
    cout<<endl;
    bkt(1);
    return 0;
}
