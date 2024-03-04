/*
 * Count_increasing_subarray.cpp
 *
 *  Created on: Feb 29, 2024
 *      Author: Mohamed Dwedar
 */


#include <iostream>
using namespace std;

#define SIZE 4
int main (void)
{
	int arr[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		cin >> arr[i];
	}
	int temp_count = 1;
	int count = 0;
	for (int i = 1; i < SIZE+1; i++)
	{
		if (arr[i] > arr[i-1] && i < SIZE)
		{
			temp_count++;
		}
		else
		{
			count += (temp_count *(temp_count+1))/2;
			temp_count = 1;
		}
	}
	cout << count;
	return 0;
}

