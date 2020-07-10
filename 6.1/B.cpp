#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int n, k, stu_num, tmp_cou, hash_stu;
string stu_name;
vector<int> course[2505];
map<int, string> stu;

int Hash(const char *name)
{
    return (name[0] - 'A' + 10) * 36 * 36 * 36 + (name[1] - 'A' + 10) * 36 * 36 + (name[2] - 'A' + 10) * 36 + (name[3] - '0');
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> stu_name >> stu_num;
        hash_stu = Hash(stu_name.c_str());
        stu[hash_stu] = stu_name;
        // scanf("%s%d", stu_name, &stu_num);
        for (int j = 0; j < stu_num; j++)
        {
            scanf("%d", &tmp_cou);
            course[tmp_cou].push_back(hash_stu);
        }
    }
    for (int i = 1; i <= k; i++)
    {
        sort(course[i].begin(), course[i].end());
        printf("%d %d\n", i, (int)course[i].size());
        for (int j = 0; j < course[i].size(); j++)
        {
            printf("%s\n", stu[course[i][j]].c_str());
        }
    }

    return 0;
}