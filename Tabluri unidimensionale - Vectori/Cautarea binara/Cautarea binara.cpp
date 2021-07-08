// Sir ordonat
#include <iostream>

using namespace std;

int main()
{
  int v[101], n, x;
  cout<<"Numarul de elemente: ";
  cin>>n;
  cout<<"Numarul cautat: ";
  cin>>x;
  for(int i = 1; i <= n; i++)
  {
    cin>>v[i];
  }
  unsigned c1 = 1, c2 = n, m;
  while(c1 <= c2)
  {
    m = (c1+c2) / 2;
    if(v[m] == x)
    {
      cout<<"Pozitia numarului "<<v[m]<<" este: "<<m;
      break;
    }
    else if(x < v[m])
    {
      c2 = m-1;
    }
    else
    {
      c1 = m+1;
    }
  }
  return 0;
}
