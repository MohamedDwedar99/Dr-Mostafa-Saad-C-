#include <iostream>
#include <stack>
#include <map>
using namespace std;

bool chack_par(string str){
    map<char,char> ck;
    stack<char> open;
    ck[')'] = '(';
    ck[']'] = '[';
    ck['}'] = '{';
    stack<char> para;
    bool flag = true;
    for (auto i : str)
    {
        if (para.empty())
        {
            flag = false;
            break;
        }
        if (i == '{' || i == '(' || i == '[')
        {
            open.push(i);
        }
        else
        {
            if (open.top() != ck[i])
            {
                flag = false;
                break;
            }
            open.pop();
        }
    }
    if (flag && !para.empty())
        flag = false;
    return flag;
}

int main(void)
{
    string str;
    cin >> str;
    cout << boolalpha;
    cout << chack_par(str);
    return 0;
}