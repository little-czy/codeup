#include <iostream>
#include <cstdio>
#include <cmath>

#define MAXV 105
#define INF 0x3f3f3f3f

using namespace std;

struct loc
{
    float x, y;
} local[MAXV];

int n;
float d[MAXV];
bool vis[MAXV];

void init()
{
    for (int i = 0; i < MAXV; i++)
    {
        d[i] = INF;
        vis[i] = false;
    }
}

float count_dis(int a, int b)
{
    return sqrt((local[a].x - local[b].x) * (local[a].x - local[b].x) + (local[a].y - local[b].y) * (local[a].y - local[b].y));
}

float prim()
{
    d[0] = 0;
    float ans = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1;
        float MIN = INF;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && d[j] < MIN)
            {
                MIN = d[j];
                u = j;
            }
        }
        if (u == -1)
            return -1;
        vis[u] = true;
        ans += d[u];
        for (int v = 0; v < n; v++)
        {
            if (v != u && !vis[v]) //不连接自己且未访问
            {
                float tmp_dis = count_dis(u, v);
                if (tmp_dis < d[v])
                    d[v] = tmp_dis;
            }
        }
    }
    return ans;
}

int main()
{
    cin >> n;
    while (n)
    {
        init();
        for (int i = 0; i < n; i++)
        {
            cin >> local[i].x >> local[i].y;
        }
        printf("%.2lf\n", prim());
        cin >> n;
    }
    return 0;
}