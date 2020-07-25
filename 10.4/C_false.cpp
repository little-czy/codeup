#include <iostream>
#include <algorithm>
#include <cstring>

#define MAXN 105
#define MAXM 505
#define INF 0x3f3f3f3f

using namespace std;

int n, m;
int g[MAXN][MAXN];
bool vis[MAXN] = {false};
bool d[MAXN][MAXM];

bool is_less(bool *a, bool *b)
{
    for (int i = MAXM - 3; i >= 0; i--)
    {
        if (a[i] && !b[i])
            return false;
        if (!a[i] && b[i])
            return true;
    }
    return false;
}

bool is_less(int a, bool *b)
{
    int j = 0;
    for (int i = MAXM - 3; i >= 0; i--)
    {
        if (b[i])
        {
            j = i;
            break;
        }
    }
    return a < j;
}

int to_num(bool *a)
{
    int j = 0;
    for (int i = MAXM - 3; i >= 0; i--)
    {
        if (a[i])
        {
            j = i;
            break;
        }
    }
    for (; j >= 0; j--)
    {
        printf("%d", a[j]);
    }
    printf("\n");
    return 0;
}

void dijkstra(int s)
{
    fill(d[0], d[0] + MAXN * MAXM, true);
    for (int i = 0; i < MAXM; i++) //设置起点到起点距离为0
        d[s][i] = false;

    for (int i = 0; i < n; i++)
    {
        int u = -1;
        bool MIN[MAXM] = {true};
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && is_less(d[j], MIN))
            {
                u = j;
                memcpy(MIN, d[j], sizeof(MIN));
            }
        }
        if (u == -1)
            return;
        vis[u] = true;
        for (int v = 0; v < n; v++)
        {
            if (!vis[v] && g[u][v] != INF)
            {
                if (is_less(d[u], d[v]))
                {
                    if (is_less(g[u][v], d[v]))
                    {
                        memcpy(d[v], d[u], MAXM);
                        d[v][g[u][v]] = true;
                    }
                }
            }
        }
    }
}

int main()
{
    int a, b;
    cin >> n >> m;
    fill(g[0], g[0] + MAXN * MAXN, INF);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        g[a][b] = g[b][a] = i;
    }
    dijkstra(0);
    for (int i = 1; i < n; i++)
    {
        if (d[i][504])
            printf("-1\n");
        else
            to_num(d[i]);
    }

    return 0;
}