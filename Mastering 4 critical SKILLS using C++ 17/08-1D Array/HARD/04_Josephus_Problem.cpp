#include <iostream>
using namespace std;


int main(void)
{
	int size,pitch;
	cin >> size >> pitch;
	int count = size;
	int arr[size];
	int ptr = -1;
	for (int i = 0; i < size; i++)
	{
		arr[i] = 1;
	}
	while (count > 0)
	{
		int internal_count = pitch;
		while (internal_count > 0)
		{
			ptr = (ptr+1)%size;
			if (arr[ptr] == 1)
			{
				internal_count--;
			}
		}
		cout << ptr+1<<" ";
		arr[ptr] = 0;
		count--;
	}
	return 0;
}
