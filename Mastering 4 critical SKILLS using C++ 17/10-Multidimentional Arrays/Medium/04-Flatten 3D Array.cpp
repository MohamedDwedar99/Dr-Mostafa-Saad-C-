#include <iostream>
using namespace std;


int main(void)
{
    int D,R,C;
    int Mode;
    cin >> D>>R>>C>>Mode;
    int D_c = R*C;
    int R_c = C;
    if (Mode == 1)
    {
        int d,r,c;
        cin >> d>>r>>c;
        int D1_index = D_c*d + R_c*r + c;
        cout << D1_index; 
    }
    else if (Mode == 2)
    {
        int D1_index;
        int d,r,c;
        cin >> D1_index;
        d = D1_index/D_c;
        r = (D1_index%D_c)/R_c;
        c = (D1_index%D_c)%R_c;
        cout << d << r << c;
    }
    return 0;
}