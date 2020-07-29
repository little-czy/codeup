#include <iostream>
#include <string>

using namespace std;

string s, word;

int main()
{
    cin >> s;
    while (s[0] != '#')
    {
        cin >> word;
        int pos = 0, ans = 0;
        while ((pos = s.find(word, pos)) != string::npos)
        {
            ans++;
            pos += word.length();
        }
        cout << ans << endl;
        cin >> s;
    }
    return 0;
}