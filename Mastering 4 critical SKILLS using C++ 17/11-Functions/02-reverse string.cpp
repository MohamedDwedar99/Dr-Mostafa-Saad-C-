#include <iostream>
using namespace std;

string reverse_str(const string str)
{
    int size = str.size();
    string str2(size,' ');
    for (int i = 0; i < size;i++)
    {
        str2[i] = str[size-i-1];
    }
    return str2;
}

int main(void)
{
    string str;
    cin >> str;
    str = reverse_str(str);
    cout << str <<endl;
    return 0;
}