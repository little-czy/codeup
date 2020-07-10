#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <string>

using namespace std;

int n, k, course_no, stu_num;
string tmp_stu;
map<int, set<short>> mp;

int Hash(const char *name)
{
    return (name[0] - 'A' + 10) * 36 * 36 * 36 + (name[1] - 'A' + 10) * 36 * 36 + (name[2] - 'A' + 10) * 36 + (name[3] - '0');
}

int main()
{
    // while (cin >> n >> k)
    // {
    // mp.clear();
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> course_no >> stu_num;
        map<int, set<short>>::iterator it;
        for (int j = 0; j < stu_num; j++)
        {
            cin >> tmp_stu;
            it = mp.find(Hash(tmp_stu.c_str()));
            if (it != mp.end()) //mp中已存在该学生
            {
                it->second.insert(course_no);
            }
            else //mp中不存在该学生
            {
                set<short> st;
                st.insert(course_no);
                mp[Hash(tmp_stu.c_str())] = st;
            }
        }
    }
    map<int, set<short>>::iterator it;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp_stu;
        it = mp.find(Hash(tmp_stu.c_str()));
        if (it != mp.end()) //该学生已注册课程
        {
            printf("%s %d", tmp_stu.c_str(), (int)it->second.size());
            for (set<short>::iterator st_it = it->second.begin(); st_it != it->second.end(); st_it++)
            {
                printf(" %d", *st_it);
            }
            printf("\n");
        }
        else
        {
            printf("%s 0\n", tmp_stu.c_str());
        }
    }
    // }
    return 0;
}