#include <iostream>
using namespace std;


int arr_max(int arr[],int len)
{
    int max = arr[len-1];
    if (len == 1)
    {
        return arr[0];
    }
    else
    {
        if (arr[len-1] > arr_max(arr,len-1))
        {
            return arr[len-1];
        }
        else
        {
            return arr_max(arr,len-1);
        }
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
    cout << arr_max(arr,len);
    return 0;
}