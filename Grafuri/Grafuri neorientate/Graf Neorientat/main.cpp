#include <iostream>
#include <fstream>

using namespace std;

int a[100][100], n, m, i, j, k, v[100];

//se citesc listele de adiacenta din graf_liste.txt
void citireListeAdiacenta()
{
    ifstream g("graf_liste.txt");
    g>>n;
    g>>m;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            a[i][j]=0;
        }
    for(k=1; k<=m; k++)
    {
        g>>i>>j;
        a[i][j]=1;
        a[j][i]=a[i][j];
    }
    g.close();
}

//se afiseaza matricea de adiacenta corespunzatoare grafului neorientat
void afisareMatriceAdiacenta()
{
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

//se afisaeaza vectorul si afirmatia daca este lant sau nu
int lant()
{
    int ok=1;
    ifstream l("lant.txt");
    l>>k;
    for(i=1; i<=k; i++)
    {
        l>>v[i];
        cout<<v[i]<<" ";
    }
    for(i=1; i<=k-1; i++)
    {
        if(a[v[i]][v[i+1]]==0)
            ok=0;
    }
    return ok;
    l.close();
}

//se afiseaza vectorul si afirmatia daca este lant elementar/neelementar
int lantElementar()
{
    int ok1=1, ok2=1;
    ifstream le("lant_e.txt");
    le>>k;
    for(i=1; i<=k; i++)
    {
        le>>v[i];
    }
    for(i=1; i<=k-1; i++)
    {
        if(a[v[i]][v[i+1]]==0)
            ok1=0;
    }
    for(i=1; i<=k-1; i++)
        for(j=i+1; j<=k; j++)
        {
            if(v[i]==v[j])
                ok2=0;
        }
    if(ok1==0)
    {
        return -1;
    }
    else if(ok1==1 && ok2==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    le.close();
}

//se afiseaza vectorul si afirmatia daca este ciclu sau nu
int ciclu()
{
    int ok1=1, ok2=1;
    ifstream c("ciclu.txt");
    c>>k;
    for(i=1; i<=k; i++)
    {
        c>>v[i];
        cout<<v[i]<<" ";
    }
    for(i=1; i<=k-1; i++)
    {
        if(a[v[i]][v[i+1]]==0)
            ok1=0;
    }
    if(v[1]!=v[k])
        ok2=0;
    if(ok1==1 && ok2==1)
        return 1;
    else
        return 0;
    c.close();
}

//se afiseaza vectorul si afirmatia daca este ciclu elementar sau nu
int cicluElementar()
{
    int ok1=1, ok2=1, ok3=1;
    ifstream ce("ciclu_e.txt");
    ce>>k;
    for(i=1; i<=k; i++)
    {
        ce>>v[i];
    }
    for(i=1; i<=k-1; i++)
    {
        if(a[v[i]][v[i+1]]==0)
            ok1=0;
    }
    if(v[1]!=v[k])
        ok2=0;
    for(i=1; i<=k-1; i++)
        for(j=i+1; j<=k-1; j++)
        {
            if(v[i]==v[j])
                ok3=0;
        }
    if(ok1==1 && ok2==1 && ok3==1)
        return 1;
    else if (ok1==1 && ok2==1 && ok3==0)
        return 0;
    else
        return -1;
    ce.close();
}

//se afiseaza afirmatia daca este ciclu par sau impar
int cicluIP()
{
    int ok1=1, ok2=1, ok3=1;
    ifstream ip("ciclu_ip.txt");
    ip>>k;
    for(i=1; i<=k; i++)
    {
        ip>>v[i];
    }
    for(i=1; i<=k-1; i++)
    {
        if(a[v[i]][v[i+1]]==0)
            ok1=0;
    }
    if(v[1]!=v[k])
    {
        ok2=0;
    }
    if(k%2!=1)
    {
        ok3=0;
    }
    if(ok1==1 && ok2==1 && ok3==1)
        return 1;
    else if (ok1==1 && ok2==1 && ok3==0)
        return 0;
    else
        return -1;
    ip.close();
}

//se afiseaza afirmatia daca este ciclu hamiltonian sau nu
int cicluHamiltonian()
{
    int ok1=1, ok2=1, ok3=1, ok4=1;
    ifstream h("hamiltonian.txt");
    h>>k;
    for(i=1; i<=k; i++)
    {
        h>>v[i];
    }
    for(i=1; i<=k-1; i++)
    {
        if(a[v[i]][v[i+1]]==0)
            ok1=0;
    }
    if(v[1]!=v[k])
    {
        ok2=0;
    }
    for(i=1; i<=k-1; i++)
        for(j=i+1; j<=k-1; j++)
        {
            if(v[i]==v[j])
                ok3=0;
        }
    if(k-1!=n)
    {
        ok4=0;
    }
    if(ok1==1 && ok2==1 && ok3==1 && ok4==1)
        return 1;
    else if(ok1==1 && ok2==1)
        return 0;
    else
        return -1;
    h.close();
}

int main()
{
    //functia de citire a listei de adiacenta
    citireListeAdiacenta();
    cout<<endl;
    //functia pentru afisarea matricii de adiacenta
    cout<<"Matricea de adiacenta este: "<<endl;
    afisareMatriceAdiacenta();
    cout<<endl;
    //functia pentru lant
    if(lant()==1)
    {
        cout<<"Este lant"<<endl;
    }
    else
    {
        cout<<"Nu este lant"<<endl;
    }
    cout<<endl;
    //functia pentru lant elementar
    if(lantElementar()==-1)
    {
        cout<<"Nu este lant"<<endl;
    }
    else if(lantElementar()==1)
    {
        cout<<"Lantul este elementar"<<endl;
    }
    else
    {
        cout<<"Lantul este neelementar"<<endl;
    }
    cout<<endl;
    //functia pentru ciclu
    if(ciclu()==1)
        cout<<"Este ciclu"<<endl;
    else
        cout<<"Nu este ciclu"<<endl;
    cout<<endl;
    //functia pentru cilu elementar
    if(cicluElementar()==1)
        cout<<"Ciclul este elementar"<<endl;
    else if(cicluElementar()==0)
        cout<<"Ciclul este neelementar"<<endl;
    else
        cout<<"Nu este ciclu"<<endl;
    cout<<endl;
    //functia pentru ciclu par/impar
    if(cicluIP()==1)
        cout<<"Ciclul este par"<<endl;
    else if(cicluIP()==0)
        cout<<"Ciclul este impar"<<endl;
    else
        cout<<"Nu este ciclu"<<endl;
    cout<<endl;
    //functia pentru ciclu hamiltonian
    if(cicluHamiltonian()==1)
        cout<<"Ciclul este hamiltonian"<<endl;
    else if(cicluHamiltonian()==0)
        cout<<"Ciclul nu este hamiltonian"<<endl;
    else
        cout<<"Nu este ciclu"<<endl;
    cout<<endl;
    return 0;
}
