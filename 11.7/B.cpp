#include <iostream>
#include <algorithm>

#define MAXM 105
#define MAXT 1005

using namespace std;

int t, m, dp[MAXM][MAXT], v[MAXM], c[MAXM];

int main()
{
    while (cin >> t >> m)
    {
        cin >> t >> m;
        for (int i = 1; i <= m; i++)
        {
            cin >> c[i] >> v[i];
        }
        for (int i = 0; i <= t; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j < c[i]; j++)
            {
                dp[i][j] = dp[i - 1][j];
            }
            for (int j = c[i]; j <= t; j++)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + v[i]);
            }
        }
        int ans = 0;
        for (int i = 1; i <= m; i++)
        {
            if (ans < dp[i][t])
                ans = dp[i][t];
        }
        cout << ans << endl;
    }
    return 0;
}