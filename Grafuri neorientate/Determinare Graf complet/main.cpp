#include <iostream>
#include <fstream>

using namespace std;

ifstream f("matrice.in");

int a[100][100], n;

void citire()
{

    f>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            f>>a[i][j];
}

void grafcomplet()
{
    cout<<endl;
    int ok1=1,ok2=1;
    for(int i=1; i<=n; i++)
        if(a[i][i]==1)
        {
            ok1=0;
            break;
        }

    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
            if(a[i][j]==0)
            {
                ok2=0;
                break;
            }

    if(ok1==1&&ok2==1)
        cout<<"!!Este graf complet";
    else
        cout<<"NU este graf complet";


}

int main()
{

   citire();
   grafcomplet();
    return 0;
}
