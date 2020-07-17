#include <iostream>
#include <cstdio>
#include <queue>

int a, b, c;
int na, nb;

using namespace std;

int main()
{
    while (cin >> a >> b >> c)
    {
        printf("fill B\n");
        nb = b;
        while (nb != c)
        {
            if (na == a) //A满，首先倒掉
            {
                printf("empty A\n");
                na = 0;
            }
            else if (nb != 0)
            {
                if (nb >= a)
                {
                    nb -= a - na;
                    na = a;
                }
                else
                {
                    na = nb;
                    nb = 0;
                }
                printf("pour B A\n");
            }
            else
            {
                nb = b;
                printf("fill B\n");
            }
        }
        printf("success\n");
    }
    return 0;
}