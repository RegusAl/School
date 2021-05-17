#include <iostream>
#include <string.h>

using namespace std;

char a[100], b[100];
char vocale[6] = "aeiou";

int main()
{
    cin.getline(a, 100);
    for(int i=0; i<strlen(vocale); i++)
    {
        strcpy(b, a);
        int j = 0;
        while(j<strlen(b))
        {
            if(b[j]==vocale[i])
            {
                strcpy(b+j, b+j+1);
            }
            else
            {
                j++;
            }
        }
        if(strlen(a)!=strlen(b))
            cout<<vocale[i]<<" = "<<b<<endl;
    }
    return 0;
}
