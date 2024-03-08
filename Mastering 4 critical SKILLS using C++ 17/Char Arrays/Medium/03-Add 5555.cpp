#include <iostream>
using namespace std;

int main(void)
{
    string str;
    cin >> str;
    string strnum;
    int size = str.size();
    int num = 5555;
    int carry = 0;
    for (int i = size-1; i >= 0  ; i--)
    {
        carry += num%10 + str[i] -'0';
        num/=10;
        str[i] = carry%10+'0';
        carry/=10;
    }
    if (carry)
    {
        std::cout << carry;
    }
    cout << str;
    return 0;
}