#include <iostream>

using namespace std;

int main()
{
    // while (true)
    // {
    int n, flag = 0;
    int bet[10001] = {0}, at[100001] = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> at[i];
        bet[at[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (bet[at[i]] == 1)
        {
            cout << at[i] << endl;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "None" << endl;
    }
    // }
    return 0;
}