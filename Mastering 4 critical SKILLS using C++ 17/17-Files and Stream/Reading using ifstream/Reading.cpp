#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("file.txt");
    if(fin.fail())
    {
        cout << "Can't Open file";
        return 1;
    }
    int x,y;
    fin >> x >> y;
    cout << x + y;
    fin.close();
    return 0;
}