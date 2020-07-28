#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll P = 1e9 + 19;
const ll MAXN = 1e5 + 10;

struct node
{
    int len, begin;
    node(int _len, int _begin) : len(_len), begin(_begin) {}
};

string s1, s2;
ll powp[MAXN], h1[MAXN], h2[MAXN];
vector<pair<int, node>> p1, p2;

void init(int len)
{
    powp[0] = 1;
    for (int i = 1; i <= len; i++)
    {
        powp[i] = (powp[i - 1] * P) % MOD;
    }
}

void cal_h(ll h[], string &s)
{
    p1.clear(), p2.clear();
    h[0] = s[0];
    for (int i = 1; i < s.length(); i++)
    {
        h[i] = (h[i - 1] * P + s[i]) % MOD;
    }
}

int cal_single_sub_h(ll h[], int i, int j)
{
    if (i == 0)
        return h[j];
    return ((h[j] - h[i - 1] * powp[j - i + 1]) % MOD + MOD) % MOD;
}

void cal_sub_h(ll h[], int len, vector<pair<int, node>> &pr)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            pr.push_back(make_pair(cal_single_sub_h(h, i, j), node(j - i + 1, i)));
        }
    }
}

int get_max(int &begin, int &len)
{
    len = 0;
    for (int i = 0; i < p1.size(); i++)
    {
        for (int j = 0; j < p2.size(); j++)
        {
            if (p1[i].first == p2[j].first && len < p1[i].second.len)
            {
                begin = p1[i].second.begin;
                len = p1[i].second.len;
                // cout << begin << " " << len << endl;
            }
        }
    }
}

int main()
{
    while (getline(cin, s1))
    {
        getline(cin, s2);
        init(max(s1.length(), s2.length()));
        cal_h(h1, s1);
        cal_h(h2, s2);
        cal_sub_h(h1, s1.length(), p1);
        cal_sub_h(h2, s2.length(), p2);
        int begin, len;
        get_max(begin, len);
        cout << s1.substr(begin, len) << endl;
    }
    return 0;
}