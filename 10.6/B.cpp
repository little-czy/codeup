#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define MAXV 505
using namespace std;

int n, m;
vector<int> g[MAXV], output;
int inDegree[MAXV];

void init()
{
    output.clear();
    for (int i = 0; i < MAXV; i++)
    {
        g[i].clear();
        inDegree[i] = 0;
    }
}

void toPologicalSort()
{
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i++)
        if (inDegree[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int u = q.top();
        output.push_back(u);
        q.pop();
        for (int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i];
            inDegree[v]--;
            if (inDegree[v] == 0)
                q.push(v);
        }
    }
}

int main()
{
    int a, b;
    cin >> n >> m;
    while (n && m)
    {
        init();
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            g[a].push_back(b);
            inDegree[b]++;
        }
        toPologicalSort();
        cout << output[0];
        for (int i = 1; i < output.size(); i++)
        {
            cout << " " << output[i];
        }
        cout << endl;
        cin >> n >> m;
    }
    return 0;
}