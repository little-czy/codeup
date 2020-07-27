#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>

#define INF 0x3f3f3f3f
using namespace std;

struct Node
{
    int v, w;
    Node(int _v, int _w) : v(_v), w(_w) {}
};

int n, m, c;
bool is_node[30], inq[30];
int inDegree[30], outDegree[30], d[30], pre[30];
string node;
vector<Node> adj[30];

void init()
{
    for (int i = 0; i < 30; i++)
    {
        adj[i].clear();
        inDegree[i] = outDegree[i] = 0;
        pre[0] = -1;
        d[i] = INF;
        inq[i] = is_node[i] = false;
    }
    for (int i = 0; i < node.length(); i++)
    {
        is_node[node[i] - 'a'] = true;
    }
}

void find_be(int &s, int &t)
{
    for (int i = 0; i < 30; i++)
    {
        if (is_node[i] && inDegree[i] == 0)
            s = i;
        if (is_node[i] && outDegree[i] == 0)
            t = i;
    }
}

void spfa(int s)
{
    queue<int> q;
    q.push(s);
    inq[s] = true;
    d[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].v;
            int w = adj[u][i].w;
            if (d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                pre[v] = u;
                if (!inq[v])
                {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
}

void out_path(int s, int t)
{
    stack<int> sta;
    sta.push(t);
    while (pre[t] != s)
    {
        sta.push(pre[t]);
        t = pre[t];
    }
    while (!sta.empty())
    {
        printf("(%c,%c) ", s + 'a', sta.top() + 'a');
        s = sta.top();
        sta.pop();
    }
}

int main()
{
    char a, b;
    int w;
    while (cin >> c)
    {
        while (c--)
        {
            cin >> n >> m;
            cin >> node;
            init();
            for (int i = 0; i < m; i++)
            {
                cin >> a >> b >> w;
                adj[a - 'a'].push_back(Node(b - 'a', -w));
                outDegree[a - 'a']++;
                inDegree[b - 'a']++;
            }
            int s, t;
            find_be(s, t); //找到源点和汇点
            // cout << s << " " << t << endl;
            spfa(s);
            out_path(s, t);
            cout << -d[t] << endl;
        }
    }
    return 0;
}