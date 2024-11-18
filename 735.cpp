#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> collided;
    vector<int> result;

    for (auto &&asteroid : asteroids)
    {
        if (asteroid > 0 && collided.top() > 0)
        {
            collided.push(asteroid);
        }
        else
        {
            if (asteroid > 0 && collided.top() < 0)
            {
                if (collided.top() * -1 < asteroid)
                    collided.pop();
            }
        }
    }

    return result;
}

int main()
{
    vector<int> asteroids = {};

    auto result = asteroidCollision(asteroids);

    for (auto &&i : result)
    {
        cout << i << "";
    }

    return 0;
}