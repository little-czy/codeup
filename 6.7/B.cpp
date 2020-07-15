#include <iostream>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

int n;
string s;

int main()
{
    while (cin >> n)
    {
        getchar();
        while (n--)
        {
            bool flag = 0;
            stack<char> st;
            getline(cin, s);
            for (int i = 0; i < s.length() && !flag; i++)
            {
                switch (s[i])
                {
                case '(':
                    st.push('(');
                    break;
                case '[':
                    st.push('[');
                    break;
                case '{':
                    st.push('{');
                    break;
                case ')':
                    if (!st.empty() && st.top() == '(')
                        st.pop();
                    else
                        flag = 1;
                    break;
                case ']':
                    if (!st.empty() && st.top() == '[')
                        st.pop();
                    else
                        flag = 1;
                    break;
                case '}':
                    if (!st.empty() && st.top() == '{')
                        st.pop();
                    else
                        flag = 1;
                    break;
                }
            }
            if (!flag && st.empty())
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
    }
    return 0;
}