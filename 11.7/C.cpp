#include <iostream>
#include <algorithm>

typedef long long ll;
const ll MAXN = 10005;

using namespace std;

ll v, n;
ll a[30], dp[30][MAXN];

bool cmp(ll x, ll y)
{
    return x < y;
}

void init()
{
    fill(dp[0], dp[0] + 30 * MAXN, -1);
}

ll f(int x, int y)
{
    if (dp[x][y] != -1 || x == 1 || y == 0)
        return dp[x][y];
    if (dp[x - 1][y] == -1)
        dp[x - 1][y] = f(x - 1, y);
    if (y >= a[x] && dp[x][y - a[x]] == -1)
        dp[x][y - a[x]] = f(x, y - a[x]);
    if (y >= a[x])
    {
        dp[x][y] = dp[x - 1][y] + dp[x][y - a[x]];
        return dp[x][y];
    }
    else
    {
        dp[x][y] = dp[x - 1][y];
        return dp[x][y];
    }
}

int main()
{
    while (cin >> v >> n)
    {
        init();
        for (int i = 1; i <= v; i++)
        {
            cin >> a[i];
        }
        sort(a + 1, a + v + 1, cmp);
        //初始化边界
        for (int i = 0; i <= v; i++)
        {
            dp[i][0] = 1;
        }
        if (a[0] == 1)
        {
            for (int i = 1; i <= n; i++)
            {
                dp[1][i] = 1;
            }
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                dp[1][i] = i % a[1] == 0 ? 1 : 0;
            }
        }
        cout << f(v, n) << endl;
    }
    return 0;
}