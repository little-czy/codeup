#include <iostream>
#include <cstdio>

using namespace std;

int n, ans[12];
bool flag[12][12], has_ans;

bool canPut(int x, int y)
{
    if (flag[x][y])
        return false;
    for (int i = 1; i <= x; i++)
        if (flag[i][y])
            return false;
    for (int i = x, j = y; i > 0 && j > 0; i--, j--)
    {
        if (flag[i][j])
            return false;
    }
    for (int i = x, j = y; i > 0 && j <= n; i--, j++)
    {
        if (flag[i][j])
            return false;
    }
    return true;
}

void dfs(int index)
{
    if (index == n + 1)
    {
        cout << ans[1];
        for (int i = 2; i <= n; i++)
            cout << " " << ans[i];
        cout << endl;
        has_ans = true;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (!canPut(index, i))
                continue;
            flag[index][i] = true;
            ans[index] = i;
            dfs(index + 1);
            flag[index][i] = false;
        }
    }
}

int main()
{
    while (cin >> n)
    {
        has_ans = false;
        dfs(1);
        if (!has_ans)
            cout << "no solute!" << endl;
    }
    return 0;
}