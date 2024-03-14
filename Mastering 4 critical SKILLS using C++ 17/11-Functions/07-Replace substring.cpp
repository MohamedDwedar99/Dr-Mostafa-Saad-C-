#include <iostream>
using namespace std;

bool starts_with(string input,string pattern, int pos)
{
    bool equal = true;
    for (int i = 0; i < pattern.size(); i++)
    {
        if (input[pos+i] != pattern[i])
        {
            equal = false;
            break;
        }
    }
    return equal;
}
string replace_str(string input,string pattern, string to)
{
    static string input_ret(1000,0);
    int i = 0;
    int j = 0;
    while (i < input.size())
    {
        if (starts_with(input,pattern,i))
        {
            for (int k = 0; k < to.size();k++)
            {
                input_ret[j] = to[k];
                j++;
            }
            i+= pattern.size();
        }
        else
        {
            input_ret[j] = input[i];
            j++;
            i++;
        }
    }
    return input_ret;
}
int main(void)
{
    string input,pattern,to,ret;
    getline(cin,input);
    getline(cin,pattern);
    getline(cin,ret);
    ret = replace_str(input, pattern, to);
    cout << ret << endl;
    return 0;
}