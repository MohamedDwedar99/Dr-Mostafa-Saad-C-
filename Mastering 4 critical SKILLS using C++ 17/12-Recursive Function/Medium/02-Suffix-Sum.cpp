#include <iostream>
using namespace std;



int suffex_sum(int arr[], int len, int start_position = 0)
{
    if (start_position == len-1)
        return arr[len-1];
    return arr[start_position]+suffex_sum(arr,len,start_position+1);
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
    cout << suffex_sum(arr,len,2);

    return 0;
}