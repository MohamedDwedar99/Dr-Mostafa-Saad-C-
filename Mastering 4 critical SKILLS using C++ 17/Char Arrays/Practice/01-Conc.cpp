
#include <iostream>
using namespace std;



int main(void)
{
    string S;
    string T;
    cin >> S>>T;
    int MaxSize = S.size();
    if (T.size() > MaxSize)
    {
        MaxSize = T.size();
    }
    for (int i = 0; i < MaxSize;i++)
    {
        if (i < S.size())
        {
            cout << S[i];
        }
        if (i <T.size())
        {
            cout << T[i];
        }
    }
    cout << endl;
    return 0;
}