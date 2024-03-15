#include <iostream>
using namespace std;


int main(void)
{
    // taking array Dimentions
    char arr[9][9] = {0};
    int N = 0;
    // All directions vertical , horizontal, diagonal right, diagonal left and starting array 
    int di[4] = {1,0,1, 1};
    int dj[4] = {0,1,1,-1};
    int si[4] = {0,1,0,0};
    int sj[4] = {1,0,0,N-1};
    while (true)
    {
        cin >> N;
        if (N >= 3 && N <= 9)
        {
            break;
        }
        else
        {
            cout << "Wrong choice try again\n";
        }
    }
    bool End = false;
    char turn = 1;
    int Draw = 0;
    while (!End)
    {
        int r,c;
        char player = 0;
        bool valid = false;
        // Take & Check input validity
        while (!valid)
        {
            //Check Draw
            if (Draw == N*N)
            {
                cout << "Draw\n";
                break;
            }
            if (turn)
            {
                player = 'x';
            }
            else
            {
                player = 'o';
            }
            cout << "Player " << player <<" trun. Enter empty location (r , c)\n";
            cin >> r >> c;
            if (r >= 1 && r <= N && c >= 1 && c <= N)
            {
                r-=1;
                c-=1;
                if (arr[r][c] == 0)
                {
                    arr[r][c] = player;
                    valid = true;
                }
                else
                {
                    cout << "Invalid Input try again\n";
                }
            }
            else
            {
                cout << "Invalid Input try again\n";
            }
        }
        // print game grid
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (arr[i][j] == 0)
                {
                    cout << "-";
                }
                else
                {
                    cout << arr[i][j];
                }
            }
            cout << endl;
        }
        //check Winner
        for (int d = 0; d < 4; d++)
        {
            int stp_count = 0;
            int current_i = si[d] * r;
            int current_j = sj[d] * c;
            for (int k = 0; k < N;k++)
            {
                if (arr[current_i][current_j] == arr[r][c])
                    stp_count++;
                else
                    break;
                current_i += di[d];
                current_j += dj[d];
            }
            if (stp_count == N)
            {
                End = true;
                cout << "Play "<<player<<" win" << endl;
                break;
            }
        }
        //Check Draw
        Draw++;
        //Switch turn
        turn = (turn+1)%2;
    }
    return 0;
}

 