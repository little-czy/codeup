#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN 500010
#define lowbit(i) ((i) & (-i))

using namespace std;
typedef long long ll;

struct node
{
    ll val;
    int pos;
} tmp[MAXN];

int n, c[MAXN];
int a[MAXN];

bool cmp(node a, node b)
{
    return a.val < b.val;
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

void init()
{
    memset(c, 0, sizeof(c));
}

int main()
{
    scanf("%d", &n);
    while (n != 0)
    {
        init();
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &tmp[i].val);
            tmp[i].pos = i;
        }
        //排序并离散化到int型范围
        sort(tmp, tmp + n, cmp);
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || tmp[i].val != tmp[i - 1].val)
            {
                a[tmp[i].pos] = i + 1;
            }
            else
            {
                a[tmp[i].pos] = a[tmp[i - 1].pos];
            }
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            update(a[i], 1);
            ans += get_sum(n) - get_sum(a[i]);
        }
        // cout << ans << endl;
        printf("%lld\n", ans);
        scanf("%d", &n);
    }
    return 0;
}