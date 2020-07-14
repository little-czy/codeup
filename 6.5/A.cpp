#include <iostream>

using namespace std;

int a[10];

inline int find_max(int &x)
{
    int max_num = a[0];
    for (int i = 1; i < 10; i++)
    {
        if (a[i] > max_num)
        {
            max_num = a[i];
            x = i;
        }
    }
    return max_num;
}

inline int find_min(int &x)
{
    int max_num = a[0];
    for (int i = 1; i < 10; i++)
    {
        if (a[i] < max_num)
        {
            max_num = a[i];
            x = i;
        }
    }
    return max_num;
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    int x;
    int tmp = find_min(x);
    a[x] = a[0];
    a[0] = tmp;
    tmp = find_max(x);
    a[x] = a[9];
    a[9] = tmp;
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}