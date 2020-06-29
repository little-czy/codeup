#include <iostream>
#include <algorithm>

using namespace std;

struct _node
{
    int l, r;
} node[105];

bool cmp(struct _node x, struct _node y)
{
    return x.r < y.r;
}

int main()
{
    int n;
    int now_r;
    cin >> n;
    while (n != 0)
    {
        int num = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> node[i].l >> node[i].r;
        }
        sort(node, node + n, cmp);
        now_r = node[0].r;
        for (int i = 1; i < n; i++)
        {
            if (node[i].l >= now_r)
            {
                num++;
                now_r = node[i].r;
            }
        }
        cout << num << endl;
        cin >> n;
    }
    return 0;
}