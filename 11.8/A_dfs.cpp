#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

const int maxn = 10010;

string s;
int n, a[maxn];
int sum, tmp_sum, res, total;

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
    res = tmp_sum = 0;
}

void dfs(int index)
{
    if (index == n)
        return;
    int old_sum = tmp_sum;
    if (tmp_sum + a[index] <= sum)
    {
        tmp_sum += a[index];
        res = max(res, tmp_sum);
        if (sum == res)
            return;
        dfs(index + 1);
        tmp_sum = old_sum;
    }
    dfs(index + 1);
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
        dfs(0);
        cout << total - res << " " << res << endl;
    }
    return 0;
}