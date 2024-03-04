#include <iostream>
using namespace std;

int main(void)
{
    string Letters;
    int arr[28] = {0};
    cin >> Letters;
    for (int i =0; i < Letters.size();i++)
    {
        if (Letters[i] >= 'a' && Letters[i] <= 'z')
        {
            arr[Letters[i]-'a']++;
        }
    }
    for (int i =0; i < 28;i++)
    {
        if (arr[i] > 0)
        {
            cout << (char)(i+'a') << " "<< arr[i]<<endl;
        }
    }
    return 0;
}