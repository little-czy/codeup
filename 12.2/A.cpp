#include <iostream>
#include <string>

using namespace std;

string s, word;
int n;

int find_word()
{
    int ans = 0, pos = 0;
    while ((pos = s.find(word, pos)) != string::npos)
    {
        ans++;
        pos++;
    }
    return ans;
}

int main()
{
    while (cin >> n >> word)
    {
        int ans = 0;
        getchar();
        for (int i = 0; i < n; i++)
        {
            getline(cin, s);
            ans += find_word();
        }
        cout << ans << endl;
    }
    return 0;
}