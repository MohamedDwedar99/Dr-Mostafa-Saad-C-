#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverse_queue(queue<int> &q)
{
    stack<int> st;
    while(!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
}
void Print_queue(queue<int> &q)
{
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}

int main(void)
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    reverse_queue(q);
    Print_queue(q);
    return 0;
}