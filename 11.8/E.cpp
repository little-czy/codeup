#include <iostream>
#include <algorithm>

using namespace std;

int sum[105][105], a[105][105], dp[105], ans;
int n;

void init()
{
    ans = -0x3f3f3f3f;
    fill(sum[0], sum[0] + 105 * 105, 0);
}

int main()
{
    while (cin >> n)
    {
        init();
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        for (int i = 1; i <= n; i++) //计算每列前缀和
            for (int j = 0; j < n; j++)
                sum[i][j] = sum[i - 1][j] + a[i][j];
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                dp[0] = sum[j][0] - sum[i][0];
                for (int k = 1; k < n; k++)
                {
                    int ak = sum[j][k] - sum[i][k];
                    dp[k] = max(ak, dp[k - 1] + ak);
                }
                int ans_t = dp[0];
                for (int k = 1; k < n; k++)
                    if (dp[k] > ans_t)
                        ans_t = dp[k];
                ans = max(ans, ans_t);
            }
        }
        cout << ans << endl;
    }
    return 0;
}