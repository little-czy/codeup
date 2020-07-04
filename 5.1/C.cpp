#include <iostream>
#include <cstdio>

using namespace std;

int n;

int main()
{
    while (cin >> n)
    {
        for (int i = 0; i <= 100; i++)
        {
            if (5 * i <= n)
            {
                for (int j = 0; j <= 100 - i; j++)
                {
                    if (8 * j <= 3 * n - 100 - 14 * i) //符合限制条件
                    {
                        // cout << "x=" << i << ",y=" << j << ",z=" << 100 - j - i << endl;
                        printf("x=%d,y=%d,z=%d\n", i, j, 100 - i - j);
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                break;
            }
        }
    }

    return 0;
}