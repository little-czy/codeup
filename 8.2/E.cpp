#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct node
{
    int cur_cap[3];
    int num;
    node() {}
    node(int _a, int _b, int _c, int _n) { cur_cap[0] = (_a), cur_cap[1] = (_b), cur_cap[2] = (_c), num = _n; }
};
bool vis[105][105][105];
int cap[3], k;
queue<node> q;
node now;

inline bool can(int x, int y)
{
    if (now.cur_cap[x] == 0 || now.cur_cap[y] == cap[y])
        return false;
    return true;
}

inline void drop(int x, int y)
{
    node tmp = now;
    tmp.num++;
    int can_res = cap[y] - now.cur_cap[y];
    if (can_res <= now.cur_cap[x])
    {
        tmp.cur_cap[y] = cap[y];
        tmp.cur_cap[x] = now.cur_cap[x] - can_res;
    }
    else
    {
        tmp.cur_cap[x] = 0;
        tmp.cur_cap[y] = now.cur_cap[y] + now.cur_cap[x];
    }
    if (!vis[tmp.cur_cap[0]][tmp.cur_cap[1]][tmp.cur_cap[2]])
    {
        q.push(tmp);
        vis[tmp.cur_cap[0]][tmp.cur_cap[1]][tmp.cur_cap[2]] = true;
    }
}

bool BFS()
{
    q.push(node(cap[0], 0, 0, 0));
    vis[cap[0]][0][0] = true;
    while (!q.empty())
    {
        now = q.front();
        // cout << now.cur_cap[0] << endl;
        // cout << now.cur_cap[0] << " " << now.cur_cap[1] << " " << now.cur_cap[2] << " " << now.num << endl;
        q.pop();
        for (int i = 0; i < 3; i++)
            if (now.cur_cap[i] == k)
                return true;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (i != j && can(i, j))
                    drop(i, j);
    }
    return false;
}

int main()
{
    while (cin >> cap[0] >> cap[1] >> cap[2] >> k)
    {
        memset(vis, 0, sizeof(vis));
        while (!q.empty())
            q.pop();
        if (k > cap[0])
            cout << "no" << endl;
        else if (k == cap[0])
            cout << "yes\n0" << endl;
        else
        {
            if (!BFS())
                cout << "no" << endl;
            else
                cout << "yes\n"
                     << now.num << endl;
        }
    }
    return 0;
}