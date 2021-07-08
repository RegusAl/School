#include <iostream>

using namespace std;

int main ()
{
  int n, v[101];
  cin>>n;
  for(int i = 1; i <= n; i++)
    {
    cin>>v[i];
    }
  for(int i = 1; i <= n; i++)
    {
    cout<<v[i]<<" ";
    }
  return 0;
}
