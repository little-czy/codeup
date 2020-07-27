#include <iostream>
#include <vector>

#define MAXV 105
#define INF 0x3f3f3f3f

using namespace std;

struct node
{
    int v, w;
    bool vaild;
    node(int _v, int _w, bool _vaild) : v(_v), w(_w), vaild(_vaild) {}
};

int n;
vector<node> g[MAXV];
int d[MAXV];
bool vis[MAXV];

void init()
{
    for (int i = 0; i < MAXV; i++)
    {
        d[i] = INF;
        vis[i] = false;
        g[i].clear();
    }
}

void refrush_vis_d(int s)
{
    for (int i = 0; i < g[s].size(); i++)
    {
        int v = g[s][i].v;
        if (!vis[v])
        {
            if (g[s][i].w < d[v])
            {
                d[v] = g[s][i].w;
            }
            if (g[s][i].vaild)
            {
                vis[v] = true;
                refrush_vis_d(v);
            }
        }
    }
}

int prim()
{
    d[1] = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1, MIN = INF;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && d[j] < MIN)
            {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1)
            return ans;
        vis[u] = true;
        ans += d[u];
        refrush_vis_d(u);
    }
    return ans;
}

int main()
{
    int a, b, w;
    bool vaild;
    cin >> n;
    while (n)
    {
        int count = (n * (n - 1)) >> 1;
        init();
        for (int i = 0; i < count; i++)
        {
            cin >> a >> b >> w >> vaild;
            g[a].push_back(node(b, w, vaild));
            g[b].push_back(node(a, w, vaild));
        }
        cout << prim() << endl;
        cin >> n;
    }
    return 0;
}