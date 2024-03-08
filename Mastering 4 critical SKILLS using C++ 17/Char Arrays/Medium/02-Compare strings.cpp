#include <iostream>
using namespace std;


//  int main(void) {
//     string str1,str2;
//     cin >> str1>>str2;
//     int size;
//     int flag = 1;
//     if (str1.size() < str2.size())
//     {
//         size = str1.size();
//     }
//     else
//     {
//         size = str2.size();
//     }

//     for (int i = 0; i < size; i++)
//     {
//         if (str1[i] > str2[i])
//         {
//             flag = 0;
//             break;
//         }
//     }
//     if (flag == 1)
//     {
//         if (str1.size() <= str2.size())
//         {
//             std::cout << "YES" << std::endl;
//         }
//         else if (str1[size-1] < str2[size-1])
//         {
//             std::cout << "YES" << std::endl;
//         }
//         else
//         {
//             std::cout << "NO" << std::endl;
//         }
//     }
//     else
//     {
//         std::cout << "NO" << std::endl;
//     }
//     return 0;
// }


/***************Another solution***************/

 int main(void) {
    string str1,str2;
    cin >> str1>>str2;
    int size = str1.size();
    if (size > str2.size())
        size = str2.size();
    int smaller = -1;

    for (int i = 0; i < size && smaller == -1;i++)
    {
        if (str1[i] != str2[i])
        {
            if (str1[i] < str1[2])
                smaller = 1;
            else
                smaller = 0;
        }
    }
    if (smaller == -1)
    {
        if (str1.size() <= str2.size())
            smaller = 1;
        else
            smaller = 0;
    }
    if (smaller == 1)
    {
        std::cout << "YES" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }
    return 0;
}
