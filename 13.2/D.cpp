#include <iostream>
#include <cstdio>
#include <cstring>

#define lowbit(i) ((i) & (-i))

using namespace std;

const int MAXN = 50010;

int n;
long long sum1[MAXN], sum2[MAXN], c[MAXN], a[MAXN];

void init()
{
    memset(c, 0, sizeof(c));
    memset(sum1, 0, sizeof(sum1));
    memset(sum2, 0, sizeof(sum2));
}

void update(int x, int v)
{
    for (int i = x; i < MAXN; i += lowbit(i))
    {
        c[i] += v;
    }
}

int get_sum(int x)
{
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        sum += c[i];
    }
    return sum;
}

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        // cin >> n;
        if (n == 0)
            break;
        init();
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
            a[i] += 100;
        }
        for (int i = 0; i < n; i++)
        {
            update(a[i], 1);
            sum1[i] = get_sum(a[i] - 1);
            // cout << sum1[i] << endl;
        }
        memset(c, 0, sizeof(c));
        for (int i = n - 1; i >= 0; i--)
        {
            update(a[i], 1);
            sum2[i] = get_sum(a[i] - 1);
            // cout << sum2[i] << endl;
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += sum1[i] * sum2[i];
        }
        cout << ans << endl;
    }
    return 0;
}