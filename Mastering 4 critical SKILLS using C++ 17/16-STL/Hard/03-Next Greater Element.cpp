#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> next_greater_num(vector<int>& v) {
    vector<int> result(v.size(),-1);
    stack<int> pos;
    for (int i = 0; i < (int)v.size();i++)
    {
        while(!pos.empty() && v[pos.top()] < v[i])
        {
            result[pos.top()] = v[i];
            pos.pop();
        }
        pos.push(i);
    }
    return result;
}
vector<int> next_greater_num(vector<int>& v) {
    vector<int> result;
    for (int i  = 0;)
}

int main() {
	vector<int> v = { 73, 74, 75, 71, 69, 72, 76, 73 };
	v = next_greater_num(v);

	for (auto x : v)
		cout << x << " ";
	return 0;
}
