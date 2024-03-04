/*
 * Fixed_Sliding_Window.cpp
 *
 *  Created on: Feb 29, 2024
 *      Author: Mohamed Dwedar
 */



#include <iostream>
using namespace std;


//int main(void)
//{
//	int list[] = {1,0,3,-4,2,-6,9};
//	int size = sizeof(list)/sizeof(list[0]);
//	int sub_list = 3;
//	int max = 0;
//	for (int i = 0; i < sub_list;i++)
//	{
//		max += list[i];
//	}
//	int slid = max;
//  int min_index;
//	for (int i = sub_list; i < size;i++)
//	{
//		slid = slid -list[i-sub_list]+list[i];
//		if (slid > max)
//		{
//			max = slid;
//          min_index = i-sub_list;
//		}
//	}
//	cout << min_index+1<<" " <<min_index+sub_list <<" "<<max;
//	return 0;
//}

/**** Accumilation *****/
int main(void)
{
	int list[] = {1,0,3,-4,2,-6,9};
	int size = sizeof(list)/sizeof(list[0]);
	int sub_list = 3;
	int max = 0;
	for (int i = 1;i < size;i++)
	{
		list[i] += list[i-1];
	}
	int min_index;
	for (int i = sub_list; i < size;i++)
	{
		if (list[i] - list[i-sub_list] > max)
		{
			max = list[i]- list[i-sub_list];
			min_index = i-sub_list;
		}
	}
	cout << min_index+1<<" " <<min_index+sub_list <<" "<<max;
	return 0;
}
