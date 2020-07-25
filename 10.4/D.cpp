#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <set>

#define INF 0x3f3f3f3f
#define MAXV 1005
using namespace std;

struct node
{
    int v, dis;
    node() {}
    node(int _v, int _d) : v(_v), dis(_d) {}
};

int n, m, s, t;
vector<node> adj[MAXV];
bool inq[MAXV];
int d[MAXV];
set<int> pre[MAXV]; //前驱

bool spfa(int s)
{
    memset(inq, false, sizeof(inq));
    fill(d, d + MAXV, INF);
    for (int i = 0; i < MAXV; i++)
    {
        pre[i].clear();
    }
    queue<int> q;
    q.push(s);
    inq[s] = true;
    d[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int j = 0; j < adj[u].size(); j++)
        {
            int v = adj[u][j].v;
            int dis = adj[u][j].dis;
            if (d[u] + dis < d[v])
            {
                d[v] = d[u] + dis;
                pre[v].clear();
                pre[v].insert(u);
                if (!inq[v])
                {
                    q.push(v);
                    inq[v] = true;
                }
            }
            else if (d[u] + dis == d[v])
            {
                pre[v].insert(u);
            }
        }
    }
    return true;
}

int main()
{
    int a, b, w;
    while (cin >> n >> m >> s >> t)
    {
        for (int i = 0; i < MAXV; i++)
        {
            adj[i].clear();
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &a, &b, &w);
            adj[a].push_back(node(b, w));
            adj[b].push_back(node(a, w));
        }
        spfa(s);
        if (d[t] != INF)
        {
            printf("%d\n", d[t]);
            stack<int> v;
            for (int i = t; i != s; i = *(pre[i].begin()))
            {
                v.push(i);
            }
            v.push(s);
            while (!v.empty())
            {
                printf("%d ", v.top());
                v.pop();
            }
            printf("\n");
        }
        else
            printf("can't arrive\n");
    }
    return 0;
}