#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct task
{
    string name;
    int pri; //优先级
    bool operator<(const task &t) const
    {
        if (pri == t.pri)
        {
            return name > t.name;
        }
        else
        {
            return pri > t.pri;
        }
    }
};

int n;
priority_queue<task> q;
map<string, int> mp;
string s, s1;

void deal(string s)
{
    int l = s.find("("), r;
    task t;
    t.pri = 0;
    t.name = s.substr(0, l);
    if (mp.find(t.name) == mp.end())
    {
        mp[t.name] = 0;
    }
    l++;
    while ((r = s.find(",", l)) != string::npos || (r = s.find(")", l)) != string::npos)
    {
        s1 = s.substr(l, r - l);
        if (s1 == "NULL")
        {
            l = r + 1;
            continue;
        }
        if (mp.find(s1) == mp.end())
        {
            mp[s1] = mp[t.name] + 1;
        }
        else
        {
            mp[s1] = max(mp[t.name] + 1, mp[s1]);
        }
        if (r == s.length() - 1)
        {
            break;
        }
        l = r + 1;
    }
}

int main()
{
    while (cin >> n)
    {
        mp.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            deal(s);
        }
        task t;
        for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
        {
            t.name = it->first;
            t.pri = it->second;
            q.push(t);
        }
        while (!q.empty())
        {
            cout << q.top().name << " ";
            q.pop();
        }
        cout << endl;
    }
    return 0;
}