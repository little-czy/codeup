#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct node
{
    double price, loc, add;
} gas_node[510];
double c, d, avg, cur_gas, max_dis, all_price;
int n;

bool cmp(struct node x, struct node y)
{
    return x.loc < y.loc;
}

int find_miner(int i)
{
    for (int j = i + 1; j < n && gas_node[j].loc - gas_node[i].loc <= max_dis; j++)
    {
        if (gas_node[j].price < gas_node[i].price)
        {
            return j;
        }
    }
    return 0;
}

int find_min(int i) //在加油站i所顾及范围内寻找最便宜的加油站
{
    int cur_min_price = gas_node[i + 1].price, cur_j = i + 1;
    for (int j = i + 2; j < n && gas_node[j].loc - gas_node[i].loc <= max_dis; j++)
    {
        if (gas_node[j].price < cur_min_price)
        {
            cur_min_price = gas_node[j].price;
            cur_j = j;
        }
    }
    return cur_j;
}

int main()
{
    cin >> c >> d >> avg >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> gas_node[i].price >> gas_node[i].loc;
    }
    sort(gas_node, gas_node + n, cmp);
    if (n == 0 || gas_node[0].loc != 0)
    {
        cout << "The maximum travel distance = 0.00" << endl;
        return 0;
    }
    max_dis = c * avg;
    for (int i = 1; i < n; i++) //判断是否可以到达目的地
    {
        if (gas_node[i].loc - gas_node[i - 1].loc > max_dis)
        {
            printf("The maximum travel distance = %.2lf\n", gas_node[i - 1].loc + max_dis);
            return 0;
        }
    }
    if (d - gas_node[n - 1].loc > max_dis)
    {
        printf("The maximum travel distance = %.2lf\n", gas_node[n - 1].loc + max_dis);
        return 0;
    }
    cur_gas = 0;
    int next_gas;
    for (int i = 0; i < n;)
    {
        if (gas_node[i].loc == d)
        {
            break;
        }
        if ((next_gas = find_miner(i)) != 0) //当前加油站作用域内存在更低油价的加油站
        {
            // all_price += gas_node[i].price * (gas_node[]);
            gas_node[i].add = (gas_node[next_gas].loc - gas_node[i].loc) / avg - cur_gas;
            cur_gas = 0;
            i = next_gas;
        }
        else //当前加油站作用域内不存在更低油价的加油站
        {
            if (gas_node[i].loc + max_dis >= d) //不需要加满便可到达目的地
            {
                gas_node[i].add = (d - gas_node[i].loc) / avg - cur_gas;
                // cout << gas_node[i].add << endl;
                break;
            }
            else
            {
                gas_node[i].add = c - cur_gas;
                cur_gas = c;
                int j = find_min(i);
                cur_gas -= (gas_node[j].loc - gas_node[i].loc) / avg;
                i = j;
            }
        }
    }
    all_price = 0;
    for (int i = 0; i < n; i++)
    {
        all_price += gas_node[i].add * gas_node[i].price;
    }
    printf("%.2lf\n", all_price);
    return 0;
}