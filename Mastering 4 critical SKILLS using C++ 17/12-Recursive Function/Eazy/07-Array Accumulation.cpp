#include <iostream>
using namespace std;


void accumulate_arr(int arr[],int len)
{
    int max = arr[len-1];
    if (len == 1)
        return;
    
    accumulate_arr(arr,len-1);
    arr[len-1] += arr[len-2];
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
    accumulate_arr(arr,len);
    for (int i = 0; i < len; i++)
    {
        cout << arr[i]<< " ";
    }
    cout << endl;
    return 0;
}