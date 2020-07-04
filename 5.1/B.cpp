#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    for (int i = 1000; i < 10000; i++)
    {
        string a = to_string(i), b = to_string(i * 9);
        reverse(b.begin(), b.end());
        if (a == b)
        {
            cout << i << endl;
        }
    }
    return 0;
}