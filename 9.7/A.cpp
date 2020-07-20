#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#define ll long long

using namespace std;

int n;
priority_queue<ll, vector<ll>, greater<ll>> q;
ll a, ans = 0;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a);
        q.push(a);
    }
    while (q.size() != 1)
    {
        a = q.top(), q.pop();
        a += q.top(), q.pop();
        ans += a;
        q.push(a);
    }
    cout << ans << endl;
    return 0;
}