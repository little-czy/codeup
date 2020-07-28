#include <iostream>
#include <string>

#define MAXN 105

using namespace std;

char _a[MAXN], _b[MAXN];
string a, b;
int dp[MAXN][MAXN];

int main()
{
    while (cin >> _a >> _b)
    {
        a = b = " ";
        a.append(_a), b.append(_b);
        for (int i = 0; i < a.length(); i++)
            dp[i][0] = 0;
        for (int i = 0; i < b.length(); i++)
            dp[0][i] = 0;
        for (int i = 1; i < a.length(); i++)
        {
            for (int j = 1; j < b.length(); j++)
            {
                if (a[i] == b[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
        cout << dp[a.length() - 1][b.length() - 1] << endl;
    }
    return 0;
}