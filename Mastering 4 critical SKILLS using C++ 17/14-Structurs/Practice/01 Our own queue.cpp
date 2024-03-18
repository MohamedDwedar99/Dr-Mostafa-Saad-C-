#include <iostream>
using namespace std;


struct queue {
    int arr[100];
    int len;
    queue(void)
    {
        len = 0;
    }
    void add_end(int value)
    {
        arr[len] = value;
        len++;
    }
    void add_front(int value)
    {
        for (int i = len; i > 0; i--)
        {
            arr[i] = arr[i-1];
        }
        arr[0] = value;
        len++;
    }
    int remove_front(void)
    {
        int ret = arr[0];
        for (int i = 0; i < len-1; i++)
        {
            arr[i] = arr[i+1];
        }
        len--;
        return ret;
    }
    void print(void)
    {
        for (int i = 0; i < len; i++)
        {
            cout << arr[i] <<" ";
        }
        cout <<endl;
    }
    
};


int main (void)
{
    queue x;
    for (int i = 0; i < 5; i++)
    {
        x.add_end(i);
        x.print();
    }
    for (int i = 5; i < 10; i++)
    {
        x.add_front(i);
        x.print();
    }
}