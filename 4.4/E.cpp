#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct E
{
    double j, f, weight;
} node[1010];
int m, n;

bool cmp(E x, E y)
{
    return x.weight > y.weight;
}

int main()
{
    cin >> m >> n;
    while (m != -1)
    {
        double max_jb = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> node[i].j >> node[i].f;
            node[i].weight = node[i].j / node[i].f;
        }
        sort(node, node + n, cmp);
        for (int i = 0; i < n; i++)
        {
            if (m > 0) //还有钱
            {
                if (m > node[i].f) //能买完
                {
                    m -= node[i].f;
                    max_jb += node[i].j;
                }
                else //能买部分
                {
                    max_jb += m * node[i].weight;
                    m = 0;
                    break;
                }
            }
            else
                break;
        }
        printf("%.3lf\n", max_jb);
        cin >> m >> n;
    }
    return 0;
}