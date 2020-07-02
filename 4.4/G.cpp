#include <iostream>

using namespace std;

int n, num[5];

int main()
{
    int mon[5] = {50, 20, 10, 5, 1};
    while (cin >> n)
    {
        for (int i = 0; i < 5; i++)
        {
            num[i] = n / mon[i];
            n -= mon[i] * num[i];
        }
        int i;
        for (i = 0; i < 5; i++)
        {
            if (num[i] != 0)
            {
                cout << mon[i] << "*" << num[i];
                break;
            }
        }
        for (int j = i + 1; j < 5; j++)
        {
            if (num[j] != 0)
            {
                cout << "+" << mon[j] << "*" << num[j];
            }
        }
        cout << endl;
    }

    return 0;
}