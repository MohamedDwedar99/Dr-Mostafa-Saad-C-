#include <iostream>
using namespace std;


double average(int arr[],int len)
{
    int max = arr[len-1];
    if (len == 1)
        return arr[0];
    
    return (arr[len-1] + average(arr,len-1)*(len-1))/len;
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
    cout << average(arr,len);
    return 0;
}