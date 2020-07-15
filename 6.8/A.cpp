#include <iostream>
#include <cstdio>

using namespace std;

int n;
double x_0, y_0, x_1, y_1, x_2, y_2;
double x, y;

int main()
{
    cin >> n;
    while (n)
    {
        while (n--)
        {
            cin >> x_0 >> y_0 >> x_1 >> y_1 >> x_2 >> y_2;
            x = (x_0 + x_1 + x_2) / 3.0;
            y = (y_0 + y_1 + y_2) / 3.0;
            // cout << x << " " << y << endl;
            printf("%.1lf %.1lf\n", x, y);
        }
        cin >> n;
    }
    return 0;
}