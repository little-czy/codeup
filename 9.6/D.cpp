#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

int n, m, a, b;
int father[10000005];
map<int, int> sonOfRoot;

void init()
{
    for (int i = 1; i <= 10000005; i++)
        father[i] = i;
    sonOfRoot.clear();
}

int find_father(int x)
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

void union_father(int x, int y)
{
    int fx = find_father(x);
    int fy = find_father(y);
    if (fx != fy)
        father[fx] = fy;
}

int main()
{
    while (cin >> n)
    {
        if (n == 0)
        {
            cout << 1 << endl;
            continue;
        }
        init();
        int max_person = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &a, &b);
            if (max_person < a)
                max_person = a;
            if (max_person < b)
                max_person = b;
            union_father(a, b);
        }
        map<int, int>::iterator it0;
        for (int i = 1; i <= max_person; i++)
        {
            int ff = find_father(i);
            it0 = sonOfRoot.find(ff);
            if (it0 == sonOfRoot.end())
            {
                sonOfRoot[ff] = 1;
            }
            else
            {
                (it0->second)++;
            }
        }
        int max_son = 0;
        for (map<int, int>::iterator it = sonOfRoot.begin(); it != sonOfRoot.end(); it++)
        {
            if (it->second > max_son)
                max_son = it->second;
        }
        cout << max_son << endl;
    }
    return 0;
}