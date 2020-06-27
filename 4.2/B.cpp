#include <iostream>

using namespace std;

int m, n;

int main()
{
    cin >> m;
    while (m--)
    {
        int a[110][10001];
        int num[110] = {0};
        int g, max_g = 0;
        int flag[10001] = {0}, flag_g[110] = {0};
        for (int i = 0; i < 110; i++) //初始化
        {
            for (int k = 0; k < 10001; k++)
            {
                a[i][k] = 0;
            }
        }
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
            flag[num[i]] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> g;
            flag_g[g] = 1;
            max_g = max_g >= g ? max_g : g;
            a[g][num[i]]++;
        }
        for (int i = 1; i <= max_g; i++)
        {
            if (flag_g[i] == 0)
                continue;
            cout << i << "={";
            int j;
            for (j = 0; j < 10001; j++)
            {
                if (flag[j]) //数j出现过
                {
                    cout << j << "=" << a[i][j];
                    break;
                }
            }
            for (int k = j + 1; k < 10001; k++)
            {
                if (flag[k]) //数j出现过
                {
                    cout << "," << k << "=" << a[i][k];
                }
            }
            cout << "}" << endl;
        }
    }

    return 0;
}