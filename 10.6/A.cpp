#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>

#define MAXV 55
using namespace std;

int n;
vector<int> g[MAXV], output;
int indegree[MAXV];

void init()
{
    output.clear();
    for (int i = 0; i < MAXV; i++)
    {
        g[i].clear();
        indegree[i] = 0;
    }
}

bool toPologicalSort()
{
    int num = 0;
    stack<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int u = q.top();
        output.push_back(u);
        q.pop();
        for (int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i];
            indegree[v]--;
            if (indegree[v] == 0)
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
    int tmp;
    while (cin >> n)
    {
        init();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> tmp;
                if (tmp)
                {
                    g[i].push_back(j);
                    indegree[j]++;
                }
            }
        }
        if (toPologicalSort())
        {
            for (int i = 0; i < output.size(); i++)
                cout << output[i] << " ";
            cout << endl;
        }
        else
            printf("ERROR\n");
    }
    return 0;
}