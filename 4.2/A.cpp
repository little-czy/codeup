#include <iostream>

using namespace std;

int n, m;

int main()
{
    int t;

    while (cin >> n)
    {
        int a[300] = {0}, b[300] = {0};
        cin >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> t;
            a[t]++;
            b[i] = t;
        }
        for (int i = 1; i <= n; i++)
        {
            t = a[b[i]];
            if (t == 1)
                cout << "BeiJu" << endl;
            else
                cout << t - 1 << endl;
        }
    }

    return 0;
}