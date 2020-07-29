#include <iostream>
#include <string>

using namespace std;

char tmp[64];
string s, word;
int n, pos, num;

void init()
{
    pos = num = 0;
    for (int i = 0; i < word.length(); i++)
        if (word[i] >= 'A' && word[i] <= 'Z')
            word[i] += 'a' - 'A';
    for (int i = 0; i < s.length(); i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 'a' - 'A';
}

void find_word()
{
    if (s.compare(word) == 0)
    {
        num = 1;
        pos = 0;
        return;
    }
    int t_pos;
    pos = s.find(word);
    if (pos != string::npos)
    {
        if (pos == 0) //匹配位置在首位
        {
            if (s[pos + word.length()] == ' ')
            {
                num = 1;
            }
        }
        else
        {
            if (s[pos - 1] == ' ' && (pos + word.length() == s.length() || s[pos + word.length()] == ' '))
            {
                num = 1;
            }
        }
        t_pos = pos + word.length();
        while ((t_pos = s.find(word, t_pos)) != string::npos)
        {
            if (s[t_pos - 1] == ' ' && (t_pos + word.length() == s.length() || s[t_pos + word.length()] == ' '))
            {
                num++;
            }
            t_pos += word.length();
        }
    }
}

int main()
{
    while (scanf("%s", tmp))
    {
        // getchar();
        while (getchar() != '\n')
            ;
        word = tmp;
        getline(cin, s);
        init();
        find_word();
        if (num)
            cout << num << " " << pos << endl;
        else
            cout << "-1" << endl;
    }
    return 0;
}