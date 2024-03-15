#include <iostream>
using namespace std;


int arr_sum(int arr[],int len)
{
    int max = arr[len-1];
    if (len == 1)
    {
        return arr[0];
    }
    else
    {
        return arr[len-1] + arr_sum(arr,len-1);
    }
}

int main(void)
{
    int arr[100];
    int len;
    cin >> len;
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }
    cout << arr_sum(arr,len);
    return 0;
}