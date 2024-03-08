#include <iostream>
using namespace std;

int main(void)
{
    string group;
    getline(cin,group);
    cout << group[0];
    for (int i = 1; i < group.size();i++)\
    {
        if (group[i] != group[i-1])
        {
            cout <<" ";
        }
        cout << group[i];
    }
}