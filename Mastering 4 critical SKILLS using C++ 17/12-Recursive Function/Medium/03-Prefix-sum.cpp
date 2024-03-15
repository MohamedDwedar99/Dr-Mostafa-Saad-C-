#include <iostream>
using namespace std;



int Prefix_sum(int arr[], int end_position )
{
    if (end_position == 1)
        return arr[end_position-1];
    return arr[end_position-1]+Prefix_sum(arr,end_position-1);
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
    cout << Prefix_sum(arr,3);

    return 0;
}