#include <iostream>
using namespace std;

int path_sum(int grid[100][100], int row, int col,int ROWS,int COLS)
{
    int di[3] = {0,1,1};
    int dj[3] = {1,0,1};
    if (row == ROWS-1 && col == COLS-1)
        return grid[row][col];
    int max = grid[row+di[0]][col+dj[0]];
    int k = -1;
    for (int i = 0; i < 3; i++)
    {
        if (row+di[i] > ROWS-1 ||col+dj[i] > COLS-1)
        {
            continue;
        }
        if (grid[row+di[i]][col+dj[i]] >= max)
        {
            max = grid[row+di[i]][col+dj[i]];
            k = i;
        }
    }
    return grid[row][col]+path_sum(grid,row+di[k],col+dj[k],ROWS,COLS);
}
int main(void)
{
    int N,M;
    int arr[100][100];
    cin >> N >> M;
    for (int i = 0; i < N;i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << path_sum(arr, 0, 0,N,M);
}