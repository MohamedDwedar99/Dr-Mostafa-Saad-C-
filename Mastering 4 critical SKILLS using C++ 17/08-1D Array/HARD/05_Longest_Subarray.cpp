/*
 * 05_Longest_Subarray.cpp
 *
 *  Created on: Mar 1, 2024
 *      Author: Mohamed Dwedar
 */

#include <iostream>
using namespace std;


/**********brute force*************/
// int main (void)
// {
//     int n;
//     int a[999];
//     cin >> n;
//     for (int i = 0; i < n;i++)
//     {
//         cin >> a[i];
//     }
//     int maxSubarrayLen = 0;
//     int maxSubarraySrt;
//     int maxSubarrayEnd;
//     for (int start = 0; start < n;start++)
//     {
//         for (int end = start; end < n;end++)
//         {
//             int one_count = 0;
//             int zero_count = 0;
//             for (int i = start; i < end; i++)
//             {
//                 if (a[i] )
//                 {
//                     one_count++;
//                 }
//                 else 
//                 {
//                     zero_count++;
//                 }
//             }
//             if (one_count == zero_count)
//             {
//                 int subArraylen = end-start+1;
//                 if (subArraylen > maxSubarrayLen)
//                 {
//                     maxSubarrayLen = subArraylen;
//                     maxSubarraySrt = start;
//                     maxSubarrayEnd = end;
//                 }
//             }
//         }
//     }
//     cout << "start: "<<maxSubarraySrt << " end: "<<maxSubarrayEnd << " Len: "<<maxSubarrayLen;
// }

/********** More Efficent Two loops brute force*************/

// int main (void)
// {
//     int n;
//     int a[999];
//     cin >> n;
//     for (int i = 0; i < n;i++)
//     {
//         cin >> a[i];
//     }
//     int maxSubarrayLen = 0;
//     int maxSubarraySrt;
//     int maxSubarrayEnd;
//     for (int start = 0; start < n;start++)
//     {
//         int sum = 0;
//         for (int end = start; end < n;end++)
//         {
//             if (a[end] == 0)
//             {
//                 sum--;
//             }
//             else
//             {
//                 sum++;
//             }
//             if (sum == 0 && maxSubarrayLen < end-start+1)
//             {
//                 maxSubarrayLen = end-start+1;
//                 maxSubarraySrt = start;
//                 maxSubarrayEnd = end;
//             }
//         }
//     }
//     cout << "start: "<<maxSubarraySrt << " end: "<<maxSubarrayEnd << " Len: "<<maxSubarrayLen;
// }



/********** Accumilation solution*************/

int main (void)
{
    int a[1000];
    int N;
    cin >> N;
    for (int i = 0; i < N;i++)
    {
        cin >> a[i];
    }
    int diff[2*N+1];
    for (int i = 0; i < 2*N+1;i++)
    {
        diff[i] = 999999;
    }
    diff[N] = -1; 
    /* First appear of Zero Was in -1
    *     0  1  0  1  0
    *  0 -1  0 -1  0 -1
    */
    int maxSubArrayLen = 0;                                                 
    int MaxSubArrayStr;
    int MaxSubArrayEnd;
    int add = 0;
    for (int i = 0; i < N;i++)
    {
        if (a[i] == 0)
        {
            add--;
        }
        else
        {
            add++;
        }
        int shift = add+N;
        if (diff[shift] == 999999)
        {
            diff[shift] = i;
        }
        else if (maxSubArrayLen < i - diff[shift])
        {
            maxSubArrayLen = i - diff[shift];
            MaxSubArrayStr = diff[shift]+1;
            MaxSubArrayEnd = i;
        }
    }
    if (maxSubArrayLen == 0)
    {
        std::cout << "Not Found" << std::endl;
    }
    else
    {
        cout << "start: "<<MaxSubArrayStr << " end: "<<MaxSubArrayEnd << " Len: "<<maxSubArrayLen;
    }

}