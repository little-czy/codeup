#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m, a, b;
int father[1005];
bool isRoot[1005];

void init()
{
    for (int i = 1; i <= n; i++)
    {
        father[i] = i;
    }
}

int find_father(int x)
{
    int a = x;
    while (x != father[x])
    {
        x = father[x];
    }
    while (a != father[a])
    {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void union_father(int x, int y)
{
    int fx = find_father(x);
    int fy = find_father(y);
    if (fx != fy)
        father[fx] = fy;
}

int main()
{
    cin >> n >> m;
    while (n)
    {
        memset(isRoot, 0, sizeof(isRoot));
        init();
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &a, &b);
            union_father(a, b);
        }
        for (int i = 1; i <= n; i++)
        {
            isRoot[find_father(i)] = true;
            // cout << find_father(i) << endl;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += isRoot[i];
        }
        // cout << ans << endl;
        if (ans == 1 && n == m + 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        cin >> n >> m;
    }
    return 0;
}