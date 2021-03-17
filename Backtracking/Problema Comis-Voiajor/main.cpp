#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int n, st[10], matrice[50][50], start;

void citireMatrice()
{
  ifstream cin("matrice.txt");
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
      cin>>matrice[i][j];
  }
}

void afisareMatrice()
{
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
      cout<<matrice[i][j]<<" ";
    cout<<endl;
  }
}

void tipar(int p)
{
    for(int i=1; i<=n; i++)
        cout<<st[i]<<" ";
        cout<<st[0];
    cout<<endl;
    exit(EXIT_SUCCESS);
}

int valid(int p)
{
    int i, ok=1;
    for(i=1; i<p; i++)
    {
        if(st[i]==st[p])
            ok=0;
        if(matrice[st[p]][st[p-1]]==0)
          {
            ok=0;
          }
    }
    return ok;
}

void backtracking(int p)
{
    for(int i=1; i<=n; i++)
    {
        st[p]=i;
        if(valid(p))
        {
            if(p==n && matrice[st[p]][start])
                tipar(p);
            else
                backtracking(p+1);
        }
    }
}

int main()
{
  citireMatrice();
  afisareMatrice();
  cout<<"Dati nodul de start: ";
  cin>>start;
  st[0] = start;
  backtracking(1);
}
