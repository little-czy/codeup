#include <iostream>

using namespace std;

int n, n2;

int main()
{
    while (cin >> n)
    {
        bool flag = true;
        n2 = n * n;
        while (n > 0)
        {
            if (n % 10 != n2 % 10)
            {
                flag = false;
                break;
            }
            n /= 10;
            n2 /= 10;
        }
        if (flag)
            cout << "Yes!" << endl;
        else
            cout << "No!" << endl;
    }
    return 0;
}