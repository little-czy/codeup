#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, k, tmp;
priority_queue<int, vector<int>, greater<int>> q;

int main()
{
    while (cin >> n >> k)
    {
        while (!q.empty()) //清空优先队列
        {
            q.pop();
        }
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            if (i < k) //还未向优先队列中放入k个数
            {
                q.push(tmp);
            }
            else
            {
                if (tmp > q.top())
                {
                    q.pop();
                    q.push(tmp);
                }
            }
        }
        cout << q.top() << endl;
    }

    return 0;
}