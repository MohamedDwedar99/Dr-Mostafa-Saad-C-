#include <iostream>
using namespace std;

bool Is_prefix(string main,string prefix,int start_pos = 0)
{
    if (prefix[start_pos] == 0)
        return true;
    if (main[start_pos] != prefix[start_pos])
        return false;
    return Is_prefix(main,prefix,start_pos+1);
}


int main (void)
{
    string main,prefix;
    getline(cin,main,' ');
    getline(cin,prefix,'\n');
    cout << boolalpha << Is_prefix(main,prefix);
    return 0;
}