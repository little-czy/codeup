#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

struct node
{
    char a[3][4];
    int step;
    node() {}
    node(char b[3][4], int num) { memcpy(a, b, sizeof(a)), step = num; }
};

char a[3][4], b[3][4];
map<int, bool> vis;
node now;

inline void find_zero(int &x, int &y)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (now.a[i][j] == '0')
            {
                x = i, y = j;
                return;
            }
}

void bfs()
{
    queue<node> q;
    int x, y;
    q.push(node(a, 1));
    vis[atoi(a[0]) * 1000000 + atoi(a[1]) * 1000 + atoi(a[2])] = true;
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        if (!strcmp(now.a[0], b[0]) && !strcmp(now.a[1], b[1]) && !strcmp(now.a[2], b[2]))
        {
            cout << now.step << endl;
            return;
        }
        find_zero(x, y);
        // cout << x << " " << y << endl;
        if (x > 0) //0向上移动
        {
            node tmp = now;
            tmp.step++;
            tmp.a[x][y] = tmp.a[x - 1][y];
            tmp.a[x - 1][y] = '0';
            int tmp_i = atoi(tmp.a[0]) * 1000000 + atoi(tmp.a[1]) * 1000 + atoi(tmp.a[2]);
            if (vis.find(tmp_i) == vis.end())
            {
                q.push(tmp);
                vis[tmp_i] = true;
            }
        }
        if (x < 2) //0向下移动
        {
            node tmp = now;
            tmp.step++;
            tmp.a[x][y] = tmp.a[x + 1][y];
            tmp.a[x + 1][y] = '0';
            int tmp_i = atoi(tmp.a[0]) * 1000000 + atoi(tmp.a[1]) * 1000 + atoi(tmp.a[2]);
            if (vis.find(tmp_i) == vis.end())
            {
                q.push(tmp);
                vis[tmp_i] = true;
            }
        }
        if (y > 0) //0向左移动
        {
            node tmp = now;
            tmp.step++;
            tmp.a[x][y] = tmp.a[x][y - 1];
            tmp.a[x][y - 1] = '0';
            int tmp_i = atoi(tmp.a[0]) * 1000000 + atoi(tmp.a[1]) * 1000 + atoi(tmp.a[2]);
            if (vis.find(tmp_i) == vis.end())
            {
                q.push(tmp);
                vis[tmp_i] = true;
            }
        }
        if (y < 2) //0向右移动
        {
            node tmp = now;
            tmp.step++;
            tmp.a[x][y] = tmp.a[x][y + 1];
            tmp.a[x][y + 1] = '0';
            int tmp_i = atoi(tmp.a[0]) * 1000000 + atoi(tmp.a[1]) * 1000 + atoi(tmp.a[2]);
            if (vis.find(tmp_i) == vis.end())
            {
                q.push(tmp);
                vis[tmp_i] = true;
            }
        }
    }
}

int main()
{
    // while (scanf("%c %c %c", &a[0][1], &a[0][2], &a[0][3]))
    // {
    int tmp_num;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> tmp_num;
            a[i][j] = tmp_num + '0';
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> tmp_num;
            b[i][j] = tmp_num + '0';
        }
    }
    a[0][3] = a[1][3] = a[2][3] = '\0';
    b[0][3] = b[1][3] = b[2][3] = '\0';
    bfs();
    // }
    return 0;
}