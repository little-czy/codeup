#include <iostream>

using namespace std;

int count_num(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    return count_num(n - 1) + count_num(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout << count_num(n) << endl;
    return 0;
}