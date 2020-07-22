#include <iostream>

#define MAXV 55
#define INF 0x3f3f3f3f
using namespace std;

int n, s;
int g[MAXV][MAXV];
bool vis[MAXV] = {false};
int dis[MAXV] = {INF};

void init()
{
    for (int i = 1; i <= n; i++)
    {
        vis[i] = false;
        dis[i] = INF;
    }
}

void dijkstra(int begin)
{
    init();
    dis[begin] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1, MIN = INF;
        for (int j = 1; j <= n; j++)
        {
            if (vis[j] == false && dis[j] < MIN)
            {
                u = j;
                MIN = dis[j];
            }
        }
        if (u == -1)
            return;
        vis[u] = true;
        for (int j = 1; j <= n; j++)
        {
            if (vis[j] == false && g[u][j] != 0 && dis[u] + g[u][j] < dis[j])
            {
                dis[j] = dis[u] + g[u][j];
            }
        }
    }
}

int main()
{
    while (cin >> n >> s)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> g[i][j];
        dijkstra(s + 1);
        for (int i = 1; i <= n; i++)
        {
            if (i == s + 1)
                continue;
            if (dis[i] != INF)
                printf("%d ", dis[i]);
            else
                printf("-1 ");
        }
        printf("\n");
    }
    return 0;
}