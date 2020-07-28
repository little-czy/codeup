#include <iostream>
#include <algorithm>

using namespace std;

int t, m, n;
int a[15][15];

void init()
{
    fill(a[0], a[0] + 15 * 15, -1);
}

int f(int m, int n)
{
    if (a[m][n] != -1)
        return a[m][n];
    if (n == 1)
    {
        a[m][n] = 1;
        return 1;
    }
    if (m == 0)
    {
        a[m][n] = 1;
        return 1;
    }
    if (n > m)
    {
        a[m][n] = f(m, m);
        return a[m][n];
    }
    a[m][n] = f(m, n - 1) + f(m - n, n);
    return a[m][n];
}

int main()
{
    while (cin >> t)
    {
        for (int i = 0; i < t; i++)
        {
            cin >> m >> n;
            init();
            cout << f(m, n) << endl;
        }
    }
    return 0;
}