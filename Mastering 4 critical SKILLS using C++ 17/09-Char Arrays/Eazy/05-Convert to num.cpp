#include <iostream>
using namespace std;

int main(void)
{
    string ch_num;
    getline(cin,ch_num);
    int num = 0;
    for (int i = 0; i < ch_num.size();i++)
    {
        num = num*10 + (ch_num[i]-'0');
    }
    std::cout <<num << " " << num * 3<<std::endl;
}