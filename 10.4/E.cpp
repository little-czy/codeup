#include <iostream>
#include <vector>
#include <queue>

#define MAXV 1005
#define INF 0x3f3f3f3f

using namespace std;

struct node
{
    int v, w, value;
    node() {}
    node(int _v, int _w, int _val) : v(_v), w(_w), value(_val) {}
};

int n, m;
vector<node> adj[MAXV];
bool inq[MAXV];
int d[MAXV], value[MAXV];

void spfa(int s)
{
    queue<int> q;
    q.push(s);
    inq[s] = true;
    d[s] = 0;
    value[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int j = 0; j < adj[u].size(); j++)
        {
            int v = adj[u][j].v;
            int w = adj[u][j].w;
            int val = adj[u][j].value;
            if (d[u] + w < d[v] || (d[u] + w == d[v] && value[u] + val < value[v]))
            {
                d[v] = d[u] + w;
                value[v] = value[u] + val;
                if (!inq[v])
                {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
}

void init()
{
    for (int i = 0; i < MAXV; i++)
    {
        adj[i].clear();
        inq[i] = false;
        d[i] = INF;
        value[i] = INF;
    }
}

int main()
{
    int u, v, w, _value, s, t;
    cin >> n >> m;
    while (n || m)
    {
        init();
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v >> w >> _value;
            adj[u].push_back(node(v, w, _value));
            adj[v].push_back(node(u, w, _value));
        }
        cin >> s >> t;
        spfa(s);
        cout << d[t] << " " << value[t] << endl;
        cin >> n >> m;
    }
    return 0;
}