#include <iostream>
#include <fstream>

using namespace std;

int n, c[20][20], m, viz[20], ct, k;
//ct=costul
void citire()
{
    ifstream f("graf.txt");
    f>>n>>m;
    int x, y, z;
    for(int i=1; i<=m; i++)
    {
        f>>x>>y>>z;
        c[x][y]=c[y][x]=z;
    }
    f.close();
}

int minim(int x)
{
    int i, min; //min = minimul pe linia x
    for(i=1; i<=n; i++) //initializam min cu primul cost > 0 de pe linia x
        if(c[x][i] > 0)
        {
            min=c[x][i];
            break;
        }
    for(i=1; i<=n; i++) //identific costul minim pe linia x
        if(c[x][i]>0 && c[x][i] < min)
            min=c[x][i];
    return min;
}


int adaugare(int i, int x)  //creez APM //i=nodul //x=costul
{
    int j;
    for(j=1; j<=n; j++)//caut nodul avand costul cel mic [pt  a l adauga]
        if(c[i][j] == x)
        {
            if(viz[j] == 0) //verific daca este vizitat - daca a fost deja adaugat
            {
                ct=ct+c[i][j]; //adaug costul nodului de adaugat
                c[i][j]=c[j][i]=-1; //il resetez in matrice ca fiind pus in APM
                viz[j]=1; //il marchez ca fiind vizitat
                k++; //il numar intre nodurile adaugate
                break; //ma opresc daca l-am gasit fara sa parcurg toate nodurile de pe linie
            }
            else
                c[i][j]=c[j][i]=0; // il resetez la 0 fiindca e adaugat deja
        }                           //ca sa nu mai iau odata muchia respectiva
    return j; //returnez nodul
}


void prim()
{
    int i=1, j=1, min1=0, min2=0;  //muchia (i,j)
    viz[1]=1, k++;
    while(k < n)  //compar 2 cate 2 [i vs.j] nodurile de adagat pt a vedea care are costul mai mic
    {
        min1=minim(i); //costul minim al primei muchii evaluate
        min2=minim(j);//costul minim al celei de-a doua muchii evaluate
        if(min1<min2)
        {
            if(min1 == 0)
                i=adaugare(j, min2); //daca i este parcurs il adaug pe j
            else
                j=adaugare(i, min1); //altfel il adaug pe i
        }
        else
        {
            if(min2 == 0)
                j=adaugare(i, min1);
            else
                i=adaugare(j, min2);
        }
    }
}


int main()
{
    int i, j;
    citire();
    prim();
    ofstream g("apm.txt");
    g<<ct<<endl;
    for(i=1; i<n; i++)
        for(j=i+1; j<=n; j++)
            if(c[i][j] == -1)
                g<<i<<' '<<j<<endl;
    g.close();
    return 0;
}
