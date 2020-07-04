#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    return !b ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    int n;
    while (cin >> n)
    {
        while (n--)
        {
            int m, tmp_a, tmp_b;
            cin >> m >> tmp_a;
            for (int i = 1; i < m; i++)
            {
                cin >> tmp_b;
                tmp_a = lcm(tmp_a, tmp_b);
            }
            cout << tmp_a << endl;
        }
    }
    return 0;
}