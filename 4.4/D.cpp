#include <iostream>
#include <algorithm>

using namespace std;

long long l, block[610];
int n;

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    while (cin >> l >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> block[i];
        }
        sort(block, block + n, cmp);
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            if (block[i] >= l)
            {
                num++;
                l = 0;
                break;
            }
            else
            {
                l -= block[i];
                num++;
            }
        }
        if (l)
        {
            cout << "impossible" << endl;
        }
        else
        {
            cout << num << endl;
        }
    }
    return 0;
}