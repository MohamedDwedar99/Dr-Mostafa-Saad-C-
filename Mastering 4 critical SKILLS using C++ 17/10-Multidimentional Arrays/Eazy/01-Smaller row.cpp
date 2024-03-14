#include <iostream>
using namespace std;

int main(void)
{
    int arr[100][100];
    int N,M;
    cin >> N >> M;
    for (int i = 0; i < N;i++)
    {
        for (int j =0; j < M ; j++)
        {
            cin >> arr[i][j];
        }
    }
    int Q;
    cin >> Q;
    for (int k = 0; k < Q; k++)
    {
        int r1,r2;
        bool flag = true;
        cin >> r1 >> r2;
        for (int i = 0; i < M; i++)
        {
            if (arr[r1-1][i] > arr[r2-1][i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}