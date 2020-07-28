#include <iostream>

#define MAXN 1005

using namespace std;

int n;
int a[MAXN], dp[MAXN], ans[MAXN];

int main()
{
    cin >> n;
    while (n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            dp[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (a[i] > a[j] && dp[j] + 1 > dp[i])
                    dp[i] = dp[j] + 1;
            }
            ans[i] = dp[i];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i] = 1;
            for (int j = n - 1; j > i; j--)
            {
                if (a[i] > a[j] && dp[j] + 1 > dp[i])
                    dp[i] = dp[j] + 1;
            }
            ans[i] += dp[i] - 1;
        }
        int ans_max = 0;
        for (int i = 0; i < n; i++)
        {
            if (ans_max < ans[i])
                ans_max = ans[i];
        }
        cout << n - ans_max << endl;
        cin >> n;
    }
    return 0;
}
