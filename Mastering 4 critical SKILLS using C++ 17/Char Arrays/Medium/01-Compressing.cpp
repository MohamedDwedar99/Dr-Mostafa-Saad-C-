#include <iostream>
using namespace std;


 int main(void) {
    string str;
    getline(cin,str);
    for(int i = 0,j = 0;i < str.size();i++)
    {
        if (i == 0 || str[i] == str[i-1])
        {
            j++;
        }
        else
        {
            std::cout << str[i-1]<<j<<"_";
            j = 1;
        }
        if (i == str.size()-1)
        {
            if (j == 0)
            {
                j = 1;
            }
            std::cout << str[i]<<j<< std::endl;
        }
    }
    return 0;
}