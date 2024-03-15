#include <iostream>
using namespace std;



void left_max(int arr[], int len, int start_position = 0)
{
    if (start_position == len-1)
        return;
    left_max(arr,len,start_position+1);
    arr[start_position] = max(arr[start_position+1],arr[start_position]);
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
    left_max(arr,len);
    for (int i =0; i < len; i++)
    {
        cout << arr[i];
    }
    return 0;
}