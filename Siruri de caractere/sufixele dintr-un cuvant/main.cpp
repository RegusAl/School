#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char a[100], b[100];
    cin.getline(a, 100);
    cin.getline(b, 100);
    int x = strlen(a) - 1;
    int y = strlen(b) - 1;
    while(a[x] == b[y])
    {
        x --;
        y --;
    }
    cout<<a+x+1;
    return 0;
}
