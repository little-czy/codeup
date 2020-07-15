#include <iostream>
#include <algorithm>

using namespace std;

int n, r;
int a[22];
bool flag[22] = {false};

void prem(int index)
{
    if (index == r)
    {
        printf("%d", a[0]);
        for (int i = 1; i < r; i++)
            printf(" %d", a[i]);
        printf("\n");
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (flag[i] || (index > 0 && a[index - 1] > i))
                continue;
            a[index] = i;
            flag[i] = true;
            prem(index + 1);
            flag[i] = false;
        }
    }
}

int main()
{
    while (cin >> n >> r)
    {
        prem(0);
    }
    return 0;
}