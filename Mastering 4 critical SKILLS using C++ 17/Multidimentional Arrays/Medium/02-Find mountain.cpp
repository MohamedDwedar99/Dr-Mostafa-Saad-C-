#include <iostream>
using namespace std;


int main(void)
{
    int arr[100][100];
    int di[8] = { 1, 1, 0,-1,-1,-1, 0, 1};
    int dj[8] = { 0, 1, 1, 1, 0,-1,-1,-1};
    int N,M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            bool mont = true;
            for (int k = 0; k < 8;k++)
            {
                int ni = i +di[k];
                int nj = j +dj[k];
                if (ni < 0 || ni > N-1|| nj < 0 || nj > M-1)
                {
                    continue;
                }
                if (arr[ni][nj] >= arr[i][j])
                {
                    mont = false;
                    break;
                }
            }
            if (mont)
            {
                std::cout << i << " " << j << std::endl;
            }
        }
    }
    return 0;
}