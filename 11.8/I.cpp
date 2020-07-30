#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct node
{
    int h, i, t;
} bg[1010];

int n, dp[1010];

bool cmp(node a, node b)
{
    return a.t < b.t;
}

int main()
{
    cin >> n;
    while (n >= 0)
    {
        int maxt = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> bg[i].h >> bg[i].i >> bg[i].t;
            maxt = max(maxt, bg[i].t);
        }
        // cout << maxt << endl;
        sort(bg + 1, bg + n + 1, cmp);
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            for (int v = bg[i].t; v >= bg[i].i; v--)
            {
                dp[v] = max(dp[v], dp[v - bg[i].i] + bg[i].h);
            }
        }
        int ans = 0;
        for (int i = 1; i <= maxt; i++)
        {
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
        cin >> n;
    }
    return 0;
}