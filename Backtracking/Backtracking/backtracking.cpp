#include <iostream>

using namespace std;

int n, k, st[100];

//functia 'tipar'
void tipar(int p)
{
    for(int i=1; i<=n; i++)
        cout<<st[i]<<" ";
    cout<<endl;
}

//functia 'valid'
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

//functia 'backtracking' - recursiva
void backtracking(int p)
{
    for(int i=1; i<=n; i++)
    {
        st[p]=i;
        if(valid(p))
        {
            if(p==n)
                tipar(p);
            else
                backtracking(p+1);
        }
    }
}

//main
int main()
{
    cin>>n;
    backtracking(1);
    return 0;
}
