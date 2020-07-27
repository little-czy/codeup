#include <iostream>
#include <vector>
#include <queue>

#define MAXV 105

using namespace std;

int n, m;
vector<int> g[MAXV];
int inDegree[MAXV];

void init()
{
    for (int i = 0; i < MAXV; i++)
    {
        g[i].clear();
        inDegree[i] = 0;
    }
}

bool toPologicalSort()
{
    int num = 0;
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (inDegree[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i];
            inDegree[v]--;
            if (inDegree[v] == 0)
                q.push(v);
        }
        num++;
    }
    if (num == n)
        return true;
    else
        return false;
}

int main()
{
    int a, b;
    cin >> n >> m;
    while (n)
    {
        init();
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            g[a].push_back(b);
            inDegree[b]++;
        }
        if (toPologicalSort())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        cin >> n >> m;
    }
    return 0;
}