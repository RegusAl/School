#include <iostream>

using namespace std;

int main() {
  char s[10];
  cout<<"Dati un cuvant: ";
  cin>>s;
  int i=0;
  while(s[i]!='\0') {
    cout<<s[i]<<" ";
    i++;
  }
  cout<<"\nCuvantul are "<<i<<" litere.";
  return 0;
}
