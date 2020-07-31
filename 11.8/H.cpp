#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 35;
const int MAXQ = 3010000;

int Q, n, w[MAXN], dp[MAXQ];
bool vaild[MAXN];
double q;

void init()
{
    memset(vaild, 0, sizeof(vaild));
    memset(dp, 0, sizeof(dp));
}

int main()
{
    int tmp_num;
    double tmp_price, tmp_sum, type_sum[3];
    char tmp_type;
    // cin >> q >> n;
    scanf("%lf%d", &q, &n);
    while (n != 0)
    {
        Q = (int)(q * 100.0);
        init();
        for (int i = 1; i <= n; i++)
        {
            tmp_sum = 0.0;
            for (int j = 0; j < 3; j++)
                type_sum[j] = 0.0;
            // cin >> tmp_num;
            scanf("%d", &tmp_num);
            while (tmp_num--)
            {
                getchar();
                tmp_type = getchar();
                // cout << "--" << tmp_type << endl;
                getchar();
                // cin >> tmp_price;
                scanf("%lf", &tmp_price);
                tmp_sum += tmp_price;
                if (tmp_type > 'C' || tmp_type < 'A' || tmp_price > 600)
                    vaild[i] = true; //发票不可报销
                else
                    type_sum[tmp_type - 'A'] += tmp_price;
            }
            for (int j = 0; j < 3; j++)
                if (type_sum[j] > 600)
                {
                    vaild[i] = true;
                    break;
                }
            if (tmp_sum > 1000)
                vaild[i] = true;
            if (!vaild[i])
                w[i] = (int)(100 * tmp_sum + 0.5);
            // cout << tmp_sum << "--" << w[i] << endl;
        }
        for (int i = 1; i <= n; i++)
            for (int v = Q; v >= w[i]; v--)
                if (!vaild[i] && dp[v] < dp[v - w[i]] + w[i])
                    dp[v] = dp[v - w[i]] + w[i];
        int ans = 0;
        for (int i = 0; i <= Q; i++)
            if (ans < dp[i])
                ans = dp[i];
        // cout << ans << endl;
        printf("%.2lf\n", 0.01 * ans);
        // cin >> q >> n;
        scanf("%lf%d", &q, &n);
    }
    return 0;
}