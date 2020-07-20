#include <iostream>

using namespace std;

int a, b;
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

int main()
{
    for (int i = 0; i < 4000005; i++)
    {
        father[i] = i;
    }
    while (cin >> a >> b)
    {
        node[a] = true;
        node[b] = true;
        Union(a, b);
    }
    for (int i = 0; i < 4000005; i++)
    {
        if (node[i])
        {
            is_root[findFather(i)] = true;
        }
    }
    int ans = 0;
    for (int i = 1; i <= 4000005; i++)
    {
        if (node[i])
        {
            ans += is_root[i];
        }
    }
    cout << ans << endl;
    return 0;
}