#include <iostream>
#include <algorithm>

using namespace std;

long long n, r, ans, cur;
long long a[22], b[22];
bool flag[22] = {false};

bool cmp(long long x, long long y)
{
    return x < y;
}

bool isPrime(long long x)
{
    if (x <= 1)
        return false;
    for (long long i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

void prem(int index)
{
    if (index == r)
    {
        long long sum = a[0];
        for (int i = 1; i < r; i++)
            sum += a[i];
        if (isPrime(sum))
            ans++;
    }
    else
    {
        for (int i = cur + 1; i <= n; i++)
        {
            if (flag[i])
                continue;
            a[index] = b[i];
            int old = cur;
            cur = i;
            flag[i] = true;
            prem(index + 1);
            cur = old;
            flag[i] = false;
        }
    }
}

int main()
{
    while (cin >> n >> r)
    {
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
        }
        sort(b + 1, b + n + 1, cmp);
        prem(0);
        cout << ans << endl;
    }
    return 0;
}