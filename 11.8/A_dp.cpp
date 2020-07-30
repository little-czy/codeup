#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

const int maxn = 5000010;

string s;
int n, a[maxn];
int sum, dp[maxn], total;

bool vaild(string &s)
{
    for (int i = 0; i < s.length(); i++)
        if ((s[i] > '9' || s[i] < '0') && s[i] != ' ')
            return false;
    return true;
}

void deal()
{
    int pos = 0, begin = 0;
    n = sum = 0;
    while (((pos = s.find(" ", pos)) != string::npos))
    {
        a[n] = atoi(s.substr(begin, pos - begin).c_str());
        sum += a[n++];
        begin = ++pos;
    }
    a[n] = atoi(s.substr(begin).c_str());
    sum += a[n++];
    total = sum;
    sum >>= 1;
    // cout << sum << endl;
}

void init()
{
    memset(dp, 0, sizeof(dp));
}

int main()
{
    while (getline(cin, s))
    {
        if (!vaild(s))
        {
            cout << "ERROR" << endl;
            continue;
        }
        deal(); //将读取的内容划分到数组
        init();
        for (int i = 0; i < n; i++)
        {
            for (int v = sum; v >= a[i]; v--)
            {
                dp[v] = max(dp[v], dp[v - a[i]] + a[i]);
            }
        }
        int ans = 0;
        for (int i = 0; i <= sum; i++)
        {
            ans = max(dp[i], ans);
        }
        cout << total - ans << " " << ans << endl;
    }
    return 0;
}