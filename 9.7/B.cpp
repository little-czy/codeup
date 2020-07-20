#include <queue>
#include <iostream>
#include <cstdio>

using namespace std;

int n, tmp;
int a[100005], b[100005], c[100005];
priority_queue<int> q;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (q.size() < n)
                q.push(a[i] + b[j]);
            else
            {
                int sum = a[i] + b[j];
                if (q.top() > sum)
                {
                    q.pop();
                    q.push(sum);
                }
                else
                    break;
            }
        }
    for (int i = n - 1; i >= 0; i--)
    {
        c[i] = q.top();
        q.pop();
    }
    printf("%d", c[0]);
    for (int i = 1; i < n; i++)
        printf(" %d", c[i]);
    printf("\n");
    return 0;
}