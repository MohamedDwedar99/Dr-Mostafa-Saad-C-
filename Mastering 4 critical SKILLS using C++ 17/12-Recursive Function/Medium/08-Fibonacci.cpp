#include <iostream>
using namespace std;

long long track = 0;
long long dp[1000]  = {0};

// int fibonacci(int n)
// {
//     track++;
//     if (n == 0 || n == 1)
//         return 1;
//     return fibonacci(n-1)+fibonacci(n-2);
// }
long long fibonacci(int n)
{
    track = track + 1;
    if (n == 0 || n == 1)
        return 1;
    if (dp[n] == 0)
        dp[n] = fibonacci(n-1)+fibonacci(n-2);
    return dp[n];
}

int main(void)
{
    long long num;
    cin >> num;
    cout << fibonacci(num);
    cout <<" steps = " << track;
    return 0;
}