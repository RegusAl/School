#include <iostream>

using namespace std;


struct muchie{
    int i,j,cost;
};

int n , m , t[101],cnn;

muchie x[5000], aux;

void sortare()
{
    int k=0, i;
    while(k==0)
    {
        k=1;
        for(i=1;i<=m-1;i++)
        {
            if(x[i].cost>x[i+1].cost)
            {
                aux=x[i];
                x[i]=x[i+1];
                x[i+1]=aux;
                k=0;
            }
        }
    }
}

void kruskall()
{
    cin >> n >> m;

    for(int i = 0 ; i < m ; ++i)
        cin >> x[i].i >> x[i].j >> x[i].cost;

    //sortare tablou x[] după campul cost
    sortare();

    //initializare tati
    for(int i =1 ; i <= n ; i++)
        t[i] = i;
      //determinare APM
    int S = 0, cnt = 0;
    for(int i = 0 ; i < m && cnt < n ; i ++)
        if(t[x[i].i] != t[x[i].j]) // extremitatile fac parte din subrabori diferiti
        {
            S += x[i].cost;
            cout<<x[i].i<<x[i].j;cout<<endl;
            //reunim subarborii
            int ai = t[x[i].i], aj = t[x[i].j];
            for(int j =1 ; j <= n ; ++j)
                if(t[j] == aj)
                    t[j] = ai;
            cout<<endl;
            cout<<ai<<aj<<" ";

        }

    cout<<endl;
    cout<<"Costul minim este: "<< S << "\n";

}
int main()
{
    kruskall();
}
