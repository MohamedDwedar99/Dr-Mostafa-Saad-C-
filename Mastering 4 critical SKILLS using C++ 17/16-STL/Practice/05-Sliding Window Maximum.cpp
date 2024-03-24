#include <iostream>
#include <stack>
#include <set>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ret;
    multiset<int> ms;
    if (nums.size() < k)
        return ret;
    for (int i = 0; i < k; i++)
    {
        ms.insert(nums[i]);
    }
    ret.push_back(*(--ms.end()));
    for (int i = k; i < (int)nums.size(); ++i)
    {
        ms.erase(ms.find(-nums[i-k]));
        ms.insert(nums[i]);
        ret.push_back(*(--ms.end()));
    }
    return ret;
}

int main(void)
{
    vector<int> in{1,3,-1,-3,5,3,6,7};
    vector<int> out = maxSlidingWindow(in,3);
    for (auto i:out)
    {
        cout << i << endl;
    }
    return 0;
}