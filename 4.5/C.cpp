#include <iostream>
#include <map>

using namespace std;

int n, m, tmp;
map<int, int> mp;

int main()
{
    while (cin >> n)
    {
        mp.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            mp[tmp] = i;
        }
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> tmp;
            map<int, int>::iterator it = mp.find(tmp);
            if (it == mp.end())
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}