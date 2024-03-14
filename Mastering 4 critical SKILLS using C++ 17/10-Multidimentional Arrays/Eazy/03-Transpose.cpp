#include <iostream>
using namespace std;

int main(void)
{
    int arr[100][100];
    int t_arr[100][100];
    int N,M;
    cin >> N >> M;
    for (int i = 0; i < N;i++)
    {
        for (int j =0; j < M ; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < N;i++)
    {
        for (int j =0; j < M ; j++)
        {
            t_arr[j][i] = arr[i][j];
        }
    }
    for (int i = 0; i < M;i++)
    {
        for (int j =0; j < N ; j++)
        {
            cout << t_arr[i][j] <<" ";
        }
        cout << endl;
    }
    return 0;
}