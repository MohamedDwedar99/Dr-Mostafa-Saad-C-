#include <iostream>
using namespace std;


int main(void)
{
    // taking array Dimentions
    char arr[9][9] = {0};
    int N = 0;
    // All directions vertical , horizontal, diagonal right, diagonal left
    int di[8] = { 0, 0, 1,-1, 1,-1, 1,-1};
    int dj[8] = { 1,-1, 0, 0, 1,-1,-1, 1};
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
    while (!End)
    {
        int r,c;
        int player = 0;
        bool valid = false;
        // Take & Check input validity
        while (!valid)
        {
            if (turn)
            {
                player = 'x';
                cout << "Player x trun. ";
            }
            else
            {
                player = 'o';
                cout << "Player o trun. ";
            }
            cout << "Enter empty location (r , c)\n";
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
            int currnt_i = r;
            int currnt_j = c;
            while (currnt_i < N && currnt_i >= 0 && currnt_j < N && currnt_j >= 0)
            {
                if (arr[r][c] == arr[currnt_i][currnt_j])
                {
                    stp_count++;
                }
                else
                {
                    break;
                }
                currnt_i = currnt_i + di[d];
                currnt_j = currnt_j + dj[d];
            }
            currnt_i = r + di[2*d+1];
            currnt_j = c + dj[2*d+1];
            while (currnt_i < N && currnt_i >= 0 && currnt_j < N && currnt_j >= 0)
            {
                if (arr[r][c] == arr[currnt_i][currnt_j])
                {
                    stp_count++;
                }
                else
                {
                    break;
                }
                currnt_i = currnt_i + di[2*d+1];
                currnt_j = currnt_j + dj[2*d+1];
            }
            if (stp_count == N)
            {
                End = true;
                if (turn)
                {
                    std::cout << "Play x win" << std::endl;
                }
                else
                {
                    std::cout << "Play o win" << std::endl;
                }
                break;
            }
        }
        //Check Draw
        bool Draw = true;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (arr[i] == 0)
                {
                    Draw = false;
                    break;
                }
            }
        }
        if (Draw)
        {
            cout << "Draw\n";
        }
        //Switch turn
        turn = (turn+1)%2;
    }
    return 0;
}

 