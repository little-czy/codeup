#include <iostream>
#include <cstdio>

using namespace std;

double count_price(int x)
{
    if (x <= 4)
        return 10.0;
    else if (x <= 8)
        return 10.0 + 2.0 * (x - 4);
    else
        return 18.0 + 2.4 * (x - 8);
}

int main()
{
    int n, num, last_n;
    double price;
    cin >> n;
    while (n != 0)
    {
        if (n <= 13)
        {
            // cout << count_price(n) << endl;
            price = count_price(n);
            if (price - (int)price > 0)
                printf("%.1lf\n", price);
            else
                printf("%d\n", (int)price);
        }
        else
        {
            num = (n - 13) / 8;
            last_n = n - num * 8;
            price = 18.0 * num;
            if (last_n > 13)
            {
                // cout << price + count_price(last_n - 8) + 18 << endl;
                price = price + count_price(last_n - 8) + 18;
                if (price - (int)price > 0)
                    printf("%.1lf\n", price);
                else
                    printf("%d\n", (int)price);
            }
            else
            {
                // cout << price + count_price(last_n) << endl;
                price = price + count_price(last_n);
                if (price - (int)price > 0)
                    printf("%.1lf\n", price);
                else
                    printf("%d\n", (int)price);
            }
        }
        cin >> n;
    }
    return 0;
}