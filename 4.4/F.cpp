#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int c, n, v, w, p[105];
double cur_p, tmp_p;

bool cmp(int x, int y)
{
    return x < y;
}

int main()
{
    cin >> c;
    while (c--)
    {
        cin >> n >> v >> w;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        sort(p, p + n, cmp);
        if (n == 0 || p[0] > w)
        {
            cout << "0 0.00" << endl;
            continue;
        }
        cur_p = p[0];
        int i = 1;
        for (; i < n; i++)
        {
            tmp_p = (cur_p * i + p[i]) / (i + 1);
            if (tmp_p > w)
                break;
            else
                cur_p = tmp_p;
        }
        printf("%d %.2lf\n", v * i, 0.01 * cur_p);
    }

    return 0;
}