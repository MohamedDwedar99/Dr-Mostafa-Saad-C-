#include <iostream>
using namespace std;

int main(void)
{
    string x = "ABCDEFG";
    string y;
    getline(cin,y);
    if (y.size() > x.size())
    {
        flag = 0;
    }
    int flag = 1;
    for (int i = x.size()-1; i >= x.size()-y.size(); i--)
    {
        if (y[i-(int)x.size()+(int)y.size()] != x[i])
        {
            flag = 0;
            break;
        }
    }
    /******* OR  *******/
    // for (int i = x.size()-1 ,j = y.size()-1; i >= x.size()-y.size(); i--,j--)
    // {
    //     if (y[j] != x[i])
    //     {
    //         flag = 0;
    //         break;
    //     }
    // }
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

