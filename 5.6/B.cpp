#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct bign
{
    int d[5000];
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

bign mul(bign a, int b)
{
    bign c;
    int carry = 0; //进位
    for (int i = 0; i < a.len; i++)
    {
        int tmp = a.d[i] * b + carry;
        c.d[c.len++] = tmp % 10;
        carry = tmp / 10;
    }
    while (carry != 0)
    {
        c.d[c.len++] = carry % 10;
        carry /= 10;
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
    char a[5];
    while (cin >> a)
    {
        int tmp_a = atoi(a);
        if (tmp_a == 0)
        {
            cout << 1 << endl;
            continue;
        }
        bign A = change(a);
        while (--tmp_a)
        {
            A = mul(A, tmp_a);
        }
        print(A);
        cout << endl;
    }
    return 0;
}