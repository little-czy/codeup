#include <iostream>
#include <algorithm>

using namespace std;

int n;
double max_num, min_num;

int main()
{
    double tmp;
    while (cin >> n)
    {
        max_num = -0x3f3f3f, min_num = 0x3f3f3f;
        while (n--)
        {
            cin >> tmp;
            max_num = max(max_num, tmp);
            min_num = min(min_num, tmp);
        }
        cout << max_num << " " << min_num << endl;
    }
    return 0;
}