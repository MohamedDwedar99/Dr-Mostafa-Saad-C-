#include <iostream>
using namespace std;


int main(void)
{   
    int di[4] = { -1, 0, 1, 0};
    int dj[4] = { 0, 1, 0,-1};
    int N,M;
    int curnt[2] = {0,0};
    cin >> N >> M;
    int it;
    cin >> it;
    while (it > 0)
    {
        int stps,dir;
        cin >> dir >> stps;
        dir-=1;
        curnt[0] += stps*di[dir];
        curnt[1] += stps*dj[dir];
        if (curnt[0] > N-1)
            curnt[0] %= N;        
        else if (curnt[0] < 0)
            curnt[0] = N - (-curnt[0]%N);
        if (curnt[1] > M-1)
            curnt[1] %= M;
        else if (curnt[1] < 0)
            curnt[1] = M - (-curnt[1]%M);
        cout << "(" << curnt[0]<<","<<curnt[1]<<")\n";
        it--;
    }
    return 0;
}