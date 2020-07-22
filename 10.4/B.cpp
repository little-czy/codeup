#include <iostream>
#include <cstdio>

#define MAXV 55
#define INF 0x3f3f3f3f
using namespace std;

int n;
int g[MAXV][MAXV];

void floyd()
{
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (g[i][k] != INF && g[k][j] != INF && g[i][k] + g[k][j] < g[i][j])
                    g[i][j] = g[i][k] + g[k][j];
}

int main()
{
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> g[i][j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                if (g[i][j] == 0)
                    g[i][j] = INF;
            }
        floyd();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (g[i][j] != INF)
                    printf("%d ", g[i][j]);
                else
                    printf("-1 ");
            }
            printf("\n");
        }
    }
    return 0;
}