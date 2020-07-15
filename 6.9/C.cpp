#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

string s;

int main()
{
    while (getline(cin, s))
    {
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
    return 0;
}