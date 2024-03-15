#include <iostream>
using namespace std;


void array_increment(int arr[],int len)
{
    int max = arr[len-1];
    if (len == 1)
    {
        return;
    }
    else
    {
        arr[len-1]+= len-1;
        array_increment(arr,len-1);
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
    array_increment(arr,len);
    for (int i = 0; i < len; i++)
    {
        cout << arr[i]<< " ";
    }
    cout << endl;
    return 0;
}