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
        lastAltitude = lastAltitude + gain[i];
        if (lastAltitude > largestAltitude)
            largestAltitude = lastAltitude;
    }

    return largestAltitude;
}

int main()
{
    vector<int> gain = {-4,-3,-2,-1,4,3,2};
    cout << largestAltitude(gain) << endl;
    return 0;
}