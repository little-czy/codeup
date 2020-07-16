#include <iostream>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

struct node
{
    char a[2][5];
    int step;
    string s;
};

char a[2][5];
bool vis[88000000];

void bfs()
{
    queue<node> q;
    node now = {{"1234", "8765"}, 0, ""};
    q.push(now);
    vis[atoi(now.a[0]) * 10000 + atoi(now.a[1])] = true;
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        if (!strcmp(now.a[0], a[0]) && !strcmp(now.a[1], a[1]))
        {
            cout << now.step << endl;
            int i;
            for (i = 0; now.s.size() > 60 && i < now.s.size() - 60; i = i + 60)
            {
                cout << now.s.substr(i, 60) << endl;
            }
            cout << now.s.substr(i) << endl;
            return;
        }
        //A操作
        node tmp;
        tmp.step = now.step + 1;
        tmp.s = now.s;
        strcpy(tmp.a[1], now.a[0]);
        strcpy(tmp.a[0], now.a[1]);
        int tmp_i = atoi(tmp.a[0]) * 10000 + atoi(tmp.a[1]);
        if (!vis[tmp_i])
        {
            // cout << tmp_i << endl;
            tmp.s.append("A");
            q.push(tmp);
            vis[tmp_i] = true;
        }
        //B操作
        tmp = now;
        tmp.step++;
        tmp.a[0][0] = now.a[0][3], tmp.a[0][1] = now.a[0][0];
        tmp.a[0][3] = now.a[0][2], tmp.a[0][2] = now.a[0][1];
        tmp.a[1][0] = now.a[1][3], tmp.a[1][1] = now.a[1][0];
        tmp.a[1][3] = now.a[1][2], tmp.a[1][2] = now.a[1][1];
        tmp_i = atoi(tmp.a[0]) * 10000 + atoi(tmp.a[1]);
        if (!vis[tmp_i])
        {
            // cout << tmp_i << endl;
            tmp.s.append("B");
            q.push(tmp);
            vis[tmp_i] = true;
        }
        //C操作
        tmp = now;
        tmp.step++;
        tmp.a[0][1] = now.a[1][1];
        tmp.a[0][2] = now.a[0][1];
        tmp.a[1][1] = now.a[1][2];
        tmp.a[1][2] = now.a[0][2];
        tmp_i = atoi(tmp.a[0]) * 10000 + atoi(tmp.a[1]);
        if (!vis[tmp_i])
        {
            // cout << tmp_i << endl;
            tmp.s.append("C");
            q.push(tmp);
            vis[tmp_i] = true;
        }
    }
}

int main()
{
    a[0][4] = a[1][4] = '\0';
    while (cin >> a[0][0] >> a[0][1] >> a[0][2] >> a[0][3] >> a[1][3] >> a[1][2] >> a[1][1] >> a[1][0])
    {
        memset(vis, 0, sizeof(vis));
        bfs();
    }
    return 0;
}