#include <iostream>
#include <map>

using namespace std;

int n, x;
map<int, int> mp;

int main()
{
    int temp;
    while (cin >> n)
    {
        mp.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            mp[temp] = i;
        }
        cin >> x;
        map<int, int>::iterator it = mp.find(x);
        if (it != mp.end())
        {
            cout << it->second << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
    return 0;
}