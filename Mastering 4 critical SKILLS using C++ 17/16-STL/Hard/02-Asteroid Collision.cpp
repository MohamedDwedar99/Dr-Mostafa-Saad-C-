#include <iostream>
#include <vector>
using namespace std;


vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> result;
    for (auto & asteroid : asteroids)
    {
        bool flag = false;
        while (!result.empty() && asteroid < 0 && result.back() > 0)
        {
            if (-asteroid > result.back())
            {
                result.pop_back();
                continue;
            }
            else if (-asteroid == result.back())
                result.pop_back();
            flag = true;
            break;
        }
        if (!flag)
            result.push_back(asteroid);
    }
    return result;
}
int main(void)
{
    vector<int> asteroids{-2,-1,1,2};
    asteroids = asteroidCollision(asteroids);
    for (auto &i : asteroids)
        cout << i << " ";
    return 0;
}