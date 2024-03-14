#include <iostream>
using namespace std;

int max(int a,int b,int c);
int max(int a,int b,int c,int d);
int max(int a,int b,int c,int d,int e);
int max(int a,int b,int c,int d,int e,int f);

int main(void)
{
    int m = max(2,4,3,5,1,0);
    cout << m;
    return 0;
}


int max(int a,int b,int c)
{
    return max(a,max(b,c));
}
int max(int a,int b,int c,int d)
{
    return max(a,max(b,c,d));
}
int max(int a,int b,int c,int d,int e)
{
    return max(max(a,b,c),max(d,e));
}
int max(int a,int b,int c,int d,int e,int f)
{
    return max(max(a,b,c),max(d,e,f));
}
