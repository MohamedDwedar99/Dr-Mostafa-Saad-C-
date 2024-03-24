#include <iostream>
#include <vector>
using namespace std;

void stack_push(vector<int> & STC , char name)
{
    int count;
    cout << "Enter Stack " << name << " count: ";
    cin >> count;
    for (int i = count; i > 0; i--)
    {
        cout <<"Member " << count - i +1 << ": ";
        int x;
        cin >> x;
        STC.push_back(x);
    }
}
int sum_stack(vector<int> &STC)
{
    int sum = 0;
    for (auto i : STC){
        sum+= i;
    }
    return sum;
}
int Max_sum(vector<int> &A,vector<int> &B,vector<int> &C)
{
    int sa = sum_stack(A);
    int sb = sum_stack(B);
    int sc = sum_stack(C);
    while(!A.empty() && !B.empty() && !C.empty())
    {
        if (sa == sb && sb == sc)
        {
            return sa;
        }
        if (sa >= sb && sa >= sc)
        {
            sa -= A.back();
            A.pop_back();
        }
        else if (sb >= sa && sb >= sc)
        {
            sb -= B.back();
            B.pop_back();
        }
        else
        {
            sc -= C.back();
            C.pop_back();
        }
    }
    return 0;
}
int main(void)
{
    vector<int> A;
    vector<int> B;
    vector<int> C;
    stack_push(A,'A');
    stack_push(B,'B');
    stack_push(C,'C');
    cout << Max_sum(A,B,C);
    return 0;
}
