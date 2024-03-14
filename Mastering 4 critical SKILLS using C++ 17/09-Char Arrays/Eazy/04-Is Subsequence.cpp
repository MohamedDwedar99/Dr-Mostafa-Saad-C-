#include <iostream>
using namespace std;

int main(void)
{
    string x = "ABCDEFG";
    string y;
    getline(cin,y);
    int flag = 1;
    int i = 0;
    int j = 0;
    if (y.size() > x.size())
    {
        flag = 0;
    }
    while (i < x.size()&& j < y.size())
    {
        if (x[i] == y[j])
        {
            j++;
        }
        i++;
    }
    if (i == x.size() && j < y.size())
    {
        flag = 0;
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