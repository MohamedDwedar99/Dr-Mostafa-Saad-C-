
#include <iostream>
using namespace std;
int main() {
	int arr_index[10000] = {0};
	int arr[200] = {0};
	for (int i = 0; i < 200-1;i++)
	{
		int temp = arr[i] - i - 1;
		if (temp > 0 && arr_index[temp] == 0 )
		{
			arr[i+1] = temp;
		}
		else
		{
			arr[i+1] = arr[i] + i +1;
		}
		arr_index[arr[i+1]] = 1;
		cout << arr[i] << ", ";
	}
	cout << arr[199] ;
	return 0;
}
