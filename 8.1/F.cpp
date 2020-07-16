#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct node
{
    int x, y;
};
int n, m;
int f[30][30];
bool vis[30][30] = {false}, can_arr = false;
int a, b, c, d;
int extre[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
vector<node> line;

bool can(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > m)
        return false;
    if (!f[x][y] || vis[x][y])
        return false;
    return true;
}

void dfs(int x, int y)
{
    if (x == c && y == d)
    {
        for (vector<node>::iterator it = line.begin(); it != line.end(); it++)
        {
            if (it + 1 == line.end())
                printf("(%d,%d)\n", it->x, it->y);
            else
                printf("(%d,%d)->", it->x, it->y);
        }
        can_arr = true;
        return;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            node NO;
            NO.x = x + extre[i][0];
            NO.y = y + extre[i][1];
            if (can(NO.x, NO.y))
            {
                line.push_back(NO);
                vis[NO.x][NO.y] = true;
                dfs(NO.x, NO.y);
                vis[NO.x][NO.y] = false;
                line.pop_back();
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &(f[i][j]));
    scanf("%d%d%d%d", &a, &b, &c, &d);
    node begin;
    begin.x = a;
    begin.y = b;
    line.push_back(begin);
    vis[a][b] = true;
    dfs(a, b);
    if (!can_arr)
        printf("-1\n");
    return 0;
}