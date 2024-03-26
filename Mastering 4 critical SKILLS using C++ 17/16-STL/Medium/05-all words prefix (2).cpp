#include<iostream>
#include<map>
#include<set>
using namespace std;

void add_name(map<string, set<string>> &name)
{
    string _name;
    cin >> _name;
    for (int i = 0; i < _name.size(); i++)
    {
        string ilias = "";
        for (int j = 0; j < i+1; j++)
        {
            ilias += _name[j];
        }
        name[ilias].insert(_name);
    }
}
void print_name(map<string, set<string>> &name)
{
    string _name;
    cin >> _name;
    //auto it = name[_name].begin();
    for (auto it : name[_name])
    {
        cout << it <<" ";
    }
    cout <<endl;
     
}

int main(void)
{
    map<string, set<string>> name;
    int x;
    while(1)
    {
        cout << "1-Add name: \n";
        cout << "2-Search Prefix: \n";
        cout << "Your Choice: ";
        cin >>x;
        if (x == 1)
            add_name(name);
        else
        {
            print_name(name);
        }

    }   
    return 0;
}