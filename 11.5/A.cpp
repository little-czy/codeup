#include <iostream>
#include <string>
#include <cstring>

#define MAXN 5010

using namespace std;

bool dp[MAXN][MAXN];
int f[MAXN];
string s, goal_s;

void init()
{
    s.clear();
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < goal_s.length(); i++)
    {
        if (goal_s[i] >= 'a' && goal_s[i] <= 'z')
        {
            f[s.length()] = i;
            char tmp[2];
            tmp[0] = goal_s[i] + 'A' - 'a', tmp[1] = '\0';
            s.append(tmp);
        }
        if (goal_s[i] >= 'A' && goal_s[i] <= 'Z')
        {
            f[s.length()] = i;
            char tmp[2];
            tmp[0] = goal_s[i], tmp[1] = '\0';
            s.append(tmp);
        }
    }
}

int main()
{
    while (getline(cin, goal_s))
    {
        // getchar();
        // getline(cin, goal_s);
        int ans = 1, left = 0;
        init();
        // cout << goal_s << endl;
        // cout << s << endl;
        for (int i = 0; i < s.length(); i++)
        {
            dp[i][i] = 1;
            if (i < s.length() - 1)
            {
                if (s[i] == s[i + 1])
                {
                    dp[i][i + 1] = 1;
                    if (ans != 2)
                        left = i;
                    ans = 2;
                }
            }
        }
        for (int l = 3; l <= s.length(); l++)
        {
            for (int i = 0; i + l - 1 < s.length(); i++)
            {
                int j = i + l - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = 1;
                    if (ans != l)
                        left = i;
                    ans = l;
                }
            }
        }
        // cout << left << " " << ans << endl;
        cout << goal_s.substr(f[left], f[left + ans - 1] - f[left] + 1) << endl;
    }
    return 0;
}