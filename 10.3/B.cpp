#include <iostream>

using namespace std;

int a, b, n, m;
int father[4000005];
bool is_root[4000005], node[4000005];

int findFather(int x)
{
    int a = x;
    while (x != father[x])
    {
        x = father[x];
    }
    while (a != father[a])
    {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a, int b)
{
    int A = findFather(a);
    int B = findFather(b);
    if (A != B)
        father[A] = B;
}

void init()
{
    for (int i = 0; i < 4000005; i++)
    {
        father[i] = i;
        is_root[i] = false;
    }
}

int main()
{
    while (cin >> n >> m)
    {
        init();
        if (n == 0)
            break;
        while (m--)
        {
            cin >> a >> b;
            Union(a, b);
        }
        for (int i = 1; i <= n; i++)
            is_root[findFather(i)] = true;
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans += is_root[i];
        if (ans == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}