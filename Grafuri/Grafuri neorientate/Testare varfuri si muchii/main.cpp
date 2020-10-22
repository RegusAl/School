#include <iostream>

using namespace std;

int n,m,i,j,a[10][10],d[20];

//citirea
void citire()
{
    int k;
    cout<<"Numarul de varfuri este: "<<endl;
    cin>>n;
    cout<<"Numarul de muchii este: "<<endl;
    cin>>m;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            a[i][j]=0;

    for(k=1; k<=m; k++)
        d[k]=0;

    for(k=1; k<=m; k++)
    {
        cout<<"Muchia "<<k<<" este: "<<endl;
        cin>>i>>j;
        a[i][j]=1;
        a[j][i]=1;
        d[i]++;
        d[j]++;
    }
}

//afisarea gradelor fiecarui varf
void afisare_vector_grade()
{
    cout<<"Vectorul gradelor este:";
    for(i=1; i<=n; i++)
        cout<<d[i]<<" ";
    cout<<endl;
}

//afisarea matricii de adiacenta
void afisare_matrice()
{
    cout<<"Matricea de adiacenta este:";
    cout<<endl;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

//gradul maxim
int grad_max()
{
    int max;
    max=d[1];
    for(i=2; i<=n; i++)
        if(d[i]>max)
            max=d[i];
    return max;
}

//afisarea varfului care are gradul maxim
void afisare_grad_max()
{
    int k;
    cout<<"Varful care are gradul maxim este: "<<endl;
    for(k=1; k<=n; k++)
        if(d[k]==grad_max())
            cout<<k<<" "<<endl;
}

int grad(int x)
{
    int grad=0;
    for(j=1; j<=n; j++)
        if(a[x][j]==1)
            grad++;
    return grad;
}

//afisarea numarului nodurilor izolate
void noduri_izolate()
{
    int nr_i=0;
    for(i=1; i<=n; i++)
        if(grad(i)==0)
            nr_i++;
    cout<<"Numarul nodurilor izolate este: "<<nr_i<<endl;
}

//afisare nodurilor terminale(cu gradul 1)
void noduri_terminale()
{
    int nr_t=0;
    for(i=0;i<=n;i++)
        if(grad(i)==1)
            nr_t++;
    cout<<"Numarul nodurilor terminale este: "<<nr_t<<endl;
}


int main()
{
    citire();
    cout<<endl;
    afisare_vector_grade();
    cout<<endl;
    afisare_matrice();
    cout<<endl;
    cout<<"Gradul maxim este:"<<grad_max();
    cout<<endl;
    afisare_grad_max();
    cout<<endl;
    noduri_izolate();
    cout<<endl;
    noduri_terminale();
    cout<<endl;
    return 0;
}
