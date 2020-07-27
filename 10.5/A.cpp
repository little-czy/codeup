#include <iostream>
#include <vector>

#define MAXV 105
#define INF 0x3f3f3f3f

using namespace std;

struct node
{
    int v, w;
    node(int _v, int _w) : v(_v), w(_w) {}
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
        for (int j = 0; j < g[u].size(); j++)
        {
            int v = g[u][j].v;
            if (!vis[v] && g[u][j].w < d[v])
            {
                d[v] = g[u][j].w;
            }
        }
    }
    return ans;
}

int main()
{
    int a, b, w;
    cin >> n;
    while (n)
    {
        int count = (n * (n - 1)) >> 1;
        init();
        for (int i = 0; i < count; i++)
        {
            cin >> a >> b >> w;
            g[a].push_back(node(b, w));
            g[b].push_back(node(a, w));
        }
        cout << prim() << endl;
        cin >> n;
    }
    return 0;
}