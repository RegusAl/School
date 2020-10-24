#include <iostream>

using namespace std;

int a[100][100], n, m, k;

//citirea arcelor
void citire()
{
    int i, j;
    cout<<"Numarul de noduri este: ";
    cin>>n;
    cout<<"Numarul de arce este: ";
    cin>>m;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            a[i][j]=0;
        }
    for(k=1; k<=m; k++)
    {
        cout<<"Muchia "<<k<<" este: ";
        cin>>i>>j;
        a[i][j]=1;
    }
}

//afisarea matricii de adiacenta
void afisare()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

//functia pentru grad exterior (x = +d(x))
int grad_Exterior(int x)
{
    int nr=0;
    for(int j=1; j<=n; j++)
    {
        if(a[x][j]==1)
            nr++;
    }
    return nr;
}

//functia pentru grad interior (y = -d(y))
int grad_Interior(int y)
{
    int nr=0;
    for(int i=1; i<=n; i++)
    {
        if(a[i][y]==1)
            nr++;
    }
    return nr;
}

//functia pentru a arata succesorii nodului "s"
void succesori(int s)
{
    for(int j=1; j<=n; j++)
    {
        if(a[s][j]==1)
            cout<<j<<" ";
    }
}

//functia pentru a arata predecesorii nodului "p"
void predecesori(int p)
{
    for(int i=1; i<=n; i++)
    {
        if(a[i][p]==1)
            cout<<i<<" ";
    }
}

//functia ce arata multimea arcelor ce ies din nodul "a_out"
void multimeaArcelor_Out(int a_out)
{
    for(int j=1; j<=n; j++)
    {
        if(a[a_out][j]==1)
            cout<<"("<<a_out<<","<<j<<")"<<" ";
    }
}

//functia ce arata multimea arcelor ce intra in nodul "a_in"
void multimeaArcelor_In(int a_in)
{
    for(int i=1; i<=n; i++)
    {
        if(a[i][a_in]==1)
            cout<<"("<<i<<","<<a_in<<")"<<" ";
    }
}

//functia "main"
int main()
{
    int x, y, s, p, a_out, a_in;
    citire();
    afisare();
    cout<<endl;
    cout<<"\n";
    cout<<"Dati nodul pentru care vreti sa aratati gradul exterior: ";
    cin>>x;
    cout<<"Gradul exterior al nodului "<<x<<" este: ";
    cout<<grad_Exterior(x);
    cout<<endl;
    cout<<"\n";
    cout<<"Dati nodul pentru care vreti sa aratati gradul interior: ";
    cin>>y;
    cout<<"Gradul interior al nodului "<<y<<" este: ";
    cout<<grad_Interior(y);
    cout<<endl;
    cout<<"\n";
    cout<<"Dati nodul pentru care vreti sa aratati multimea succesorilor: ";
    cin>>s;
    cout<<"Multimea succesorilor nodului "<<s<<" este: ";
    succesori(s);
    cout<<endl;
    cout<<"\n";
    cout<<"Dati nodul pentru care vreti sa aratati multimea predecesorilor: ";
    cin>>p;
    cout<<"Multimea predecesorilor nodului "<<p<<" este: ";
    predecesori(p);
    cout<<endl;
    cout<<"\n";
    cout<<"Dati nodul pentru care vreti sa aratati multimea arcelor ce ies: ";
    cin>>a_out;
    cout<<"Multimea arcelor ce ies este: ";
    multimeaArcelor_Out(a_out);
    cout<<endl;
    cout<<"\n";
    cout<<"Dati nodul pentru care vreti sa aratati multimea arcelor ce intra: ";
    cin>>a_in;
    cout<<"Multimea arcelor ce intra este: ";
    multimeaArcelor_In(a_in);
    cout<<endl;
    cout<<"\n";
    return 0;
}
