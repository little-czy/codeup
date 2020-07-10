#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int getID(char name[])
{
    int ID = 0;
    for (int i = 0; i < 3; i++)
        ID = ID * 26 + name[i] - 'A';
    ID = ID * 10 + (name[3] - '0');
    return ID;
}
const int N = 40005;
const int M = 26 * 26 * 26 * 10 + 1;
vector<int> selectCourse[M];

int main()
{
    char name[5];
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++)
    {
        int index, num;
        scanf("%d%d", &index, &num);
        for (int j = 0; j < num; j++)
        {
            scanf("%s", name);
            selectCourse[getID(name)].push_back(index);
        }
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%s", name);
        int id = getID(name);
        sort(selectCourse[id].begin(), selectCourse[id].end());
        printf("%s %d", name, selectCourse[id].size());
        for (int j = 0; j < selectCourse[id].size(); j++)
        {
            printf(" %d", selectCourse[id][j]);
        }
        printf("\n");
    }
    return 0;
}