
#include <iostream>
using namespace std;



int main(void)
{
    string ch_map ="YZIMNESTODUAPWXHQFBRJKCGVL";
    string nm_map = "!@#$%^&*()";
    string arr;
    cin >> arr;
    for (int i =0; i < arr.size();i++)
    {
        if (arr[i] >= 'a' && arr[i] <= 'z')
        {
            cout << ch_map[arr[i]-'a'];
        }
        else if (arr[i] >= '0' && arr[i] <= '9')
        {
            cout << nm_map[arr[i]-'0'];
        }
        else
        {
            cout << arr[i];
        }
    }
    cout <<endl;
    return 0;
}