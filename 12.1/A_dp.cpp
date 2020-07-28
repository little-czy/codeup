#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAXN 1001

using namespace std;

struct node
{
    int len, begin;
} f[MAXN][MAXN];

string s1, s2;

int longestSubstring(string &x, string &y, int &begin)
{
    // vector<vector<int>> f(x.size() + 1, vector<int>(y.size() + 1, 0));
    int max = -1;
    for (int i = 1; i <= x.size(); i++)
    {
        for (int j = 1; j <= y.size(); j++)
        {
            if (x[i - 1] != y[j - 1])
            {
                f[i][j].len = 0;
            }
            else if (x[i - 1] == y[j - 1])
            {
                f[i][j].len = f[i - 1][j - 1].len + 1;
                if (f[i][j].len == 1)
                {
                    f[i][j].begin = i - 1;
                }
                else
                    f[i][j].begin = f[i - 1][j - 1].begin;
            }
            if (max < f[i][j].len)
            {
                max = f[i][j].len;
                begin = f[i][j].begin;
            }
        }
    }
    return max;
}

int main()
{
    while (getline(cin, s1))
    {
        getline(cin, s2);
        int begin = 0;
        int len = longestSubstring(s1, s2, begin);
        if (len != 0)
            cout << s1.substr(begin, len) << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}