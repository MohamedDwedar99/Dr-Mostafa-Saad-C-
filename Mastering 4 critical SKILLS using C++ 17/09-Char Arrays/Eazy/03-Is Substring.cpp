#include <iostream>
using namespace std;

int main(void)
{
    string x = "ABCDEFG";
    string y;
    getline(cin,y);
    int flag = 1;
    int start = 0;
    if (y.size() > x.size())
    {
        flag = 0;
    }
    while (start< x.size()+1)
    {
        if (start == x.size()+1)
        {
            flag = 0;
            break;
        }
        else if (x[start] == y[0])
        {
            break;
        }
        else
        {
            start++;
        }
    }
    for (int i = 0;i < y.size();i++)
    {
        if (x[i+start] != y[i])
        {
            flag = 0;
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