#include<iostream>
#include<stack>
using namespace std;

void removeDuplicates(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        bool flag = true;
        for (int j = 0; j < i; j++)
        {
            if (s[i] == s[j])
                flag = false;
        }
        if (s[i] == s[i+1])
        {
            flag = false;
            i++;
        }
        if (flag)
        {
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        cout << st.top();
        st.pop();
    }
}

int main(void)
{
    string s;
    getline(cin,s);
    removeDuplicates(s);
    return 0;
}