#include <iostream>

using namespace std;

int n, regine[10], ok = 0, p[10], contor = 0;

void afis()
{
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
            if(regine[j] == i)
            {cout << "* ";}
            else
            {cout << "- ";}
        cout << endl;
    }
    contor++;
}
void back(int coloana)
{
    for(int i = 1 ; i <= n && contor == 0; i++)
    {
        if(!p[i])
        {
            ok = 0;
            regine[coloana] = i;
            p[i] = 1;
            for(int j = 1 ; j < coloana; j++)
                if((coloana - j) == (regine[coloana] - regine[j]))
                ok = 1;
            if(coloana == n && ok == 0)
                afis();
            else if(ok == 0)
                back(coloana + 1);
                p[i] = 0;
        }
    }
}
int main()
{
    cin >> n;
    back(1);
    return 0;
}
