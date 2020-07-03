#include <iostream>

using namespace std;

int n, k;
int num[100];

int main()
{
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            bool is[100] = {false};
            cin >> k;
            for (int j = 0; j < k; j++)
            {
                cin >> num[j];
            }
            if (num[0] != num[1])
                is[0] = true;
            if (num[k - 1] != num[k - 2])
                is[k - 1] = true;
            for (int j = 1; j < k - 1; j++)
            {
                if (num[j] < num[j - 1] && num[j] < num[j + 1])
                    is[j] = true;
                if (num[j] > num[j - 1] && num[j] > num[j + 1])
                    is[j] = true;
            }
            bool first = true;
            for (int j = 0; j < k; j++)
            {
                if (first && is[j])
                {
                    cout << j;
                    first = false;
                }
                else if (!first && is[j])
                    cout << " " << j;
            }
            if (!first)
                cout << endl;
        }
    }
    return 0;
}