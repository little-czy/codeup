#include <iostream>

#include <cstring>

using namespace std;

const int MAXN = 30005;
int t, n, x, y;
int a[MAXN], c[MAXN];
char command[10];

void init()
{
    memset(c, 0, sizeof(c));
}

inline int lowbit(int i)
{
    return i & (-i);
}

void update(int x, int v)
{
    for (int i = x; i <= n; i += lowbit(i))
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
    ios::sync_with_stdio(false); //加快cin的读入速度，但是scanf将会不能用。
    while (cin >> t)
    {
        for (int k = 1; k <= t; k++)
        {
            cin >> n;
            init();
            cout << "Case " << k << ":" << endl;
            for (int i = 1; i <= n; i++)
            {
                cin >> a[i];
                update(i, a[i]);
            }
            cin >> command;
            while (command[0] != 'E')
            {
                cin >> x >> y;
                if (command[0] == 'Q')
                {
                    cout << get_sum(y) - get_sum(x - 1) << endl;
                }
                else if (command[0] == 'A')
                {
                    update(x, y);
                }
                else
                {
                    update(x, -y);
                }
                cin >> command;
            }
        }
    }
    return 0;
}