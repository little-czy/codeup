#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[11];
bool flag[12] = {false};

// void prem(int begin, int end)
// {
//     if (begin == end)
//     {
//         // cout << a[1];
//         printf("%d", a[1]);
//         for (int i = 2; i <= n; i++)
//         {
//             // cout << " " << a[i];
//             printf(" %d", a[i]);
//         }
//         // cout << endl;
//         printf("\n");
//     }
//     else
//     {
//         for (int i = begin; i <= end; i++)
//         {
//             swap(a[begin], a[i]);
//             prem(begin + 1, end);
//             swap(a[begin], a[i]);
//         }
//     }
// }

void prem(int index)
{
    if (index == n)
    {
        printf("%d", a[0]);
        for (int i = 1; i < n; i++)
        {
            // cout << " " << a[i];
            printf(" %d", a[i]);
        }
        // cout << endl;
        printf("\n");
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (flag[i])
                continue;
            a[index] = i;
            flag[i] = true;
            prem(index + 1);
            flag[i] = false;
        }
    }
}

int main()
{
    while (cin >> n)
    {
        prem(0);
    }
    return 0;
}