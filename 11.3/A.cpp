#include <iostream>

#define MAXN 1005

using namespace std;

int n;
int a[MAXN], dp[MAXN];

int main()
{
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            dp[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (a[i] > a[j] && dp[j] + 1 > dp[i])
                    dp[i] = dp[j] + 1;
            }
            ans = ans > dp[i] ? ans : dp[i];
        }
        cout << ans << endl;
    }
    return 0;
}
