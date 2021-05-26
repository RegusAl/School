#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char c[256];
    char vocale[6] = "aeiou";
    char consoane[] = "b, c, č, k’, d, f, g, ğ, g’, h, j, l, m, n, p, r, s, ș, t, ț, v, z";
    cin.get(c, 256);
    int nr = 0;
    for(int i=0; i<strlen(c); i++)
    {
        if(strchr(vocale, c[i]) && strchr(consoane, c[i-1]) && strchr(consoane, c[i+1]))
        {
            nr++;
        }

    }
    cout<<nr;

    return 0;
}
