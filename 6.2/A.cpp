#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int n, m, k, tmp, l, r, nc, nt;
set<int> st[55];

int main()
{
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &m);
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &tmp);
                st[i].insert(tmp);
            }
        }
        scanf("%d", &m);
        while (m--)
        {
            scanf("%d%d", &l, &r);
            nc = nt = 0;
            for (set<int>::iterator it = st[l].begin(); it != st[l].end(); it++)
            {
                if (st[r].find(*it) != st[r].end())
                {
                    nc++;
                }
            }
            nt = st[l].size() + st[r].size() - nc;
            printf("%.1lf%%\n", 100.0 * nc / nt);
        }
    }
    return 0;
}