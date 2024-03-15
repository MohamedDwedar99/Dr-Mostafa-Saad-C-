#include <iostream>
using namespace std;

int my_pow(int value, int p = 2)
{
    if (p == 0)
        return 1;
    else
        return value * my_pow(value,p-1);
}

int main(void)
{
    int v,p;
    cin >> v >> p;
    cout << my_pow(v,p);
    return 0;
}