#include <iostream>
using namespace std;

int main(void)
{
    string x = "ABCDEFG";
    string y;
    getline(cin,y);
    int flag = 1;
    if (y.size() > x.size())
    {
        flag = 0;
    }
    for (int i = 0; i < y.size(); i++)
    {
        if (y[i] != x[i])
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        std::cout << "YES" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }
    return 0;
}