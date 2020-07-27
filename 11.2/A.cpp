#include <iostream>

#define MAXN 10005

using namespace std;

int n;
int a[MAXN], dp[MAXN], head[MAXN];

void init()
{
    for (int i = 0; i < MAXN; i++)
    {
        head[i] = 0;
    }
}

int main()
{
    cin >> n;
    while (n)
    {
        bool bigThanZero = false;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] >= 0)
                bigThanZero = true;
        }
        if (!bigThanZero)
        {
            cout << 0 << " " << a[0] << " " << a[n - 1] << endl;
            cin >> n;
            continue;
        }
        dp[0] = a[0];
        head[0] = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i] <= dp[i - 1] + a[i])
            {
                head[i] = head[i - 1];
                dp[i] = dp[i - 1] + a[i];
            }
            else
            {
                head[i] = i;
                dp[i] = a[i];
            }
        }
        int end = 0;
        for (int i = 1; i < n; i++)
        {
            if (dp[i] > dp[end])
                end = i;
        }
        cout << dp[end] << " " << a[head[end]]
             << " " << a[end] << endl;
        cin >> n;
    }
    return 0;
}