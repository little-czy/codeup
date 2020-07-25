#include <iostream>
#include <cstdio>

#define MAXN 105
#define MAXM 505
#define INF 0x3f3f3f3f

using namespace std;

int n, m;
int father[MAXN], dis[MAXN][MAXN], height[MAXN];

void init()
{
    for (int i = 0; i < n; i++)
    {
        father[i] = i;
        height[i] = 0;
        for (int j = 0; j < n; j++)
        {
            dis[i][j] = 0;
        }
    }
}

int findFather(int x)
{
    // int a = x;
    while (x != father[x])
    {
        x = father[x];
    }
    // while (a != father[a])
    // {
    //     int z = a;
    //     a = father[a];
    //     father[z] = x;
    // }
    return x;
}

void Union(int a, int b)
{
    a = findFather(a);
    b = findFather(b);
    if (a != b)
    {
        if (height[a] < height[b])
            father[a] = b;
        else if (height[a] > height[b])
            father[b] = a;
        else
        {
            father[b] = a;
            height[a]++;
        }
    }
}

int main()
{
    while (cin >> n >> m)
    {
        init();
        int len = 1, a, b;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            if (findFather(a) != findFather(b))
                for (int j = 0; j < n; j++)
                    if (findFather(a) == findFather(j))
                        for (int k = 0; k < n; k++)
                            if (findFather(b) == findFather(k))
                                dis[j][k] = dis[k][j] = (dis[j][a] + len + dis[b][k]) % 100000;
            Union(a, b);
            len = len * 2 % 100000;
        }
        int r = findFather(0);
        for (int i = 1; i < n; i++)
        {
            if (findFather(i) != r)
            {
                dis[0][i] = -1;
            }
            printf("%d\n", dis[0][i]);
        }
    }
    return 0;
}