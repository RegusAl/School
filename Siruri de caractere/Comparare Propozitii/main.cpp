#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char a[100], b[100], s[]=" ", c[]="abcdefghijklmnopqrstuvwxyz";
    cin.getline(a,100);
    cin.getline(b,100);
    int nra=1, nrb=1;
    for(int i=1; i<strlen(a); i++)
        if(strchr(s,a[i]))
            if(strchr(c,a[i-1])||strchr(c,a[i]))
                nra++;
    cout<<endl;
    for(int j=1; j<strlen(b); j++)
        if(strchr(s,b[j]))
            if(strchr(c,b[j-1])||strchr(c,b[j]))
                nrb++;

    cout<<endl<<nra<<" "<<nrb<<endl;
    if(nra>nrb)
        cout<<"prima propozitie are mai multe cuvinte";
    else
    {
        if(nrb>nra)
            cout<<"a doua propozitie are mai multe cuvinte";
        else
            cout<<"amandoua au acelasi nr de cuvinte";
    }
    return 0;
}

