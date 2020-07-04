#include <iostream>

using namespace std;

int a[4][4], b[4][4], c[4][4];

int main()
{
    while (cin >> a[0][0] >> a[0][1] >> a[0][2])
    {
        for (int j = 0; j < 3; j++)
            cin >> a[1][j];
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 2; j++)
                cin >> b[i][j], c[i][j] = 0;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        cout << c[0][0] << " " << c[0][1] << endl;
        cout << c[1][0] << " " << c[1][1] << endl;
    }

    return 0;
}