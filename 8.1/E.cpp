#include <iostream>
#include <stack>

using namespace std;

stack<int> s;
int n, ans, cur_num;

void dfs(int index)
{
    if (index == n)
    {
        ans++;
    }
    else
    {
        if (!s.empty())
        {
            int num = s.top();
            s.pop();
            dfs(index + 1);
            s.push(num);
        }
        if (cur_num <= n)
        {
            s.push(cur_num++);
            dfs(index);
            cur_num--;
            s.pop();
        }
    }
}

int main()
{
    while (cin >> n)
    {
        ans = 0;
        cur_num = 1;
        dfs(0);
        cout << ans << endl;
    }
    return 0;
}