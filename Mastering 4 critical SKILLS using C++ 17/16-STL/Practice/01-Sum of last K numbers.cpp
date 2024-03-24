#include <iostream>
#include <queue>
using namespace std;

typedef struct SUM_LAST{
    int sum;
    int k;
    queue<int> q;
    SUM_LAST(void){
        sum = 0;
        cout << "Enter Number of sum: ";
        cin >> k;
    }
    void Count_sum(void)
    {
        int num;
        cin >> num;
        sum+= num;
        if (q.size() >= k)
        {
            sum -= q.front();
            q.pop();
            q.push(num);
        }
        else
        {
            q.push(num);
        }
        cout << sum << endl;
    }
}SUM_LAST_st;



int main(void)
{
    SUM_LAST_st Sum;
    while(1)
    {
        Sum.Count_sum();
    }
}