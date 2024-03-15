#include <iostream>
using namespace std;


void Left_max(int arr[],int len)
{
    int max = arr[len-1];
    if (len == 1)
    {
        return;
    }
    else
    {
        Left_max(arr,len-1);
        if (arr[len-1] < arr[len-2])
        {
            arr[len-1] = arr[len-2];
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
    Left_max(arr,len);
    for (int i = 0; i < len; i++)
    {
        cout << arr[i]<< " ";
    }
    cout << endl;
    return 0;
}