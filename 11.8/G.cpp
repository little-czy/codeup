#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXC = 1005, MAXN = 105;

int c, n;
int cost[MAXN], w[MAXN], dp[MAXC];

void init()
{
    memset(dp, 0, sizeof(dp));
}

int main()
{
    while (cin >> c >> n)
    {
        init();
        for (int i = 1; i <= n; i++)
        {
            cin >> cost[i] >> w[i];
        }
        for (int i = 0; i <= c; i++)
        {
            dp[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = c; j >= cost[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - cost[i]] + w[i]);
            }
        }
        int ans = 0;
        for (int i = 0; i <= c; i++)
        {
            if (dp[i] > ans)
                ans = dp[i];
        }
        cout << ans << endl;
    }
    return 0;
}