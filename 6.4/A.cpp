#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <set>

using namespace std;

char c[1048580], tmp[1024];
map<string, int> mp;
set<string> st;
int len;

inline bool is_alpha_num(char an)
{
    return ('a' <= an && an <= 'z') || ('A' <= an && an <= 'Z') || ('0' <= an && an <= '9');
}

int main()
{
    cin.getline(c, 1048580);
    len = strlen(c);
    map<string, int>::iterator it;
    for (int i = 0; i < len;)
    {
        int j, k;
        for (j = 0; j < len && is_alpha_num(c[i + j]); j++)
        {
            if ('A' <= c[i + j] && c[i + j] <= 'Z') //大写字母
                tmp[j] = c[i + j] + 'a' - 'A';
            else
                tmp[j] = c[i + j];
        }
        tmp[j] = '\0';
        string tmp_s = tmp;
        // cout << tmp_s << endl;
        if ((it = mp.find(tmp_s)) == mp.end())
        {
            mp[tmp_s] = 1;
        }
        else
        {
            it->second++;
        }
        for (k = i + j; k < len && !is_alpha_num(c[k]); k++)
            ;
        i = k;
    }
    int max_num = 0;
    string max_s;
    for (map<string, int>::iterator it0 = mp.begin(); it0 != mp.end(); it0++)
    {
        if (max_num < it0->second)
        {
            max_num = it0->second;
            max_s = it0->first;
        }
    }
    for (map<string, int>::iterator it0 = mp.begin(); it0 != mp.end(); it0++)
    {
        if (max_num == it0->second)
        {
            st.insert(it0->first);
        }
    }
    for (set<string>::iterator it1 = st.begin(); it1 != st.end(); it1++)
    {
        cout << *it1 << " " << max_num << endl;
    }
    return 0;
}