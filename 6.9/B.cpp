#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char c[10];

int main()
{
    while (cin >> c)
    {
        do
        {
            cout << c << endl;
        } while (next_permutation(c, c + strlen(c)));
        cout << endl;
    }
    return 0;
}