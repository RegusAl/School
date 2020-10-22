#include <iostream>
#include <fstream>

using namespace std;

void citire1(int a[][100],int &n1, int &m1)
{
    ifstream f("graf.txt");
    f>>n1>>m1;
    for(int i=1; i<=n1; i++)
        for(int j=1; j<=n1; j++)
    f>>a[i][j];
    f.close();
}
void citire2(int b[][100],int &n2, int &m2)
{
    ifstream f("grafprim.txt");
    f>>n2>>m2;
    for(int i=1; i<=n2; i++)
        for(int j=1; j<=n2; j++)
    f>>b[i][j];
    f.close();
}

void grafpartial(int a[][100], int b[][100], int n1, int m1, int n2, int m2)
{
    if(m2<m1)
    {
        int ok1=1;
        for(int i=1; i<=n2; i++)
            if(a[i][i]==1)
                ok1=0;
        int ok2=1;
        for(int i=1; i<=n2; i++)
            for(int j=1; j<=n2; j++)
                if(b[i][j]!=b[j][i])
                    ok2=0;
        if(ok1==1 && ok2==1)
            cout<<"da"<<endl;
        else
            cout<<"nu"<<endl;
    }
}

int main()
{
    int a[100][100], b[100][100], x, y, n, m;
    citire1(a, x, y);
    citire2(b, n, m);
    grafpartial(a, b, x, y, n, m);
    return 0;
}
