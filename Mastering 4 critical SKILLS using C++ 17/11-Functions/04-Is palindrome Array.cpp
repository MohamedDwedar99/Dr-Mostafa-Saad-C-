#include <iostream>
using namespace std;

void Is_Palindrome(const int arr[],int size)
{
    for (int i = 0; i < size / 2; i++) {
	    if (arr[i] != arr[size - 1 - i]) {
			cout << "NO";
            return;
		}
	}
	cout << "YES";
}
int main() {
	int arr[999];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
    Is_Palindrome(arr,N);
    return 0;
}