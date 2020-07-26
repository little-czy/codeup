#include <iostream>
#include <algorithm>

#define MAXE 105

using namespace std;

struct edge
{
    int u, v;
    int cost;
} e[MAXE];

int n, m, father[MAXE];

bool cmp(edge a, edge b)
{
    return a.cost < b.cost;
}

int findFather(int x)
{
    int a = x;
    while (x != father[x])
    {
        x = father[x];
    }
    while (a != father[a])
    {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

int kruskal()
{
    int ans = 0, edge_num = 0;
    for (int i = 0; i < m; i++)
    {
        father[i] = i;
    }
    sort(e, e + n, cmp);
    for (int i = 0; i < n; i++)
    {
        int fu = findFather(e[i].u);
        int fv = findFather(e[i].v);
        if (fu != fv)
        {
            father[fu] = fv;
            ans += e[i].cost;
            edge_num++;
            if (edge_num == m - 1)
                break;
        }
    }
    if (edge_num == m - 1)
        return ans;
    else
        return -1;
}

int main()
{
    cin >> n >> m;
    while (n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> e[i].u >> e[i].v >> e[i].cost;
        }
        int ans = kruskal();
        if (ans == -1)
            cout << "?" << endl;
        else
            cout << ans << endl;
        cin >> n >> m;
    }
    return 0;
}