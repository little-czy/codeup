#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

struct node
{
    char a[9][9];
    int x, y;
    int step;
    node() {}
    node(char b[9][9], int _x, int _y, int num) : x(_x), y(_y), step(num) { memcpy(a, b, sizeof(a)); }
};

char a[9][9];
node now;
int n, num;
int X[6] = {0, -1, 0, 0, -1, -1};
int Y[6] = {0, 0, -1, 1, -1, 1};

bool can_stand(node &tmp)
{
    if (tmp.x <= 0 || tmp.y < 0 || tmp.x > 8 || tmp.y > 7)
        return false;
    if (tmp.a[tmp.x][tmp.y] == 'S' || tmp.a[tmp.x - 1][tmp.y] == 'S')
        return false;
    return true;
}

void drop(node &tmp)
{
    for (int i = 8; i > 0; i--)
        strcpy(tmp.a[i], tmp.a[i - 1]);
}

bool bfs()
{
    queue<node> q;
    int x, y;
    q.push(node(a, 8, 0, 1));
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        if (now.step == 9)
            return true;
        for (int i = 0; i < 6; i++)
        {
            node tmp = now;
            tmp.step++;
            tmp.x += X[i];
            tmp.y += Y[i];
            if (can_stand(tmp))
            {
                drop(tmp);
                q.push(tmp);
            }
        }
    }
    return false;
}

int main()
{
    while (cin >> n)
    {
        num = 1;
        while (n--)
        {
            for (int i = 1; i < 9; i++)
            {
                cin >> a[i];
                a[0][i - 1] = '.';
            }
            a[0][8] = '\0';
            a[8][0] = a[0][7] = '.';
            if (bfs())
                cout << "Case #" << num << ": Yes" << endl;
            else
                cout << "Case #" << num << ": No" << endl;
            num++;
        }
    }
    return 0;
}