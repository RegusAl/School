#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char a[100], vocale[6] = "aeiou";
    cin.getline(a, 100);
    char *p = strtok(a, " ");
    while(p!=0)
    {
        if(strchr(vocale, *p) != NULL)
            strrev(p);
        cout<<p<<" ";
        p = strtok(NULL, " ");
    }
    return 0;
}
