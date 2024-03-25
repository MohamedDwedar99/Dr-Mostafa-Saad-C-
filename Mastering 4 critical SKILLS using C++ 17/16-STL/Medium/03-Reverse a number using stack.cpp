#include<iostream>
#include<stack>
using namespace std;


int reverse_num(int num)
{
    stack<int> st;
    while(num > 0)
        st.push(num%10),num/=10;
    int factor =1;
    while(!st.empty())
    {
        num = num + factor*st.top();
        factor*=10;
        st.pop();
    }
    return num;
}
int main(void)
{
    cout << reverse_num(1234);
    return 0;
}