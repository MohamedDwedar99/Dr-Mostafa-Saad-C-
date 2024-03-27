#include <iostream>
#include <stack>
using namespace std;

int Score_Par(string &par)
{
    stack<int> st;
    st.push(0);
    for (auto i : par)
    {
        if (i == '(')
        {
            st.push(0);
        }
        else
        {
            int last = st.top();
            st.pop();
            if (last == 0)
                last = 1;
            else
                last *=2;

            int parent = last + st.top();
            st.pop();
            st.push(parent);
        }
    }
    return st.top();
}

int main(void)
{
    string par;
    cin >> par;
    cout <<   Score_Par(par); 
}