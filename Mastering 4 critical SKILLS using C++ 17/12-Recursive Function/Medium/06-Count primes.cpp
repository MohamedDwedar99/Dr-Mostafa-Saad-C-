#include <iostream>
using namespace std;

bool Is_prime(int Num, int par = 3)
{

    if (Num == 2 || par == Num)
        return true;
    if (Num%par == 0 || Num < 2)
        return false;
    return Is_prime(Num, par+1);
}

int count_primes(int start, int end)
{
    if (start > end)
        return 0;
    return Is_prime(start) + count_primes(start+1,end);
}



int main(void)
{
    int start,end;
    cin >> start >> end;
    cout << count_primes(start,  end);
    return 0;
}