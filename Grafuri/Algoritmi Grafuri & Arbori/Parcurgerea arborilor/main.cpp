#include <iostream>
#include <fstream>

using namespace std;

int n, St[1000], Dr[1000], val[1000], T[1000]; //vectorul de tati

void RSD(int nod) //parcurgere in preordine
{
    if(nod > 0)
    {
        cout<<val[nod]<<" ";
        RSD(St[nod]);
        RSD(Dr[nod]);
    }
}

void SRD(int nod) //parcurgere in inordine
{
    if(nod > 0)
    {
        SRD(St[nod]);
        cout<<val[nod]<<" ";
        SRD(Dr[nod]);
    }
}

void SDR(int nod) //parcurgere in postordine
{
    if(nod > 0)
    {
        SDR(St[nod]);
        SDR(Dr[nod]);
        cout<<val[nod]<<" ";
    }
}

int main()
{
    ifstream cin("parcurgere.in");
    ofstream cout("parcurgere.out");
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> val[i] >> St[i] >> Dr[i];
        T[St[i]] = i;
        T[Dr[i]] = i;
    }

    int aux = 1, rez;
    while(aux > 0)
    {
        if(rez != 0)
            rez = aux;
        aux = T[aux];
    }

    RSD(rez);
    cout<<endl;
    SRD(rez);
    cout<<endl;
    SDR(rez);
    cout<<endl;
    return 0;
}
