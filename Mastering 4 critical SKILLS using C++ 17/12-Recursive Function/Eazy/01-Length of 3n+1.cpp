#include <iostream>
using namespace std;


int length_3n_plus_1(int n)
{
    int len = 1;
    if (n == 1)
    {
        return len;
    }
    else if (n%2 == 0)
    {
        return len+length_3n_plus_1(n/2);
    }
    else
    {
        return len+length_3n_plus_1(n*3+1);
    }
}

int main(void)
{
    int x = length_3n_plus_1(6);
    cout << x;
    return 0;
}