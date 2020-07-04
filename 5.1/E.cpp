#include <iostream>

using namespace std;

int cur_max, cur_num;

int main()
{
    int tmp;
    while (cin >> tmp)
    {
        int num[12] = {0};
        num[tmp]++;
        cur_max = tmp;
        cur_num = 1;
        for (int i = 1; i < 20; i++)
        {
            cin >> tmp;
            num[tmp]++;
            if (num[tmp] > cur_num || (num[tmp] == cur_num && tmp < cur_max))
            {
                cur_max = tmp;
                cur_num = num[tmp];
            }
        }
        cout << cur_max << endl;
    }

    return 0;
}