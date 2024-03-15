#include <iostream>
using namespace std;

bool Is_Plaindrome(int arr[],int len,int start = 0)
{
    if (start == len/2 && start%2 == 0)
        return true;
    bool state = true;
    if (arr[start] != arr[len-start-1])
        return false;
    return state && Is_Plaindrome(arr,len,start+1);
}


int main (void)
{
    int arr[100];
    int len;
    cin >> len;
    for (int i =0; i < len; i++)
    {
        cin >> arr[i];
    }
    cout << boolalpha<<Is_Plaindrome(arr, len);
    return 0;
}