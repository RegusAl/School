#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("date.in");

struct nod
{
    int inf;
    nod *st;
    nod *dr;
};
nod *r;
int x;

void inserare(int nr)
{
    nod *n1, *n2, *n3;
    n1 = new nod;
    n1 -> inf = nr;
    n1 -> st = NULL;
    n1 -> dr = NULL;
    if(r==NULL)
    {
        r = n1;
    }
    else
    {
        n2 = r;
        while(n2!=NULL)
        {
            if(nr<n2->inf)
            {
                n3=n2;
                n2=n2->st;
            }
            else
            {
                n3=n2;
                n2=n2->dr;
            }
        }
        if(nr<n3->inf)
        {
            n3->st=n1;
        }
        else
        {
            n3->dr=n1;
        }
    }
}

void inordine(nod *r)
{
    if(r!=NULL)
    {
        inordine(r->st);
        cout<<r->inf<<" ";
        inordine(r->dr);
    }
}

int main()
{
    while(fin>>x)
        inserare(x);
    inordine(r);
    return 0;
}
