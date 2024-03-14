#include <iostream>
using namespace std;

bool is_prime(int num)
{
    if (num < 2)
        return false;
    else if (num > 2)
    {
        for (int i = 2; i <= num/2;i++)
        {
            if (num%i == 0)
            {
                return false;
            }
        }
    }
    return true;
}
int nth_prime(int n)
{
    int count = 0;
    int num = 0;
    while (count < n)
    {
        num++;
        if (is_prime(num))
            count++;
    }
    return num;
}

int main(void)
{
    int num;
    cin >> num;
    num = nth_prime(num);
    cout << num;
    return 0;
}