#include <iostream>
#include <fstream>
using namespace std;


int main(){
    ifstream fin("rtext.file");
    if (fin.fail())
    {
        cout << "Not fount";
        return 0;
    }
    int x,y;
    fin >> x >> y;
    fin.close();
    ofstream fout("wtext.file");
    if (fout.fail())
    {
        cout << "Not fount";
        return 0;
    }
    fout << x+y;
    fout.close();
    return 0;
}