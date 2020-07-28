#include <iostream>
#include <algorithm>

#define MAXN 1005
#define MAXV 20005
#define INF 0x3f3f3f3f

using namespace std;

int V, n, a[MAXN], dp[MAXN][MAXV];

void init()
{
    fill(dp[0], dp[0] + MAXN * MAXV, INF);
    for (int j = 0; j < MAXV; j++)
    {
        dp[0][j] = j;
    }
}

int main()
{
    while (cin >> V >> n)
    {
        init();
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int v = 0; v < a[i]; v++)
            {
                dp[i][v] = dp[i - 1][v];
            }
            for (int v = a[i]; v <= V; v++)
            {
                dp[i][v] = min(dp[i - 1][v], dp[i - 1][v - a[i]]);
            }
        }
        int ans = INF;
        for (int i = 0; i <= n; i++)
        {
            if (dp[i][V] < ans)
                ans = dp[i][V];
        }
        cout << ans << endl;
    }
    return 0;
}