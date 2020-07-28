#include <iostream>
#include <vector>

#define MAXV 30
#define INF 0x3f3f3f3f

using namespace std;

struct node
{
    int v;
    int w;
    node(int _v, int _w) : v(_v), w(_w) {}
};

int n, d[MAXV];
bool vis[MAXV];
vector<node> g[MAXV];

void init()
{
    for (int i = 0; i < MAXV; i++)
    {
        d[i] = INF;
        g[i].clear();
        vis[i] = 0;
    }
}

int prim()
{
    d[0] = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && d[j] < MIN)
                u = j, MIN = d[j];
        }
        if (u == -1)
            return ans;
        vis[u] = true;
        ans += d[u];
        for (int j = 0; j < g[u].size(); j++)
        {
            int v = g[u][j].v;
            if (!vis[v] && g[u][j].w < d[v])
                d[v] = g[u][j].w;
        }
    }
    return ans;
}

int main()
{
    char a, b;
    int num, w;
    cin >> n;
    while (n)
    {
        init();
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a >> num;
            for (int j = 0; j < num; j++)
            {
                cin >> b >> w;
                g[a - 'A'].push_back(node(b - 'A', w));
                g[b - 'A'].push_back(node(a - 'A', w));
            }
        }
        cout << prim() << endl;
        cin >> n;
    }
    return 0;
}