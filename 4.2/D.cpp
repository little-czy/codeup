#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    char s1[10001] = {'\0'}, c;
    int flag[10001] = {0};
    int s2[1000] = {0};
    int i;
    for (i = 0; (c = getchar()) != '\n'; i++)
    {
        s1[i] = c;
    }
    while ((c = getchar()) != '\n')
    {
        s2[c] = 1;
    }
    for (int j = 0; j < i; j++)
    {
        if (s2[s1[j]] == 0)
        {
            cout << s1[j];
        }
    }
    cout << endl;
    return 0;
}