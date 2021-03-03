//Combinari
#include <iostream>

using namespace std;

int n, m, k, st[100];

void tipar(int p)
{
    for(int i=1; i<=m; i++)
        cout<<st[i]<<" ";
    cout<<endl;
}

int valid(int p)
{
    int i, ok=1;
    for(i=1; i<p; i++)
    {
        if(st[i]==st[p])
            ok=0;
    }
    return ok;
}

void backtracking(int p)
{
    for(int i=st[p-1]+1; i<=n; i++)
    {
        st[p]=i;
        if(valid(p))
        {
            if(p==m)
                tipar(p);
            else
                backtracking(p+1);
        }
    }
}

int main()
{
    cin>>n>>m;
    backtracking(1);
    return 0;
}
