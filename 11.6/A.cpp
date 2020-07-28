#include <iostream>
#include <cstring>
#include <vector>

#define MAXV 1010
using namespace std;

struct node
{
    int x, y;
    node(int _x, int _y)
    {
        x = _x < _y ? _x : _y;
        y = _x < _y ? _y : _x;
    }
};

int n, dp[MAXV];
vector<node> v;
vector<int> g[MAXV];

void put(int a, int b)
{
    if (v[a].x < v[b].x && v[a].y < v[b].y)
    {
        g[a].push_back(b);
    }
    else if (v[a].x > v[b].x && v[a].y > v[b].y)
    {
        g[b].push_back(a);
    }
}

int DP(int i)
{
    if (dp[i] > 0)
        return dp[i];
    for (int j = 0; j < g[i].size(); j++)
    {
        int tmp = DP(g[i][j]) + 1;
        if (tmp > dp[i])
            dp[i] = tmp;
    }
    return dp[i];
}

void init()
{
    v.clear();
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < MAXV; i++)
    {
        g[i].clear();
    }
}

int main()
{
    int t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> n;
        init();
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            v.push_back(node(a, b));
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                put(i, j);
            }
        }
        for (int i = 0; i < n; i++)
        {
            DP(i);
        }

        int ans = dp[0];
        for (int i = 1; i < n; i++)
        {
            if (dp[i] > ans)
                ans = dp[i];
        }
        cout << ans + 1 << endl;
    }

    return 0;
}