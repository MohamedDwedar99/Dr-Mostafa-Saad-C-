#include <iostream>
using namespace std;

int main(void)
{
    int arr[100][100];
    int N;
    int upper = 0,lower = 0;
    cin >> N;
    for (int i = 0; i < N;i++)
    {
        for (int j =0; j < N ; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N;i++)
    {
        for (int j =0; j < N ; j++)
        {
            if (j >= i)
            {
                upper+=arr[i][j];
            }
            if (j <= i)
            {
                lower+=arr[i][j];
            }
        }
    }
    cout << lower << endl;
    cout << upper << endl;
    return 0;
}