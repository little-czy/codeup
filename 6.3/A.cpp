#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

long double a, b, c;
string s;
char ans[1024];

int main()
{
    // while (cin >> a >> b)
    // {
    cin >> a >> b;
    c = a + b;
    if (c - (long long)c < 1e-10) //c不为浮点数
    {
        printf("%lld\n", (long long)c);
    }
    else
    {
        cout << c << endl;
        sprintf(ans, "%.20Lf", c);
        s = ans;
        if (s[0] == '-')
        {
            printf("-\n");
        }
        printf("%s\n", ans);
    }

    // }
    return 0;
}
