#include <iostream>
#include <cstring>
#include <string>

#define lowbit(i) ((i) & (-i))

using namespace std;

const int MAXN = 1000010;

string s;
int a[MAXN], c[MAXN];

void init()
{
    memset(c, 0, sizeof(c));
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
    int pos, begin, i;
    while (getline(cin, s))
    {
        init();
        i = begin = pos = 0;
        while ((pos = s.find(" ", pos)) != string::npos)
        {
            // cout << "--" << pos << endl;
            a[i++] = atoi(s.substr(begin, pos - begin).c_str());
            begin = ++pos;
        }
        a[i++] = atoi(s.substr(begin).c_str());
        // for (int j = 0; j < i; j++)
        // {
        //     cout << a[j] << endl;
        // }
        long long ans = 0;
        for (int j = 0; j < i; j++)
        {
            update(a[j], 1);
            ans += get_sum(i) - get_sum(a[j]);
        }
        cout << ans << endl;
    }
    return 0;
}