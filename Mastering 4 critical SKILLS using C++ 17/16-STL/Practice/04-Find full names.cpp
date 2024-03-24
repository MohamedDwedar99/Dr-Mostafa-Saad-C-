#include <iostream>
#include <stack>
#include <map>
#include <vector>
using namespace std;

void Add_Names(map<string,vector<string>> &mp)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int len;
        cin >> len;
        string full_name = "";
        string str;
        vector<string> names;
        for (int j = 0; j < len; j++)
        {
            cin >> str;
            if (j)
                full_name += " ";
            full_name += str;
            names.push_back(full_name);
        }
        for (auto str:names)
            mp[str].push_back(full_name);
    }
}

void Query_Names(map<string,vector<string>> &mp)
{
    int q;
    cin >> q;
    while(q--)
    {
        int len;
        cin >> len;
        string full_name = "";
        string str;
        for (int i = 0; i < len; i++)
        {
            cin >> str;
            if (i)
                full_name += " ";
            full_name += str;
        }
        if (mp.count(full_name))
        {
            for (auto i : mp[full_name])
                cout << i <<endl;
        }
        else
        {
            cout <<"Not Found" << endl;
        }

    }
}
int main(void)
{
    map<string,vector<string>> mp;
    Add_Names(mp);
    Query_Names(mp);
    return 0;
}