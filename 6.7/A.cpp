#include <iostream>
#include <cstdio>
#include <stack>
#include <string>

using namespace std;

stack<double> s1;
stack<char> s2;
string s;
char s0[250];

void deal0()
{
    if (s2.top() == '*')
    {
        double a, b;
        s2.pop();
        b = s1.top();
        s1.pop();
        a = s1.top();
        s1.pop();
        a *= b;
        s1.push(a);
    }
    else if (s2.top() == '/')
    {
        double a, b;
        s2.pop();
        b = s1.top();
        s1.pop();
        a = s1.top();
        s1.pop();
        a /= b;
        s1.push(a);
    }
}

void deal1()
{
    if (s2.top() == '+')
    {
        double a, b;
        s2.pop();
        b = s1.top();
        s1.pop();
        a = s1.top();
        s1.pop();
        a += b;
        s1.push(a);
    }
    else if (s2.top() == '-')
    {
        double a, b;
        s2.pop();
        b = s1.top();
        s1.pop();
        a = s1.top();
        s1.pop();
        a -= b;
        s1.push(a);
    }
}

int main()
{
    double n;
    char c;
    getline(cin, s);
    // cout << s << endl;
    while (s.length() != 1 || s[0] != '0')
    {
        sscanf(s.c_str(), "%lf%[^\n]", &n, s0);
        s1.push(n);
        while (s.length())
        {
            if (sscanf(s.c_str(), "%*c%c%lf%[^\n]", &c, &n, s0) == 2)
                s0[0] = '\0';
            if (!s2.empty() && (c == '+' || c == '-'))
            {
                deal1();
                s1.push(n);
                s2.push(c);
            }
            else
            {
                s1.push(n);
                s2.push(c);
                deal0();
            }
            s = s0;
        }
        if (!s2.empty())
        {
            deal1();
        }
        printf("%.2lf\n", s1.top());
        s1.pop();
        getline(cin, s);
    }
    return 0;
}