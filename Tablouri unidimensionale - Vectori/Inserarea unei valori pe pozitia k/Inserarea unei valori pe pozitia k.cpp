#include <iostream>

using namespace std;

int main()
{
  int v[101], n, k, x;
  cout<<"Numarul de elemente: ";
  cin>>n;
  cout<<"Numarul care vreti sa fie inserat: ";
  cin>>x;
  cout<<"Pozitia k: ";
  cin>>k;
  for(int i = 1; i <= n; i++)
  {
    cout<<"v["<<i<<"] = ";
    cin>>v[i];
  }
  for(int i = n; i >= k; i--)
  {
    v[i+1] = v[i];
  }
  v[k] = x;
  n++;
  cout<<"Vectorul final este: ";
  for(int i = 1; i <= n; i++)
  {
    cout<<v[i]<<" ";
  }
  return 0;
}
