#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <string>

using namespace std;

struct node
{
    int a, b;
    string step;
    node() {}
    node(int _a, int _b, string _s) : a(_a), b(_b), step(_s) {}
} now;
bool vis[1005][1005];
int a, b, c;
int na, nb;
char option[6][10] = {"fill A", "fill B", "empty A", "empty B", "pour A B", "pour B A"};

void bfs()
{
    queue<node> q;
    q.push(node(0, 0, ""));
    while (!q.empty())
    {
        now = q.front(), q.pop();
        if (now.b == c)
            return;
        if (now.a < a) //灌满A
        {
            node tmp = now;
            tmp.a = a;
            if (!vis[tmp.a][tmp.b])
            {
                tmp.step.append("0");
                vis[tmp.a][tmp.b] = true;
                q.push(tmp);
            }
        }
        if (now.b < b) //灌满B
        {
            node tmp = now;
            tmp.b = b;
            if (!vis[tmp.a][tmp.b])
            {
                tmp.step.append("1");
                vis[tmp.a][tmp.b] = true;
                q.push(tmp);
            }
        }
        if (now.a > 0) //倒掉A
        {
            node tmp = now;
            tmp.a = 0;
            if (!vis[tmp.a][tmp.b])
            {
                tmp.step.append("2");
                vis[tmp.a][tmp.b] = true;
                q.push(tmp);
            }
        }
        if (now.b > 0) //倒掉B
        {
            node tmp = now;
            tmp.b = 0;
            if (!vis[tmp.a][tmp.b])
            {
                tmp.step.append("3");
                vis[tmp.a][tmp.b] = true;
                q.push(tmp);
            }
        }
        if (now.a > 0 && now.b != b) //从A倒到B
        {
            node tmp = now;
            int b_res = b - now.b; //B可以接收的水量
            if (now.a <= b_res)    //A内的水可以倒完
            {
                tmp.b += tmp.a;
                tmp.a = 0;
            }
            else
            {
                tmp.a -= b_res;
                tmp.b = b;
            }
            if (!vis[tmp.a][tmp.b])
            {
                tmp.step.append("4");
                vis[tmp.a][tmp.b] = true;
                q.push(tmp);
            }
        }
        if (now.b > 0 && now.a != a) //从B倒到A
        {
            node tmp = now;
            int a_res = a - now.a; //A可以接收的水量
            if (now.b <= a_res)    //B内的水可以倒完
            {
                tmp.a += tmp.b;
                tmp.b = 0;
            }
            else
            {
                tmp.b -= a_res;
                tmp.a = a;
            }
            if (!vis[tmp.a][tmp.b])
            {
                tmp.step.append("5");
                vis[tmp.a][tmp.b] = true;
                q.push(tmp);
            }
        }
    }
}

void print()
{
    for (string::iterator it = now.step.begin(); it != now.step.end(); it++)
    {
        printf("%s\n", option[*it - '0']);
    }
    printf("success\n");
}

int main()
{
    while (cin >> a >> b >> c)
    {
        memset(vis, false, sizeof(vis));
        bfs();
        print();
    }
    return 0;
}