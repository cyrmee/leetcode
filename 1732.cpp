#include <iostream>
#include <vector>

using namespace std;

int largestAltitude(vector<int> &gain)
{
    int largestAltitude = 0,
        points = gain.size(),
        lastAltitude = 0;

    for (int i = 0; i < points; i++)
    {
        lastAltitude += gain[i];
        if (lastAltitude > largestAltitude)
            largestAltitude = lastAltitude;
    }

    return largestAltitude;
}