#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct bign
{
    int d[1005];
    int len;
    bign()
    {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

bign change(char str[])
{
    bign a;
    a.len = strlen(str);
    for (int i = 0; i < a.len; i++)
    {
        a.d[i] = str[a.len - i - 1] - '0';
    }
    return a;
}

bign add(bign a, bign b)
{
    bign c;
    int carry = 0; //进位
    for (int i = 0; i < a.len || i < b.len; i++)
    {
        int tmp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = tmp % 10;
        carry = tmp / 10;
    }
    if (carry)
    {
        c.d[c.len++] = carry;
    }
    return c;
}

void print(bign a)
{
    for (int i = a.len - 1; i >= 0; i--)
    {
        printf("%d", a.d[i]);
    }
}

int main()
{
    char a[1024], b[1024];
    while (cin >> a >> b)
    {
        bign A = change(a);
        bign B = change(b);
        print(add(A, B));
        cout << endl;
    }
    return 0;
}