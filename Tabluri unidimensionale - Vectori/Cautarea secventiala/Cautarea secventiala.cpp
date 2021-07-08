// Sir Neordonat
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
  for(int i = 1; i <= n; i++)
  {
    if(v[i] == x)

      cout<<"Pozitia este: "<<i<<" ";
  }
  return 0;
}
