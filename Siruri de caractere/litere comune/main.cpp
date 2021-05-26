#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char cuv1[100], cuv2[100], c;
    cin.getline(cuv1, 100);
    cin.getline(cuv2, 100);
    cout<<"literele comune sunt: ";
    for(c='a'; c<='z'; c++)
    {
        int z1 = 0, z2 = 0;
        for(int i=0; i<=strlen(cuv1); i++)
        {
            if(cuv1[i] ==c )
            {
                z1 = 1;
            }
        }
        for(int i=0; i<=strlen(cuv2); i++)
        {
            if(cuv2[i] ==c )
            {
                z2 = 1;
            }
        }
        if(z1 && z2)
        {
            cout<<c<<" ";
        }
    }
    return 0;
}
