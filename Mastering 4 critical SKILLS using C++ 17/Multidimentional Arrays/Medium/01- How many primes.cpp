#include <iostream>
using namespace std;


int main(void)
{
    int prime_arr[100][100];
    int N,M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int val;
            cin >> val;
            if (val > 1)
            {
                prime_arr[i][j] = 1;
                for (int k = 2; k < val/2;k++)
                {
                    if (val%k == 0)
                    {
                        prime_arr[i][j] = 0;
                        break;
                    }
                }
            }
        }

    }
    int Q;
    cin >> Q;
    for (int k = 0; k < Q; k++)
    {
        int i,j,r,c;
        int count = 0;
        cin >> i >> j >> r >> c;
        for (int row = i;row <= r; row++)
        {
            for (int col = j;col < c;col++)
            {
                count+= prime_arr[row][col];
            }
        }
        cout << count << endl;
    }
    return 0;
}