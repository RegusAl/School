#include <iostream>

using namespace std;

int main()
{
  int v[101], n, k;
  cout<<"Numarul de elemente: ";
  cin>>n;
  cout<<"Pozitia k: ";
  cin>>k;
  for(int i = 1; i <= n; i++)
  {
    cin>>v[i];
  }
  for(int i = k+1; i <= n; i++)
  {
    v[i-1] = v[i];
  }
  n--;
  for(int i = 1; i<= n; i++)
  {
    cout<<v[i];
  }
  return 0;
}
