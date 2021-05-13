#include <iostream>

using namespace std;

int main() {
  char *p, s[30];
  cout<<"Dati un cuvant: ";
  cin>>s;
  cout<<s<<endl; //cuvantul
  p=s;
  cout<<p<<endl; //pointerul = cuvantul
  p++;
  cout<<p<<endl; //pointerul+1 = cuvantul fara prima litera
  return 0;
}
