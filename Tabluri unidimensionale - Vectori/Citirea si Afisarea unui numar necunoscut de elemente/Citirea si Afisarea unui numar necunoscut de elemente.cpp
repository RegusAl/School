#include <iostream>

using namespace std;

int main ()
{
  int k, v[101], i = 0;
  cin>>k;
  while(k)
  {
    v[i++] = k;
    cin>>k;
  }
  int nr = i;
  for(int i = 0; i < nr; i++)
  {
    cout<<v[i]<<" ";
  }
  return 0;
}
