#include<iostream>
#include<queue>
using namespace std;


struct MyStack{
    queue<int> st;
    void push(int val)
    {
        int i = st.size();
        st.push(val);
        while(i--)
            st.push(st.front()),st.pop();
    }
    void pop(void)
    {
        if (!st.empty())
            st.pop();
    }
    int top(void)
    {
        return st.front();
    }
    bool empty(void)
    {
        return st.empty();
    }
};

int main(void)
{
    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    while(!s.empty())
        cout << s.top() << " ",s.pop();
    return 0;
}